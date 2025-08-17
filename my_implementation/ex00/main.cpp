#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void testCorrectPolymorphism();
void testWrongPolymorphism();
void testWrongPolymorphismDestructionOrder();

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

void testWrongPolymorphism() {
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
}

void testWrongPolymorphismDestructionOrder() {
    std::cout << "\033[31m=== Testing Wrong Polymorphism Destruction Order ===\033[0m" << std::endl;
    
    const WrongAnimal* baseAnimal = new WrongAnimal();
    std::cout << std::endl;
    const WrongAnimal* derivedCat = new WrongCat();
    std::cout << std::endl;

    std::cout << "\n----- Types -----" << std::endl;
    std::cout << baseAnimal->getType() << " " << std::endl;
    std::cout << derivedCat->getType() << " " << std::endl;
    std::cout << std::endl;

    std::cout << "\n----- Wrong sounds (should both be WrongAnimal sound) -----" << std::endl;
    baseAnimal->makeSound();
    derivedCat->makeSound();
    
    std::cout << "\n----- Destroying wrong animals (derived first, then base) -----" << std::endl;
    delete derivedCat;
    std::cout << std::endl;
    delete baseAnimal;
    std::cout << std::endl;
}

int main() {
    while (true) {
        std::cout << "\033[33m=== Animal Test Menu ===\033[0m" << std::endl;
        std::cout << "1: Test Correct Polymorphism" << std::endl;
        std::cout << "2: Test Wrong Polymorphism" << std::endl;
        std::cout << "3: Test Wrong Polymorphism Destruction Order" << std::endl;
        std::cout << "0: Exit" << std::endl;
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                testCorrectPolymorphism();
                break;
            case 2:
                testWrongPolymorphism();
                break;
            case 3:
                testWrongPolymorphismDestructionOrder();
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

