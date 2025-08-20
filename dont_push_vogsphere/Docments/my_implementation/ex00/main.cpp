#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void testCorrectPolymorphism();
void testPolymorphismProblemsExposed();
void testVirtualDestructorImportance();


int main() {
    while (true) {
        std::cout << "\033[33m=== Animal Test Menu ===\033[0m" << std::endl;
        std::cout << "1: Test Correct Polymorphism" << std::endl;
        std::cout << "2: Test Wrong Polymorphism" << std::endl;
        std::cout << "3: Demonstrate Virtual Destructor Importance" << std::endl;
        std::cout << "0: Exit" << std::endl;
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                testCorrectPolymorphism();
                break;
            case 2:
                testPolymorphismProblemsExposed();
                break;
            case 3:
                testVirtualDestructorImportance();
                break;
            case 0:
                std::cout << "Exiting program" << std::endl;
                return 0;
            default:
                std::cout << "Invalid option" << std::endl;
        }
    }
    return 0;
}


void testCorrectPolymorphism() {
    std::cout << "\033[32m=== Testing Correct Polymorphism ===\033[0m" << std::endl;

    const Animal* meta = new Animal();
    std::cout << std::endl;
    const Animal* dog = new Dog();
    std::cout << std::endl;
    const Animal* cat = new Cat();
    std::cout << std::endl;

    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;

    std::cout << "\n----- Sounds (should be specific to each animal) -----" << std::endl;
    cat->makeSound();
    dog->makeSound();
    meta->makeSound();

    std::cout << "\n----- Destroying animals -----" << std::endl;
    delete meta;
    std::cout << std::endl;
    delete dog;
    std::cout << std::endl;
    delete cat;
    std::cout << std::endl;

    std::cout << "\n=== Testing Stack Objects ===\n" << std::endl;

    Animal stackAnimal;
    std::cout << std::endl;
    Dog stackDog;
    std::cout << std::endl;
    Cat stackCat;
    std::cout << std::endl;

    std::cout << "\n----- Stack object sounds -----" << std::endl;
    stackAnimal.makeSound();
    stackDog.makeSound();
    stackCat.makeSound();
}

void testPolymorphismProblemsExposed() {
    std::cout << "\033[31m=== Testing Wrong Polymorphism ===\033[0m" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    std::cout << std::endl;
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << std::endl;


    std::cout << "\n----- Types -----" << std::endl;
    std::cout << wrongMeta->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;
    std::cout << std::endl;

    std::cout << "\n----- Wrong sounds (should both be WrongAnimal sound) -----" << std::endl;
    wrongMeta->makeSound();
    wrongCat->makeSound();

    std::cout << "\n----- Destroying wrong animals -----" << std::endl;
    delete wrongMeta;
    std::cout << std::endl;
    delete wrongCat;
    std::cout << std::endl;

    std::cout << "\n=== Testing Stack Objects ===\n" << std::endl;

    WrongAnimal stackWrongAnimal;
    std::cout << std::endl;
    WrongCat stackWrongCat;
    std::cout << std::endl;

    std::cout << "\n----- Stack object sounds -----" << std::endl;
    stackWrongAnimal.makeSound();
    stackWrongCat.makeSound();
}

void testVirtualDestructorImportance() {
    std::cout << "\033[31m=== Demonstrating Virtual Destructor Importance ===\033[0m" << std::endl;
    std::cout << "\033[33m注意: この例では非virtualデストラクタによる問題を明確に示します\033[0m" << std::endl;
    std::cout << std::endl;

    std::cout << "\n----- 正しい多態性での破棄 (virtualデストラクタあり) -----" << std::endl;
    {
        const Animal* correctAnimal = new Cat();
        std::cout << "Type: " << correctAnimal->getType() << std::endl;
        correctAnimal->makeSound();
        std::cout << "\n破棄時: virtualデストラクタにより適切な順序で呼ばれます" << std::endl;
        delete correctAnimal;  // Cat → Animal の順で適切に破棄される
        std::cout << std::endl;
        std::cout << std::endl;

    }

    std::cout << "\n----- 間違った多態性での破棄 (非virtualデストラクタ) -----" << std::endl;
    {
        const WrongAnimal* wrongAnimal = new WrongCat();
        std::cout << "Type: " << wrongAnimal->getType() << std::endl;
        wrongAnimal->makeSound();
        std::cout << "\n破棄時: 非virtualデストラクタのため問題が発生します" << std::endl;
        delete wrongAnimal;  // WrongCatのデストラクタが呼ばれない！
        std::cout << std::endl;
    }

    std::cout << "\033[31m=== 問題の説明 ===\033[0m" << std::endl;
    std::cout << "• virtualデストラクタがない場合、基底クラスポインタ経由での削除時に" << std::endl;
    std::cout << "  派生クラスのデストラクタが呼ばれません" << std::endl;
    std::cout << "• これによりメモリリークやリソースリークが発生する可能性があります" << std::endl;
    std::cout << "• virtualキーワードは「実質的な」機能を提供し、適切な多態性を実現します" << std::endl;
    std::cout << std::endl;
}
