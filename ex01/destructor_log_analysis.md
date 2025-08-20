# Destructorログ分析ガイド

## 1. WrongAnimal/WrongCat (❌ virtual destructorなし)

### 実行コード:
```cpp
WrongAnimal* wrongAnimal = new WrongCat();
delete wrongAnimal;
```

### 期待されるログ vs 実際のログ:

| 期待されるログ (完全な削除) | 実際のログ (メモリリーク) |
|---|---|
| `WrongCat destructor called` | ❌ **呼ばれない** |
| `WrongBrain destructor called` | ❌ **呼ばれない** |
| `WrongAnimal destructor called` | ✅ 呼ばれる |

### 問題:
- `WrongCat::~WrongCat()`が呼ばれない
- `WrongBrain::~WrongBrain()`が呼ばれない
- `WrongBrain`オブジェクトがメモリに残る

---

## 2. Animal/Cat (✅ virtual destructorあり)

### 実行コード:
```cpp
Animal* animal = new Cat();
delete animal;
```

### 実際のログ (正常な削除):

| ログの順序 | 説明 |
|---|---|
| `Cat destructor called` | ✅ 派生クラスのデストラクタが先に呼ばれる |
| `Brain destructor called` | ✅ Catが所有するBrainが削除される |
| `Animal destructor called` | ✅ 最後にベースクラスのデストラクタが呼ばれる |

### 正常な動作:
- すべてのデストラクタが適切な順序で呼ばれる
- メモリリークなし

---

## 🔍 ログ確認のポイント

### 1. デストラクタの呼び出し順序
- **正常**: `派生クラス → 所有オブジェクト → ベースクラス`
- **異常**: `ベースクラスのみ`

### 2. 色分けでの視覚的確認
- **緑色**: 正常に呼ばれたデストラクタ
- **赤色**: 呼ばれるべきだが呼ばれなかったデストラクタ

### 3. this ポインタの確認
- 同じオブジェクトのデストラクタが連続して呼ばれることを確認
- 異なるthisポインタの場合は別のオブジェクト
