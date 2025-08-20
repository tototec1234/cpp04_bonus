# newが失敗した場合の例外処理の流れ

## 🔄 順序立てた説明

### 📍 **Step 1: 代入演算子開始**
```
cat2 = cat1;  // ← この操作を開始
```
- `Cat::operator=`が呼び出される
- `if (this != &other)`をチェック（通常true）
- `Animal::operator=(other)`を実行（成功）

### 📍 **Step 2: 危険ポイント到達**
```cpp
Brain* newBrain = new Brain(*other.brain);  // ← ここで例外発生
```

**正常時の流れ:**
1. `new Brain(*other.brain)`でメモリ割り当て成功
2. `newBrain`に新しいBrainのアドレスが格納される
3. 次の行に進む

**例外発生時の流れ:**
1. `new Brain(*other.brain)`でメモリ不足
2. システムが`std::bad_alloc`例外を**自動的に投げる**
3. **この時点で関数の実行が中断される**
4. `newBrain`変数は未初期化のまま
5. 次の行（`delete this->brain`）は**実行されない**

### 📍 **Step 3: 例外の伝播**
- 例外は呼び出し元に**自動的に**遡る
- `catch`文を探し続ける
- 見つからなければプログラム終了

### 📍 **Step 4a: 例外がキャッチされた場合**
```cpp
try {
    cat2 = cat1;  // ← ここで例外発生
} catch (const std::bad_alloc &e) {
    // ここで例外を処理
    std::cout << "メモリ不足: " << e.what() << std::endl;
    // cat2の状態は変更されていない（安全）
}
```

### 📍 **Step 4b: 例外がキャッチされない場合**
- プログラムが異常終了
- `terminate()`が呼ばれる

## 🛡️ 改修の重要性

### ❌ **改修前（危険な実装）**
```cpp
Cat &operator=(const Cat &other) {
    if (this != &other) {
        delete this->brain;              // ← 先に削除
        this->brain = new Brain(*other.brain);  // ← 失敗でダングリングポインタ
    }
    return *this;
}
```

**問題:**
- `delete this->brain`を先に実行
- `new Brain`が失敗すると`this->brain`が無効ポインタになる
- オブジェクトが壊れた状態になる

### ✅ **改修後（安全な実装）**
```cpp
Cat &operator=(const Cat &other) {
    if (this != &other) {
        Brain* newBrain = new Brain(*other.brain);  // ← 先に新しいものを作成
        delete this->brain;              // ← 成功後に古いものを削除
        this->brain = newBrain;
    }
    return *this;
}
```

**利点:**
- `new Brain`が失敗しても`this->brain`は元のまま
- オブジェクトの状態が保持される
- 例外安全性を確保

## 🧪 実際のテスト方法

### コンパイル・実行コマンド
```bash
# 例外処理基本デモ
cd /Users/toruinoue/CPP/0817cpp04/ex01 && c++ -Wall -Wextra -Werror -std=c++98 exception_demo.cpp Cat.cpp Dog.cpp Animal.cpp Brain.cpp WrongAnimal.cpp WrongCat.cpp WrongDog.cpp -o exception_demo && ./exception_demo

# ステップバイステップ例外処理デモ
cd /Users/toruinoue/CPP/0817cpp04/ex01 && c++ -Wall -Wextra -Werror -std=c++98 exception_flow_demo.cpp -o exception_flow_demo && ./exception_flow_demo

# 統合テスト（Brain範囲外アクセス例外）
cd /Users/toruinoue/CPP/0817cpp04/ex01 && printf "5\n0\n" | ./brain_test
```

## 🎯 学習ポイント

1. **例外は自動的に投げられる** - newが失敗した時点で`std::bad_alloc`が発生
2. **例外発生時点で処理中断** - 後続のコードは実行されない
3. **try-catchで安全に処理** - プログラムクラッシュを防ぐ
4. **例外安全性** - オブジェクトの状態を保持する設計が重要
5. **RAII原則** - リソース管理を確実にする
