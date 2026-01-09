# ex03 クラス分類

## 課題の趣旨

**Exercise 03: Interface & recap（インターフェースと復習）**

C++98にはインターフェースが存在しません（C++20でも存在しません）。しかし、**純粋抽象クラスは一般的にインターフェースと呼ばれます**。この演習では、このモジュールを理解していることを確認するために、インターフェースを実装します。

---

## クラス分類

### 1. インターフェース（純粋抽象クラス）

**特徴：**
- すべてのメンバー関数が純粋仮想関数（`= 0`）
- 直接インスタンス化できない
- 実装を持たない（インターフェースの定義のみ）
- 派生クラスで必ず実装する必要がある

**クラス一覧：**

#### `ICharacter`
- **役割**: Characterクラスのインターフェース
- **純粋仮想関数**:
  - `virtual std::string const & getName() const = 0`
  - `virtual void equip(AMateria* m) = 0`
  - `virtual void unequip(int idx) = 0`
  - `virtual void use(int idx, ICharacter& target) = 0`
- **実装クラス**: `Character`

#### `IMateriaSource`
- **役割**: MateriaSourceクラスのインターフェース
- **純粋仮想関数**:
  - `virtual void learnMateria(AMateria*) = 0`
  - `virtual AMateria* createMateria(std::string const & type) = 0`
- **実装クラス**: `MateriaSource`

---

### 2. 抽象基底クラス

**特徴：**
- 少なくとも1つの純粋仮想関数（`= 0`）を持つ
- 一部の関数には実装がある
- 直接インスタンス化できない
- 派生クラスで純粋仮想関数を実装する必要がある

**クラス一覧：**

#### `AMateria`
- **役割**: Materiaクラス階層の基底クラス
- **純粋仮想関数**:
  - `virtual AMateria* clone() const = 0` - 派生クラスで必ず実装が必要
- **実装済み関数**:
  - `virtual void use(ICharacter& target)` - デフォルト実装あり（派生クラスでオーバーライド可能）
  - `std::string const & getType() const` - 具象実装
- **派生クラス**: `Ice`, `Cure`
- **特徴**: 
  - コピーコンストラクタとコピー代入演算子は禁止（タイプのコピーは意味がないため）

---

### 3. 具象クラス（Concrete Classes）

**特徴：**
- すべての仮想関数が実装されている
- 直接インスタンス化可能
- 純粋仮想関数を持たない

**クラス一覧：**

#### `Ice`
- **基底クラス**: `AMateria`
- **タイプ**: `"ice"`
- **実装**:
  - `AMateria* clone() const` - 新しいIceインスタンスを返す
  - `void use(ICharacter& target)` - `"* shoots an ice bolt at <name> *"`を表示

#### `Cure`
- **基底クラス**: `AMateria`
- **タイプ**: `"cure"`
- **実装**:
  - `AMateria* clone() const` - 新しいCureインスタンスを返す
  - `void use(ICharacter& target)` - `"* heals <name>'s wounds *"`を表示

#### `Character`
- **実装インターフェース**: `ICharacter`
- **機能**:
  - 4スロットのMateriaインベントリを持つ
  - Materiaの装備・装備解除・使用が可能
  - ディープコピーを実装（コピー時にMateriaも複製）
- **実装関数**:
  - `std::string const & getName() const`
  - `void equip(AMateria* m)`
  - `void unequip(int idx)`
  - `void use(int idx, ICharacter& target)`

#### `MateriaSource`
- **実装インターフェース**: `IMateriaSource`
- **機能**:
  - 最大4つのMateriaテンプレートを学習可能
  - 学習したMateriaをタイプ名から生成可能
- **実装関数**:
  - `void learnMateria(AMateria*)` - Materiaをコピーして保存
  - `AMateria* createMateria(std::string const & type)` - 学習済みMateriaをクローンして返す

---

## クラス階層図

```
インターフェース（純粋抽象クラス）
├── ICharacter
│   └── Character (具象実装)
│
└── IMateriaSource
    └── MateriaSource (具象実装)

抽象基底クラス
└── AMateria
    ├── Ice (具象実装)
    └── Cure (具象実装)
```

---

## 学習ポイント

### 1. インターフェースの概念
- C++98ではインターフェースは存在しないが、**純粋抽象クラス**で実現
- すべての関数が純粋仮想関数（`= 0`）のクラスがインターフェース
- 実装を持たず、契約（インターフェース）のみを定義

### 2. 抽象基底クラスとの違い
- **インターフェース**: すべての関数が純粋仮想関数
- **抽象基底クラス**: 一部の関数が純粋仮想関数、一部は実装あり

### 3. 多態性（Polymorphism）の活用
- `ICharacter*`として`Character`を扱う
- `IMateriaSource*`として`MateriaSource`を扱う
- `AMateria*`として`Ice`や`Cure`を扱う
- 実行時に適切な関数が呼ばれる（動的バインディング）

### 4. デザインパターン
- **Factory Pattern**: `MateriaSource`がMateriaを生成
- **Strategy Pattern**: 異なるMateriaタイプ（Ice/Cure）で異なる動作
- **Interface Segregation**: インターフェースを分離（ICharacter, IMateriaSource）

---

## まとめ

| 分類 | クラス | 特徴 |
|------|--------|------|
| **インターフェース** | `ICharacter`, `IMateriaSource` | すべての関数が純粋仮想関数 |
| **抽象基底クラス** | `AMateria` | 一部の関数が純粋仮想関数 |
| **具象クラス** | `Ice`, `Cure`, `Character`, `MateriaSource` | すべての関数が実装済み |

この分類により、C++98でインターフェースを実現する方法と、抽象クラスとの違いを理解できます。
