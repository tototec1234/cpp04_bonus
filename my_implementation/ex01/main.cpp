#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void testBasicFunctionality();
void testDeepCopy();
void testAssignmentOperator();
void testVirtualDestructorWithBrain();
int main() {
    int choice;
    bool running = true;

    while (running) {
        std::cout << "\n=== CPP04 Exercise 01 Test Menu ===" << std::endl;
        std::cout << "=== CPP04 演習01 テストメニュー ===" << std::endl;
        std::cout << "1: Basic Animal Array Functionality Test                    基本的な動物配列機能テスト" << std::endl;
        std::cout << "2: Deep Copy Test                                          ディープコピーテスト" << std::endl;
        std::cout << "3: Assignment Operator Test                                代入演算子テスト" << std::endl;
        std::cout << "4: Virtual Destructor Importance Test                      仮想デストラクタの重要性テスト" << std::endl;
        std::cout << "0: Exit                                                    終了" << std::endl;
        std::cout << "Please select an option / 選択してください: ";
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
                running = false;
                break;
            default:
                std::cout << "Invalid selection. Please try again. / 無効な選択です。もう一度試してください。" << std::endl;
        }
    }

    return 0;
}





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
    
    std::cout << "\n----- Testing Dog Assignment Operator -----" << std::endl;
    {
        Dog dog1;
        Dog dog2;
        
        dog1.getBrain()->setIdea(0, "Original dog idea");
        dog1.getBrain()->setIdea(1, "Another original idea");
        
        dog2.getBrain()->setIdea(0, "Different dog idea");
        
        std::cout << "\nBefore assignment:" << std::endl;
        std::cout << "Dog1 brain address: " << dog1.getBrain() << std::endl;
        std::cout << "Dog1 ideas:" << std::endl;
        dog1.getBrain()->printIdeas();
        
        std::cout << "\nDog2 brain address: " << dog2.getBrain() << std::endl;
        std::cout << "Dog2 ideas:" << std::endl;
        dog2.getBrain()->printIdeas();
        
        std::cout << "\n--- Performing assignment (dog2 = dog1) ---" << std::endl;
        dog2 = dog1;  // Assignment operator
        
        std::cout << "\nAfter assignment:" << std::endl;
        std::cout << "Dog1 brain address: " << dog1.getBrain() << std::endl;
        std::cout << "Dog2 brain address: " << dog2.getBrain() << std::endl;
        std::cout << "Dog2 ideas (should be same content, different address):" << std::endl;
        dog2.getBrain()->printIdeas();
        
        std::cout << "\n--- Verifying independent modification ---" << std::endl;
        dog1.getBrain()->setIdea(0, "Modified after assignment");
        
        std::cout << "\nAfter modifying dog1:" << std::endl;
        std::cout << "Dog1 ideas (modified):" << std::endl;
        dog1.getBrain()->printIdeas();
        
        std::cout << "Dog2 ideas (should be unchanged - proof of deep copy):" << std::endl;
        dog2.getBrain()->printIdeas();
        
        std::cout << "\n✅ Dog assignment operator deep copy verified" << std::endl;
    }
    
    std::cout << "\n----- Testing Cat Assignment Operator -----" << std::endl;
    {
        Cat cat1;
        Cat cat2;
        
        cat1.getBrain()->setIdea(0, "Original cat idea");
        cat1.getBrain()->setIdea(1, "Sleep in sunny spot");
        
        cat2.getBrain()->setIdea(0, "Different cat idea");
        
        std::cout << "\nBefore assignment:" << std::endl;
        std::cout << "Cat1 brain address: " << cat1.getBrain() << std::endl;
        std::cout << "Cat1 ideas:" << std::endl;
        cat1.getBrain()->printIdeas();
        
        std::cout << "\nCat2 brain address: " << cat2.getBrain() << std::endl;
        std::cout << "Cat2 ideas:" << std::endl;
        cat2.getBrain()->printIdeas();
        
        std::cout << "\n--- Performing assignment (cat2 = cat1) ---" << std::endl;
        cat2 = cat1;  // Assignment operator
        
        std::cout << "\nAfter assignment:" << std::endl;
        std::cout << "Cat1 brain address: " << cat1.getBrain() << std::endl;
        std::cout << "Cat2 brain address: " << cat2.getBrain() << std::endl;
        std::cout << "Cat2 ideas (should be same content, different address):" << std::endl;
        cat2.getBrain()->printIdeas();
        
        std::cout << "\n--- Verifying independent modification ---" << std::endl;
        cat1.getBrain()->setIdea(0, "Modified cat thought");
        
        std::cout << "\nAfter modifying cat1:" << std::endl;
        std::cout << "Cat1 ideas (modified):" << std::endl;
        cat1.getBrain()->printIdeas();
        
        std::cout << "Cat2 ideas (should be unchanged - proof of deep copy):" << std::endl;
        cat2.getBrain()->printIdeas();
        
        std::cout << "\n✅ Cat assignment operator deep copy verified" << std::endl;
    }
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