// CPP03-04 学習比較例

// ============ 1. virtualデストラクタの違い ============

// ❌ 危険な例（非virtual）
class WrongAnimal {
public:
    ~WrongAnimal() { /* 非virtual */ }  
};

// ✅ 安全な例（virtual）
class Animal {
public:
    virtual ~Animal() { /* virtual */ }
};

void test_destructor() {
    // 危険：Dogデストラクタが呼ばれない
    WrongAnimal* wrong = new WrongDog();
    delete wrong;  // ❌ メモリリーク

    // 安全：適切な順序でデストラクタ呼び出し
    Animal* safe = new Dog();
    delete safe;   // ✅ ~Dog() → ~Animal()
}

// ============ 2. virtual関数の動的ディスパッチ ============

void test_polymorphism() {
    Animal* animals[] = {
        new Dog(),
        new Cat(),
        new Animal()
    };

    for (int i = 0; i < 3; i++) {
        // 実行時に正しいmakeSound()が呼ばれる
        animals[i]->makeSound();  // Dog: "Woof!", Cat: "Meow!", Animal: "..."
        delete animals[i];
    }
}

// ============ 3. コピーコンストラクタの進化 ============

// Ex00: シンプル（コンパイラ生成で十分）
class Dog_Ex00 : public Animal {
    // 固有メンバなし → デフォルトコピーコンストラクタOK
};

// Ex01: 複雑（深いコピー必要）
class Dog_Ex01 : public Animal {
private:
    Brain* brain;  // 動的メモリ → 手動深いコピー必要

public:
    Dog_Ex01(const Dog_Ex01& other) : Animal(other) {
        brain = new Brain(*other.brain);  // 深いコピー
    }
};
