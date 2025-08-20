/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/20 22:11:20 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// CPP04 Exercise 02: Abstract class
// Main differences from ex01: Make Animal class abstract
// 1. Change Animal::makeSound() to pure virtual function (= 0)
// 2. Direct instantiation of Animal objects becomes impossible
// 3. Dog/Cat continue to work normally (since makeSound() is already implemented)
// 4. Polymorphism is maintained (can handle Dog/Cat as Animal*)

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <limits>

void testBasicFunctionality();
void testDeepCopy();
void testAssignmentOperator();
void testAbstractClass();
void testVirtualDestructorWithBrain();
void testPolymorphismUseCases();
void testExceptionHandling();


int main() {
	int choice;
	bool running = true;

	while (running) {
		std::cout << "\n\033[33m=== CPP04 Exercise 02 Abstract class. ===\033[0m" << std::endl;
		std::cout << "1: Test Basic Animal Array Functionality                    Animal[] でPolymorphism機能テスト" << std::endl;
		std::cout << "2: Test Deep Copy (Copy Constructor)                        ディープコピーテスト（コピーコンストラクタ）" << std::endl;
		std::cout << "3: Test Deep Copy (Assignment Operator)                     代入演算子テスト" << std::endl;
		std::cout << "4: Test Abstract Class (ex02 Feature)                       抽象クラステスト（ex02機能）" << std::endl;
		std::cout << "5: Demonstrate Virtual Destructor Importance                仮想デストラクタの重要性テスト" << std::endl;
		std::cout << "6: Polymorphism Use Case Examples                           多態性使用例" << std::endl;
		std::cout << "0: Exit                                                     終了" << std::endl;
		std::cout << "Please select an option / 選択してください: ";

		// Exception-safe input handling
		if (!(std::cin >> choice)) {
			std::cout << "⚠️ Invalid input! Please enter a number. / 無効な入力です！数字を入力してください。" << std::endl;
			std::cin.clear();  // Clear error flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer
			continue;
		}

		try {
				std::cout << std::endl;
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
					testAbstractClass();
					break;
				case 5:
					testVirtualDestructorWithBrain();
					break;
				case 6:
					testPolymorphismUseCases();
					break;
				case 0:
					running = false;
					break;
				default:
					std::cout << "Invalid selection. Please try again. / 無効な選択です。もう一度試してください。" << std::endl;
			}
		} catch (const std::exception &e) {
			std::cout << "⚠️ Exception caught: " << e.what() << std::endl;
			std::cout << "Test continued... / テストを継続します..." << std::endl;
		}
	}

	return 0;
}

void testBasicFunctionality() {
	std::cout << "\033[32m=== 1: Testing Basic Animal Array Functionality ===\033[0m" << std::endl;

	const int ARRAY_SIZE = 4;
	Animal* animals[ARRAY_SIZE];
	int created = 0;  // Track number of successfully created animals

	std::cout << "\n----- Creating Animal Array (half Dogs, half Cats) -----" << std::endl;
	try {
		// Fill half with dogs, half with cats
		for (int i = 0; i < ARRAY_SIZE / 2; i++) {
			std::cout << "Creating Dog[" << i << "]:" << std::endl;
			animals[i] = new Dog();
			created++;
			std::cout << std::endl;
		}

		for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; i++) {
			std::cout << "Creating Cat[" << i << "]:" << std::endl;
			animals[i] = new Cat();
			created++;
			std::cout << std::endl;
		}
	} catch (const std::bad_alloc &e) {
		std::cout << "⚠️ Memory allocation failed: " << e.what() << std::endl;
		std::cout << "Cleaning up already created animals..." << std::endl;
		for (int i = 0; i < created; i++) {
			delete animals[i];
		}
		return;
	} catch (const std::exception &e) {
		std::cout << "⚠️ Exception during creation: " << e.what() << std::endl;
		for (int i = 0; i < created; i++) {
			delete animals[i];
		}
		return;
	}

	std::cout << "\n----- Testing Polymorphic Behavior -----" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++) {
		std::cout << "Animal[" << i << "] (" << animals[i]->getType() << "): ";
		animals[i]->makeSound();
	}

	std::cout << "\n----- Destroying Animals (virtual destructor ensures proper cleanup) -----" << std::endl;
	try {
		for (int i = 0; i < ARRAY_SIZE; i++) {
			std::cout << "Deleting Animal[" << i << "]:" << std::endl;
			delete animals[i];
			std::cout << std::endl;
		}
	} catch (const std::exception &e) {
		std::cout << "⚠️ Exception during destruction: " << e.what() << std::endl;
	}
}

void testDeepCopy() {
	std::cout << "\033[32m=== 2: Testing Deep Copy (Copy Constructor) ===\033[0m" << std::endl;

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
	std::cout << "\033[32m=== 3: Testing Deep Copy (Assignment Operator) ===\033[0m" << std::endl;

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

	std::cout << "\n-----  Testing Cat Assignment Operator -----" << std::endl;
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

void testAbstractClass() {
	std::cout << "\033[32m=== 4: Testing Abstract Class (ex02 Feature) ===\033[0m" << std::endl;
	std::cout << "ex02の学習目標: Abstract classによりAnimalの直接インスタンス化を禁止" << std::endl;

	std::cout << "\n----- 抽象クラスとは -----" << std::endl;
	std::cout << "・純粋仮想関数（= 0）を1つ以上持つクラス" << std::endl;
	std::cout << "・直接インスタンス化できない" << std::endl;
	std::cout << "・派生クラスは純粋仮想関数を実装する必要がある" << std::endl;

	std::cout << "\n----- 抽象クラス vs 普通のクラスの比較 -----" << std::endl;
	std::cout << "Animal（抽象クラス）: インスタンス化不可" << std::endl;
	std::cout << "WrongAnimal（普通のクラス）: インスタンス化可能" << std::endl;

	std::cout << "\n----- コンパイルエラーになるコード例 -----" << std::endl;
	std::cout << "以下のコードのコメントアウトを外すとコンパイルエラー:" << std::endl;
	std::cout << "  // Animal animal;          // Error: cannot instantiate abstract class" << std::endl;
	std::cout << "  // Animal* ptr = new Animal(); // Error: cannot instantiate abstract class" << std::endl;

	// ex02: The following code will cause compile errors, so commenting out is mandatory
	// Learning demonstration - not actually usable
	/*
	// Uncommenting these will cause compile-time errors:
	// error: variable type 'Animal' is an abstract class
	// error: allocating an object of abstract class type 'Animal'

	Animal animal;                    // Error: abstract classes cannot be instantiated
	Animal* animalPtr = new Animal(); // Error: abstract classes cannot be created with new
	delete animalPtr;
	*/

	std::cout << "\n----- WrongAnimalとの違い: 普通のクラスの動作確認 -----" << std::endl;
	std::cout << "WrongAnimal wrongAnimal;  // OK: Normal classes can be instantiated" << std::endl;
	// WrongAnimal wrongAnimal;  //
	std::cout << "WrongAnimal* wrongPtr = new WrongAnimal();  // OK" << std::endl;
	// WrongAnimal* wrongPtr = new WrongAnimal(); 
	// delete wrongPtr;
	std::cout << "→ WrongAnimalは普通のクラスなので直接インスタンス化可能" << std::endl;

	std::cout << "\n----- 正常動作: 派生クラス経由でのアクセス -----" << std::endl;
	std::cout << "Animal*ポインタとして派生クラスを扱うことは可能:" << std::endl;

	
	Animal* dogPtr = new Dog();		// OK: Create a Dog object and assign it to an Animal pointer
	Animal* catPtr = new Cat();		// OK: Create a Cat object and assign it to an Animal pointer

	std::cout << "\nDog via Animal* pointer:" << std::endl;
	std::cout << "Type: " << dogPtr->getType() << std::endl;
	dogPtr->makeSound();  // Dog::makeSound() is called (polymorphism)

	std::cout << "\nCat via Animal* pointer:" << std::endl;
	std::cout << "Type: " << catPtr->getType() << std::endl;
	catPtr->makeSound();  // Cat::makeSound() is called (polymorphism)

	delete dogPtr;
	delete catPtr;

	std::cout << "\n✅ 抽象クラスの効果:" << std::endl;
	std::cout << "・意味のないAnimalオブジェクトの作成を防止" << std::endl;
	std::cout << "・多態性は維持（Animal*としてDog/Catを扱い可能）" << std::endl;
	std::cout << "・派生クラスでのmakeSound()実装を強制" << std::endl;
	std::cout << "・設計意図の明確化（\"動物は具体的でなければならない\"）" << std::endl;
	std::cout << "\n⚖️ Animalクラス vs WrongAnimalクラス:" << std::endl;
	std::cout << "・Animal: 抽象クラス → インスタンス化不可" << std::endl;
	std::cout << "・WrongAnimal: 普通のクラス → インスタンス化可能" << std::endl;
	std::cout << "・ex02では意図的に抽象化によりAnimal直接生成を禁止" << std::endl;
}

void testVirtualDestructorWithBrain() {
	std::cout << "\033[32m=== 5: Demonstrating Virtual Destructor Importance with Brain ===\033[0m" << std::endl;
	std::cout << "注意: この例では、virtual destructorがなかった場合のメモリリークリスクを説明します" << std::endl;

	std::cout << "\n----- Correct usage with virtual destructor -----" << std::endl;
	{
		Animal* animal = new Dog();
		animal->makeSound();
		std::cout << "\n削除時: virtualデストラクタによりDog→Animalの順で適切に呼ばれ、Brainも解放されます" << std::endl;
		delete animal;  // Dog destructor -> Animal destructor (Brain properly deleted)
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

// Simple polymorphism demo function
void demonstratePolymorphism(Animal* animal) {
	std::cout << "Animal*ポインタ -> 実際は" << animal->getType() << ": ";
	animal->makeSound();
}

void testPolymorphismUseCases() {
	std::cout << "\033[32m=== 6: Polymorphism Use Case Examples ===\033[0m" << std::endl;
	std::cout << "ex02の核心: 抽象クラスによる多態性の実用例" << std::endl;

	std::cout << "\n----- 多態性の基本概念 -----" << std::endl;
	std::cout << "Animal*型ポインタが様々な実体を指す例:\n" << std::endl;

	// Same type (Animal*) pointing to different entities
	Animal* animal1 = new Dog();
	Animal* animal2 = new Cat();

	// Unified processing for each behavior
	demonstratePolymorphism(animal1);
	demonstratePolymorphism(animal2);



	std::cout << "\n----- 配列での多態性活用 -----" << std::endl;
	std::cout << "実行コード:" << std::endl;
	std::cout << "Animal* zoo[3];" << std::endl;
	std::cout << "zoo[0] = new Dog();" << std::endl;
	std::cout << "zoo[1] = new Cat();" << std::endl;
	std::cout << "zoo[2] = new Dog();" << std::endl;
	std::cout << std::endl;

	Animal* zoo[3];
	zoo[0] = new Dog();
	zoo[1] = new Cat();
	zoo[2] = new Dog();

	std::cout << "実行コード:" << std::endl;
	std::cout << "for (int i = 0; i < 3; i++) {" << std::endl;
	std::cout << "    std::cout << \"zoo[\" << i << \"]: \";" << std::endl;
	std::cout << "    demonstratePolymorphism(zoo[i]);" << std::endl;
	std::cout << "}" << std::endl;
	std::cout << "\n実行結果:" << std::endl; 
	// Process all animals with the same code
	for (int i = 0; i < 3; i++) {
		std::cout << "zoo[" << i << "]: ";
		demonstratePolymorphism(zoo[i]);
	}

	std::cout << "\n----- 実用的なユースケース -----" << std::endl;
	std::cout << "1. ペットショップ管理システム:" << std::endl;
	std::cout << "   Animal* petShop[100]; // Unified management of various animals" << std::endl;
	std::cout << "   for (int i = 0; i < petCount; i++) {" << std::endl;
	std::cout << "       petShop[i]->makeSound(); // Each animal's unique sound" << std::endl;
	std::cout << "   }" << std::endl;

	std::cout << "\n2. ゲーム開発:" << std::endl;
	std::cout << "   Animal* enemies[50]; // Various enemy characters" << std::endl;
	std::cout << "   for (int i = 0; i < enemyCount; i++) {" << std::endl;
	std::cout << "       enemies[i]->makeSound(); // Each enemy's unique sound" << std::endl;
	std::cout << "   }" << std::endl;

	std::cout << "\n✅ ex02多態性の効果:" << std::endl;
	std::cout << "・Animal*で統一的に扱える（コードの簡潔性）" << std::endl;
	std::cout << "・実行時に正しいmakeSound()が呼ばれる（動的束縛）" << std::endl;
	std::cout << "・新しい動物追加が容易（拡張性）" << std::endl;
	std::cout << "・抽象クラスにより意味のないAnimalインスタンス化を防止" << std::endl;
	std::cout << "・コードの再利用性・保守性が大幅向上" << std::endl;

	delete animal1;
	delete animal2;
	for (int i = 0; i < 3; i++) {
		delete zoo[i];
	}
}

/*
valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./brain_test

valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./brain_test > VALGLIND.log 2>&1

*/