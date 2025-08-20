// 多態性のメリットを示すシンプルな例

#include <iostream>

class Animal {
public:
    virtual ~Animal() {}
    virtual void makeSound() const = 0;
    virtual std::string getType() const = 0;
};

class Dog : public Animal {
public:
    void makeSound() const { std::cout << "Woof! Woof!" << std::endl; }
    std::string getType() const { return "Dog"; }
};

class Cat : public Animal {
public:
    void makeSound() const { std::cout << "Meow! Meow!" << std::endl; }
    std::string getType() const { return "Cat"; }
};

class Bird : public Animal {
public:
    void makeSound() const { std::cout << "Tweet! Tweet!" << std::endl; }
    std::string getType() const { return "Bird"; }
};

// ===== メリット1: 統一的な扱い =====
void feedAllAnimals(Animal** animals, int size) {
    std::cout << "\n=== 動物たちに餌やり ===" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << animals[i]->getType() << "に餌やり: ";
        animals[i]->makeSound();  // 各動物の固有の鳴き声
    }
}

// ===== メリット2: 動的な動物追加 =====
Animal* createAnimal(const std::string& type) {
    if (type == "dog") return new Dog();
    if (type == "cat") return new Cat();
    if (type == "bird") return new Bird();
    return NULL;  // C++98では nullptr の代わりに NULL
}

// ===== メリット3: コードの再利用性 =====
void animalInteraction(Animal* animal) {
    std::cout << "動物との触れ合い:" << std::endl;
    std::cout << "- 種類: " << animal->getType() << std::endl;
    std::cout << "- 鳴き声: ";
    animal->makeSound();
    std::cout << std::endl;
}

int main() {
    // ===== 従来の方法（多態性なし）の問題点 =====
    std::cout << "【従来の方法の問題点】" << std::endl;
    std::cout << "個別に処理する必要があり、コードが重複する:" << std::endl;

    Dog dog1;
    Cat cat1;
    Bird bird1;

    // 個別処理が必要（非効率）
    std::cout << "犬: "; dog1.makeSound();
    std::cout << "猫: "; cat1.makeSound();
    std::cout << "鳥: "; bird1.makeSound();

    std::cout << "\n" << std::string(50, '=') << std::endl;

    // ===== 多態性を使った統一的な扱い =====
    std::cout << "\n【多態性の活用】" << std::endl;

    const int ANIMAL_COUNT = 4;
    Animal* zoo[ANIMAL_COUNT];
    zoo[0] = new Dog();
    zoo[1] = new Cat();
    zoo[2] = new Bird();
    zoo[3] = new Dog();

    // メリット1: 同じコードで全動物を処理
    feedAllAnimals(zoo, ANIMAL_COUNT);

    // メリット2: 動的な動物作成
    std::cout << "\n=== 動的な動物作成 ===" << std::endl;
    std::string animalTypes[3];
    animalTypes[0] = "dog";
    animalTypes[1] = "cat";
    animalTypes[2] = "bird";

    for (int i = 0; i < 3; i++) {
        Animal* dynamicAnimal = createAnimal(animalTypes[i]);
        if (dynamicAnimal) {
            animalInteraction(dynamicAnimal);
            delete dynamicAnimal;
        }
    }

    // メリット3: 新しい動物追加が簡単
    std::cout << "\n=== 拡張性の実証 ===" << std::endl;
    std::cout << "新しい動物（鳥）を追加しても、既存コードは変更不要!" << std::endl;

    std::cout << "\n=== 多態性の核心 ===" << std::endl;
    std::cout << "Animal*型のポインタが様々な実体(Dog, Cat, Bird)を指している:" << std::endl;
    for (int i = 0; i < ANIMAL_COUNT; i++) {
        std::cout << "zoo[" << i << "] (Animal*) -> 実際は" << zoo[i]->getType() << "オブジェクト" << std::endl;
    }

    // クリーンアップ
    for (int i = 0; i < ANIMAL_COUNT; i++) {
        delete zoo[i];
    }

    return 0;
}
