# C++ Module 04: 継承とis-a関係のまとめ

## 課題の趣旨

**C++ - Module 04: Subtype Polymorphism, Abstract Classes, and Interfaces**

このモジュールでは、以下の概念を学習します：
- **多態性（Polymorphism）**: 基底クラスのポインタ/参照で派生クラスを扱う
- **抽象クラス（Abstract Classes）**: 直接インスタンス化できない基底クラス
- **インターフェース（Interfaces）**: 純粋抽象クラスによる契約の定義

---

## 1. is-a関係の確認（ex00-ex03）

### is-a関係とは

**is-a関係**は、オブジェクト指向設計における基本的な関係の一つです。
- 「Dog **is an** Animal」（犬は動物である）
- 「Cat **is an** Animal」（猫は動物である）
- 「Character **is an** ICharacter」（CharacterはICharacterである）

この関係により、**基底クラスのポインタ/参照で派生クラスを扱う**ことができます。

### ex00: Polymorphism

**is-a関係の使用例：**

```cpp
// Animal*でDog/Catを扱う（is-a関係）
const Animal* j = new Dog();  // Dog is an Animal
const Animal* i = new Cat();  // Cat is an Animal

j->makeSound();  // Dog::makeSound()が呼ばれる（多態性・動的バインディング）
i->makeSound();  // Cat::makeSound()が呼ばれる（多態性・動的バインディング）

delete j;  // 仮想デストラクタにより、Dog::~Dog()が呼ばれる
delete i;  // 仮想デストラクタにより、Cat::~Cat()が呼ばれる
```

**継承関係：**
- `class Dog : public Animal` → **is-a関係あり** ✅
- `class Cat : public Animal` → **is-a関係あり** ✅

**仮想関数による動的バインディング：**

ex00では、`Animal`クラスで`makeSound()`が**仮想関数**として定義されています：

```cpp
// Animal.hpp
class Animal {
public:
    virtual void makeSound() const;  // ← virtualキーワード
    virtual ~Animal();  // ← 仮想デストラクタ
};
```

```cpp
// Dog.hpp
class Dog : public Animal {
public:
    void makeSound() const;  // ← Animal::makeSound()をオーバーライド
};
```

**確認ポイント：**
- `Animal*`として`Dog`や`Cat`を扱える（is-a関係）
- **仮想関数により、実行時に適切な関数が呼ばれる（動的バインディング）** ✅
  - `Animal* j = new Dog(); j->makeSound();` → `Dog::makeSound()`が呼ばれる
  - `Animal* i = new Cat(); i->makeSound();` → `Cat::makeSound()`が呼ばれる
- 仮想デストラクタにより、適切なデストラクタが呼ばれる

**ex00とex02の違い：**
- **ex00**: `virtual void makeSound() const;` - 実装がある（純粋仮想関数ではない）
- **ex02**: `virtual void makeSound() const = 0;` - 純粋仮想関数（抽象基底クラス）
- **どちらも仮想関数であり、動的バインディングは同じように機能する**

---

### ex01: I don't want to set the world on fire

**ex00との違い：ex01で追加された重要な概念**

ex00では基本的な多態性を学習しましたが、ex01では**メモリ管理とディープコピー**に焦点を当てます。

**主な追加要素：**

1. **Brainクラスの追加**
   - `Dog`と`Cat`が`Brain*`メンバーを持つ
   - `Brain`は100個の`std::string`配列（ideas）を持つ

2. **Orthodox Canonical Formの実装**
   - コピーコンストラクタ
   - 代入演算子
   - デストラクタ

3. **ディープコピーの重要性**
   - 浅いコピー（shallow copy）の問題点を理解
   - ディープコピー（deep copy）の実装

**is-a関係の使用例：**

```cpp
// Animal*でDog/Catを扱う（is-a関係）
Animal* animals[ARRAY_SIZE];
for (int i = 0; i < ARRAY_SIZE / 2; i++) {
    animals[i] = new Dog();  // Dog is an Animal
}
for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; i++) {
    animals[i] = new Cat();  // Cat is an Animal
}

// Animal*として削除（多態性）
for (int i = 0; i < ARRAY_SIZE; i++) {
    delete animals[i];  // 適切なデストラクタが呼ばれる（Brainも削除される）
}
```

**継承関係：**
- `class Dog : public Animal` → **is-a関係あり** ✅
- `class Cat : public Animal` → **is-a関係あり** ✅

**ex01で着目するポイント：**

1. **ディープコピーの実装**
   ```cpp
   // Dog.hpp
   class Dog : public Animal {
   private:
       Brain* brain;  // ← ポインタメンバー
   public:
       Dog(const Dog &other);  // コピーコンストラクタ
       Dog &operator=(const Dog &other);  // 代入演算子
       ~Dog();  // デストラクタ（Brainを削除）
   };
   ```
   - コピー時に`Brain`も新しいインスタンスとしてコピー（ディープコピー）
   - 浅いコピーだと、複数の`Dog`が同じ`Brain`を共有してしまう

2. **メモリ管理の重要性**
   - `new Brain()`で作成した`Brain`は`delete`で削除する必要がある
   - 仮想デストラクタにより、`Animal*`経由で削除しても適切に`Brain`が削除される

3. **Orthodox Canonical Form**
   - Module 02-09の要件
   - コピーコンストラクタ、代入演算子、デストラクタを実装

**ex00とex01の比較：**

| 項目 | ex00 | ex01 |
|------|------|------|
| **多態性** | ✅ 基本的多態性 | ✅ 多態性（継承） |
| **仮想関数** | ✅ `virtual makeSound()` | ✅ `virtual makeSound()` |
| **仮想デストラクタ** | ✅ 実装 | ✅ 実装 |
| **Brainクラス** | ❌ なし | ✅ **追加** |
| **コピーコンストラクタ** | ❌ なし | ✅ **実装必須** |
| **代入演算子** | ❌ なし | ✅ **実装必須** |
| **ディープコピー** | - | ✅ **重要** |
| **メモリ管理** | 基本的 | ✅ **重要（Brainの管理）** |

**ex01の学習目標：**

ex01は「I don't want to set the world on fire（世界を燃やしたくない）」というタイトルからも分かるように、**メモリリークを防ぐ**ことが主な目的です。

- ポインタメンバー（`Brain*`）を持つクラスの適切な管理
- ディープコピーによる独立性の確保
- 仮想デストラクタによる適切なリソース解放
- Orthodox Canonical Formの実装

**確認ポイント：**
- 配列で`Animal*`として統一管理（ex00と同じ）
- 仮想デストラクタにより、適切なデストラクタが呼ばれる（ex00と同じ）
- **ディープコピーの実装（Brainのコピー）** ← **ex01の新規要素**
- **メモリリークの防止** ← **ex01の主な目的**

---

### ex02: Abstract class

**is-a関係の使用例：**

```cpp
// Animal*でDog/Catを扱う（is-a関係）
Animal* dogPtr = new Dog();  // Dog is an Animal
Animal* catPtr = new Cat();  // Cat is an Animal

dogPtr->makeSound();  // Dog::makeSound()が呼ばれる
catPtr->makeSound();  // Cat::makeSound()が呼ばれる

delete dogPtr;
delete catPtr;

// ❌ 以下はコンパイルエラー（抽象クラスは直接インスタンス化不可）
// Animal animal;  // Error: cannot instantiate abstract class
// Animal* ptr = new Animal();  // Error: cannot instantiate abstract class
```

**継承関係：**
- `class Dog : public Animal` → **is-a関係あり** ✅
- `class Cat : public Animal` → **is-a関係あり** ✅

**確認ポイント：**
- `Animal`は抽象基底クラス（`makeSound() = 0`）
- 直接インスタンス化できない
- しかし、`Animal*`として`Dog`や`Cat`を扱える（is-a関係は維持）

---

### ex03: Interface & recap

**is-a関係の使用例：**

```cpp
// 1. ICharacter*でCharacterを扱う（is-a関係）
ICharacter* me = new Character("me");  // Character is an ICharacter
ICharacter* bob = new Character("bob");  // Character is an ICharacter

// 2. IMateriaSource*でMateriaSourceを扱う（is-a関係）
IMateriaSource* src = new MateriaSource();  // MateriaSource is an IMateriaSource

// 3. AMateria*でIce/Cureを扱う（is-a関係）
AMateria* tmp = src->createMateria("ice");  // Ice is an AMateria
me->equip(tmp);
tmp = src->createMateria("cure");  // Cure is an AMateria
me->equip(tmp);

me->use(0, *bob);  // 多態性により適切なuse()が呼ばれる
me->use(1, *bob);

delete bob;
delete me;
delete src;
```

**継承関係：**
- `class Character : public ICharacter` → **is-a関係あり** ✅
- `class MateriaSource : public IMateriaSource` → **is-a関係あり** ✅
- `class Ice : public AMateria` → **is-a関係あり** ✅
- `class Cure : public AMateria` → **is-a関係あり** ✅

**確認ポイント：**
- インターフェース（`ICharacter`, `IMateriaSource`）として扱える
- 抽象基底クラス（`AMateria`）として扱える
- すべて`public`継承により、is-a関係が実現されている

---

## 2. 継承関係の分類（ex00-ex03）

### すべて`public`継承を使用

このモジュール（ex00-ex03）では、**すべて`public`継承**のみが使用されています。

| Exercise | 継承関係 | 継承の種類 |
|----------|---------|-----------|
| **ex00** | `Dog : public Animal` | `public`継承 |
| | `Cat : public Animal` | `public`継承 |
| **ex01** | `Dog : public Animal` | `public`継承 |
| | `Cat : public Animal` | `public`継承 |
| **ex02** | `Dog : public Animal` | `public`継承 |
| | `Cat : public Animal` | `public`継承 |
| **ex03** | `Character : public ICharacter` | `public`継承 |
| | `MateriaSource : public IMateriaSource` | `public`継承 |
| | `Ice : public AMateria` | `public`継承 |
| | `Cure : public AMateria` | `public`継承 |

### なぜ`public`継承なのか

1. **is-a関係を表現するため**
   - 「Dog is an Animal」という関係を表現
   - 基底クラスのポインタ/参照で派生クラスを扱える

2. **多態性を実現するため**
   - 仮想関数による動的バインディング
   - 実行時に適切な関数が呼ばれる

3. **インターフェースの実装**
   - `ICharacter`や`IMateriaSource`はインターフェース
   - `public`継承により、インターフェースとして扱える

---

## 3. private継承・protected継承との比較

### 継承の種類

C++には3種類の継承があります：

| 継承の種類 | 構文 | 意味 | 使用例 |
|-----------|------|------|--------|
| **public継承** | `class Derived : public Base` | **is-a関係** | このモジュールで使用 |
| **private継承** | `class Derived : private Base` | **実装の継承**のみ | このモジュールでは未使用 |
| **protected継承** | `class Derived : protected Base` | 中間的な継承 | このモジュールでは未使用 |

### public継承（このモジュールで使用）

**特徴：**
- 基底クラスの`public`メンバー → 派生クラスでも`public`
- 基底クラスの`protected`メンバー → 派生クラスでも`protected`
- 基底クラスの`private`メンバー → 派生クラスからはアクセス不可

**使用例：**
```cpp
class Dog : public Animal {
    // Dog is an Animal
    // Animal*として扱える
};

Animal* dog = new Dog();  // ✅ OK
dog->makeSound();  // ✅ OK（public継承により可能）
```

**このモジュールでの使用：**
- ex00-ex03のすべての継承が`public`継承
- is-a関係を表現
- 多態性を実現

---

### private継承（このモジュールでは未使用）

**特徴：**
- 基底クラスの`public`メンバー → 派生クラスでは`private`
- 基底クラスの`protected`メンバー → 派生クラスでは`private`
- **is-a関係を表現しない**
- **実装の継承のみ**（「is-implemented-in-terms-of」関係）

**使用例：**
```cpp
class Stack : private std::vector<int> {
    // Stackはvectorを使って実装されているが、vectorではない
    // vectorの機能を再利用しているだけ
};

std::vector<int>* vec = new Stack();  // ❌ Error: private継承では不可能
```

**このモジュールでは未使用：**
- is-a関係を表現する必要があるため
- 多態性を実現する必要があるため

**使用場面：**
- 基底クラスの実装を再利用したいが、is-a関係は不要な場合
- 基底クラスのインターフェースを外部に公開したくない場合

---

### protected継承（このモジュールでは未使用）

**特徴：**
- 基底クラスの`public`メンバー → 派生クラスでは`protected`
- 基底クラスの`protected`メンバー → 派生クラスでも`protected`
- **中間的な継承**
- さらに派生したクラスでのみ使用可能

**使用例：**
```cpp
class Base {
public:
    void func() {}
};

class Derived : protected Base {
    // Base::func()はprotectedになる
};

class FurtherDerived : public Derived {
    void test() {
        func();  // ✅ OK（Derivedから見てprotectedなので、さらに派生したクラスからアクセス可能）
    }
};

Base* base = new Derived();  // ❌ Error: protected継承では不可能
```

**このモジュールでは未使用：**
- 通常、`protected`継承はほとんど使われない
- `public`継承で十分

**使用場面：**
- 基底クラスの機能を、さらに派生したクラスでのみ使用可能にしたい場合
- 非常に特殊な設計が必要な場合

---

## 4. まとめ表

### ex00とex01の違い（重要なポイント）

| 項目 | ex00: Polymorphism | ex01: I don't want to set the world on fire |
|------|-------------------|--------------------------------------------|
| **学習目標** | 基本的な多態性 | **メモリ管理とディープコピー** |
| **多態性** | ✅ 基本的多態性の学習 | ✅ 多態性（継承） |
| **仮想関数** | ✅ `virtual makeSound()` | ✅ `virtual makeSound()` |
| **仮想デストラクタ** | ✅ 実装 | ✅ 実装 |
| **Brainクラス** | ❌ なし | ✅ **追加（重要）** |
| **コピーコンストラクタ** | ❌ なし | ✅ **実装必須** |
| **代入演算子** | ❌ なし | ✅ **実装必須** |
| **ディープコピー** | - | ✅ **重要（Brainのコピー）** |
| **メモリ管理** | 基本的 | ✅ **重要（Brainの管理）** |
| **Orthodox Canonical Form** | ❌ 不要 | ✅ **必須** |

**ex01で追加された重要な概念：**
1. **Brainクラス**: `Dog`と`Cat`が`Brain*`メンバーを持つ
2. **ディープコピー**: コピー時に`Brain`も新しいインスタンスとしてコピー
3. **メモリリークの防止**: 適切なリソース管理（「世界を燃やさない」）

### is-a関係の確認

| Exercise | 継承関係 | is-a関係 | 使用例 | 主な学習内容 |
|----------|---------|---------|--------|------------|
| **ex00** | `Dog : public Animal` | ✅ あり | `Animal* dog = new Dog();` | 基本的な多態性 |
| | `Cat : public Animal` | ✅ あり | `Animal* cat = new Cat();` | 仮想関数、仮想デストラクタ |
| **ex01** | `Dog : public Animal` | ✅ あり | `Animal* animals[] = {new Dog(), new Cat()};` | **メモリ管理、ディープコピー** |
| | `Cat : public Animal` | ✅ あり | | **Orthodox Canonical Form** |
| **ex02** | `Dog : public Animal` | ✅ あり | `Animal* dog = new Dog();` | 抽象基底クラス |
| | `Cat : public Animal` | ✅ あり | `Animal* cat = new Cat();` | 純粋仮想関数 |
| **ex03** | `Character : public ICharacter` | ✅ あり | `ICharacter* me = new Character("me");` | インターフェース |
| | `MateriaSource : public IMateriaSource` | ✅ あり | `IMateriaSource* src = new MateriaSource();` | 純粋抽象クラス |
| | `Ice : public AMateria` | ✅ あり | `AMateria* ice = new Ice();` | 抽象基底クラス |
| | `Cure : public AMateria` | ✅ あり | `AMateria* cure = new Cure();` | |

### 継承の種類の比較

| 継承の種類 | このモジュールでの使用 | 理由 |
|-----------|---------------------|------|
| **public継承** | ✅ **すべての継承で使用** | is-a関係を表現、多態性を実現 |
| **private継承** | ❌ 未使用 | is-a関係を表現する必要があるため |
| **protected継承** | ❌ 未使用 | 通常は不要、特殊な設計が必要な場合のみ |

### 重要なポイント

1. **すべて`public`継承**
   - ex00-ex03のすべての継承が`public`継承
   - is-a関係を表現するため

2. **is-a関係がすべてのexerciseで実現されている**
   - 基底クラスのポインタ/参照で派生クラスを扱える
   - 多態性により、実行時に適切な関数が呼ばれる

3. **private/protected継承は使用されていない**
   - このモジュールの目的（多態性、抽象クラス、インターフェース）には不要
   - `public`継承で十分

4. **課題の趣旨との関係**
   - **多態性（Polymorphism）**: `public`継承により実現
   - **抽象クラス（Abstract Classes）**: `public`継承により実現（ex02）
   - **インターフェース（Interfaces）**: `public`継承により実現（ex03）

---

## 5. 学習のポイント

### public継承を使うべき場合

✅ **is-a関係がある場合**
- 「Dog is an Animal」→ `class Dog : public Animal`
- 「Character is an ICharacter」→ `class Character : public ICharacter`

✅ **多態性を実現したい場合**
- 基底クラスのポインタ/参照で派生クラスを扱う
- 仮想関数による動的バインディング

✅ **インターフェースを実装する場合**
- 純粋抽象クラス（インターフェース）を実装
- 契約（インターフェース）を満たす

### private継承を使うべき場合

✅ **実装の継承のみが必要な場合**
- is-a関係は不要
- 基底クラスの機能を再利用したいが、インターフェースは公開したくない

❌ **このモジュールでは不要**
- is-a関係を表現する必要があるため
- 多態性を実現する必要があるため

### protected継承を使うべき場合

✅ **非常に特殊な設計が必要な場合**
- 基底クラスの機能を、さらに派生したクラスでのみ使用可能にしたい
- 通常はほとんど使われない

❌ **このモジュールでは不要**
- `public`継承で十分

---

## 6. 結論

### このモジュール（ex00-ex03）での継承

1. **すべて`public`継承を使用**
   - is-a関係を表現
   - 多態性を実現
   - インターフェースを実装

2. **is-a関係がすべてのexerciseで実現されている**
   - ex00: `Animal*`で`Dog`/`Cat`を扱う
   - ex01: 同様（配列で統一管理）
   - ex02: 同様（抽象基底クラス）
   - ex03: `ICharacter*`、`IMateriaSource*`、`AMateria*`で派生クラスを扱う

3. **private/protected継承は使用されていない**
   - このモジュールの目的には不要
   - `public`継承で十分

### 課題の趣旨との関係

このモジュールの目的は：
- **多態性（Polymorphism）**の理解
- **抽象クラス（Abstract Classes）**の理解
- **インターフェース（Interfaces）**の理解

これらすべてが`public`継承により実現されています。`private`継承や`protected`継承は、このモジュールの目的には不要であり、使用されていません。
