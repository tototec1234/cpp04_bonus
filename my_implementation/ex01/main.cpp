#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "=== Testing Animal Array Creation ===" << std::endl;
    
    const int ARRAY_SIZE = 6;
    Animal* animals[ARRAY_SIZE];
    
    // Fill half with dogs, half with cats
    for (int i = 0; i < ARRAY_SIZE / 2; i++) {
        animals[i] = new Dog();
    }
    
    for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; i++) {
        animals[i] = new Cat();
    }
    
    std::cout << "\n=== Testing Animal Sounds ===" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << "Animal[" << i << "] (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }
    
    std::cout << "\n=== Testing Deep Copy ===" << std::endl;
    
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Chase squirrels");
    originalDog.getBrain()->setIdea(1, "Protect house");
    
    std::cout << "\nOriginal dog ideas:" << std::endl;
    originalDog.getBrain()->printIdeas();
    
    Dog copiedDog = originalDog;  // Copy constructor
    
    std::cout << "\nCopied dog ideas (should be same):" << std::endl;
    copiedDog.getBrain()->printIdeas();
    
    // Modify original to prove deep copy
    originalDog.getBrain()->setIdea(0, "Sleep all day");
    
    std::cout << "\nAfter modifying original:" << std::endl;
    std::cout << "Original dog ideas:" << std::endl;
    originalDog.getBrain()->printIdeas();
    
    std::cout << "Copied dog ideas (should be unchanged):" << std::endl;
    copiedDog.getBrain()->printIdeas();
    
    std::cout << "\n=== Destroying Animal Array ===" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        delete animals[i];
    }
    
    return 0;
}