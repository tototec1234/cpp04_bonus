// シンプルな多態性デモ（CPP04 Module準拠）

#include <iostream>

class Animal {
public:
    virtual ~Animal() {}
    virtual void makeSound() const = 0;
    virtual const char* getType() const = 0;  // std::stringの代わりにconst char*
};

class Dog : public Animal {
public:
    void makeSound() const { std::cout << "Woof! Woof!" << std::endl; }
    const char* getType() const { return "Dog"; }
};

class Cat : public Animal {
public:
    void makeSound() const { std::cout << "Meow! Meow!" << std::endl; }
    const char* getType() const { return "Cat"; }
};

// シンプルな多態性デモ関数
void demonstratePolymorphism(Animal* animal) {
    std::cout << "Animal*ポインタ -> 実際は" << animal->getType() << ": ";
    animal->makeSound();
}

int main() {
    std::cout << "=== 多態性のシンプルデモ ===" << std::endl;
    std::cout << "Animal*型ポインタが様々な実体を指す例:\n" << std::endl;

    // 同じ型（Animal*）で異なる実体を指す
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    // 統一的な処理で各々の動作
    demonstratePolymorphism(animal1);
    demonstratePolymorphism(animal2);

    std::cout << "\n--- 配列での多態性 ---" << std::endl;
    Animal* zoo[3];
    zoo[0] = new Dog();
    zoo[1] = new Cat();
    zoo[2] = new Dog();

    // 同じコードで全動物を処理
    std::cout << "実行コード:\n";
    std::cout << "for (int i = 0; i < 3; i++) {\n";
    std::cout << "    std::cout << \"zoo[\" << i << \"]: \";\n";
    std::cout << "    demonstratePolymorphism(zoo[i]);\n";
    std::cout << "}\n\n";

    for (int i = 0; i < 3; i++) {
        std::cout << "zoo[" << i << "]: ";
        demonstratePolymorphism(zoo[i]);
    }
    std::cout << "\n✅ 多態性の効果:" << std::endl;
    std::cout << "・Animal*で統一的に扱える" << std::endl;
    std::cout << "・実行時に正しいmakeSound()が呼ばれる" << std::endl;
    std::cout << "・コードの再利用性・拡張性が向上" << std::endl;

    // クリーンアップ
    delete animal1;
    delete animal2;
    for (int i = 0; i < 3; i++) {
        delete zoo[i];
    }

    return 0;
}
