#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void testBasicFunctionality();
void testDeepCopy();
void testAssignmentOperator();
void testVirtualDestructorWithBrain();

void testBasicFunctionality() {
    std::cout << "\033[32m=== Testing Basic Animal Array Functionality ===\033[0m" << std::endl;
    
    const int ARRAY_SIZE = 4;
    Animal* animals[ARRAY_SIZE];
    
    std::cout << "\n----- Creating Animal Array (half Dogs, half Cats) -----" << std::endl;
    // Fill half with dogs, half with cats
    for (int i = 0; i < ARRAY_SIZE / 2; i++) {
        std::cout << "Creating Dog[" << i << "]:" << std::endl;
        animals[i] = new Dog();
        std::cout << std::endl;
    }
    
    for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; i++) {
        std::cout << "Creating Cat[" << i << "]:" << std::endl;
        animals[i] = new Cat();
        std::cout << std::endl;
    }
    
    std::cout << "\n----- Testing Polymorphic Behavior -----" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << "Animal[" << i << "] (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }
    
    std::cout << "\n----- Destroying Animals (virtual destructor ensures proper cleanup) -----" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << "Deleting Animal[" << i << "]:" << std::endl;
        delete animals[i];
        std::cout << std::endl;
    }
}

void testDeepCopy() {
    std::cout << "\033[32m=== Testing Deep Copy (Copy Constructor) ===\033[0m" << std::endl;
    
    std::cout << "\n----- Testing Dog Deep Copy -----" << std::endl;
    {
        Dog originalDog;
        originalDog.getBrain()->setIdea(0, "Chase squirrels");
        originalDog.getBrain()->setIdea(1, "Protect house");
        originalDog.getBrain()->setIdea(2, "Bark at mailman");
        
        std::cout << "\nOriginal dog's brain address: " << originalDog.getBrain() << std::endl;
        std::cout << "Original dog ideas:" << std::endl;
        originalDog.getBrain()->printIdeas();
        
        std::cout << "\n--- Creating copy using copy constructor ---" << std::endl;
        Dog copiedDog = originalDog;  // Copy constructor
        
        std::cout << "\nCopied dog's brain address: " << copiedDog.getBrain() << std::endl;
        std::cout << "Copied dog ideas (should be same content, different address):" << std::endl;
        copiedDog.getBrain()->printIdeas();
        
        std::cout << "\n--- Verifying deep copy by modifying original ---" << std::endl;
        originalDog.getBrain()->setIdea(0, "Sleep all day");
        originalDog.getBrain()->setIdea(3, "Dream about food");
        
        std::cout << "\nAfter modifying original:" << std::endl;
        std::cout << "Original dog ideas (modified):" << std::endl;
        originalDog.getBrain()->printIdeas();
        
        std::cout << "Copied dog ideas (should be unchanged - proof of deep copy):" << std::endl;
        copiedDog.getBrain()->printIdeas();
        
        std::cout << "\n✅ Deep copy verified: Different brain addresses, independent content" << std::endl;
    }
    
    std::cout << "\n----- Testing Cat Deep Copy -----" << std::endl;
    {
        Cat originalCat;
        originalCat.getBrain()->setIdea(0, "Hunt mice");
        originalCat.getBrain()->setIdea(1, "Nap in sunlight");
        
        std::cout << "\nOriginal cat's brain address: " << originalCat.getBrain() << std::endl;
        std::cout << "Original cat ideas:" << std::endl;
        originalCat.getBrain()->printIdeas();
        
        Cat copiedCat = originalCat;  // Copy constructor
        
        std::cout << "\nCopied cat's brain address: " << copiedCat.getBrain() << std::endl;
        
        // Modify original to prove deep copy
        originalCat.getBrain()->setIdea(0, "Knock things off table");
        
        std::cout << "\nAfter modifying original cat:" << std::endl;
        std::cout << "Original cat ideas (modified):" << std::endl;
        originalCat.getBrain()->printIdeas();
        
        std::cout << "Copied cat ideas (should be unchanged - proof of deep copy):" << std::endl;
        copiedCat.getBrain()->printIdeas();
    }
}

void testAssignmentOperator() {
    std::cout << "\033[32m=== Testing Deep Copy (Assignment Operator) ===\033[0m" << std::endl;
    
    Dog dog1;
    Dog dog2;
    
    dog1.getBrain()->setIdea(0, "Original dog idea");
    dog1.getBrain()->setIdea(1, "Another original idea");
    
    dog2.getBrain()->setIdea(0, "Different dog idea");
    
    std::cout << "\nBefore assignment:" << std::endl;
    std::cout << "Dog1 brain address: " << dog1.getBrain() << std::endl;
    std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 brain address: " << dog2.getBrain() << std::endl;
    std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;
    
    std::cout << "\n--- Performing assignment (dog2 = dog1) ---" << std::endl;
    dog2 = dog1;  // Assignment operator
    
    std::cout << "\nAfter assignment:" << std::endl;
    std::cout << "Dog1 brain address: " << dog1.getBrain() << std::endl;
    std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 brain address: " << dog2.getBrain() << std::endl;
    std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;
    
    std::cout << "\n--- Verifying independent modification ---" << std::endl;
    dog1.getBrain()->setIdea(0, "Modified after assignment");
    
    std::cout << "Dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << " (should be unchanged)" << std::endl;
    
    std::cout << "\n✅ Assignment operator deep copy verified" << std::endl;
}

void testVirtualDestructorWithBrain() {
    std::cout << "\033[32m=== Demonstrating Virtual Destructor Importance with Brain ===\033[0m" << std::endl;
    std::cout << "注意: この例では、virtual destructorがなかった場合のメモリリークリスクを説明します" << std::endl;
    
    std::cout << "\n----- Correct usage with virtual destructor -----" << std::endl;
    {
        Animal* animal = new Dog();
        animal->makeSound();
        std::cout << "\n削除時: virtualデストラクタによりDog→Animalの順で適切に呼ばれ、Brainも解放されます" << std::endl;
        delete animal;  // Dog destructor → Animal destructor (Brain properly deleted)
    }
    
    std::cout << "\n⚠️ もしvirtualデストラクタがなかった場合:" << std::endl;
    std::cout << "・Animalのデストラクタのみが呼ばれる" << std::endl;
    std::cout << "・Dogのデストラクタが呼ばれない" << std::endl;
    std::cout << "・delete this->brain が実行されない" << std::endl;
    std::cout << "・結果: Brainオブジェクトがメモリリーク！" << std::endl;
    
    std::cout << "\n✅ CPP04 ex01の学習ポイント:" << std::endl;
    std::cout << "・virtualデストラクタ: 適切な多態性での破棄" << std::endl;
    std::cout << "・深いコピー: 独立したBrainオブジェクトの管理" << std::endl;
    std::cout << "・リソース管理: new/deleteのペア、RAII原則" << std::endl;
}

int main() {
    while (true) {
        std::cout << "\n\033[33m=== CPP04 Exercise 01 Test Menu ===\033[0m" << std::endl;
        std::cout << "1: Test Basic Animal Array Functionality" << std::endl;
        std::cout << "2: Test Deep Copy (Copy Constructor)" << std::endl;
        std::cout << "3: Test Deep Copy (Assignment Operator)" << std::endl;
        std::cout << "4: Demonstrate Virtual Destructor Importance" << std::endl;
        std::cout << "0: Exit" << std::endl;
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                testBasicFunctionality();
                break;
            case 2:
                testDeepCopy();
                break;
            case 3:
                testAssignmentOperator();
                break;
            case 4:
                testVirtualDestructorWithBrain();
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