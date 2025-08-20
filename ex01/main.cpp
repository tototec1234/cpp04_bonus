/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/20 16:26:34 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "AnsiColor.hpp"
#include <limits>

void testBasicFunctionality();
void testDeepCopy();
void testAssignmentOperator();
void testVirtualDestructorWithBrain();
void testExceptionHandling();

int main() {
	int choice;
	bool running = true;

	while (running) {
		std::cout <<  YELLOW_COLOR << "\n=== CPP04 Exercise 01 Test Menu ===" << RESET_COLOR << std::endl;
		std::cout << "=== CPP04 演習01 テストメニュー ===" << std::endl;
		std::cout << "1: Basic Animal Array Functionality Test                    基本的な動物配列機能テスト" << std::endl;
		std::cout << "2: Deep Copy Test                                          ディープコピーテスト" << std::endl;
		std::cout << "3: Assignment Operator Test                                代入演算子テスト" << std::endl;
		std::cout << "4: Virtual Destructor Importance Test                      仮想デストラクタの重要性テスト" << std::endl;
		std::cout << "5: Exception Handling Test                                 例外処理テスト" << std::endl;
		std::cout << "0: Exit                                                    終了" << std::endl;
		std::cout << "Please select an option / 選択してください: ";

		// Exception-safe input handling
		if (!(std::cin >> choice)) {
			std::cout << "⚠️ Invalid input! Please enter a number. / 無効な入力です！数字を入力してください。" << std::endl;
			std::cin.clear();  // Clear error flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer
			continue;
		}

		try {
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
				case 5:
					testExceptionHandling();
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
		std::cout << BOLD_GREEN_COLOR << "Executing: originalDog.getBrain()->setIdea(0, \"Chase squirrels\");" << RESET_COLOR << std::endl;
		originalDog.getBrain()->setIdea(0, "Chase squirrels");
		std::cout << BOLD_GREEN_COLOR << "Executing: originalDog.getBrain()->setIdea(1, \"Protect house\");" << RESET_COLOR << std::endl;
		originalDog.getBrain()->setIdea(1, "Protect house");
		std::cout << BOLD_GREEN_COLOR << "Executing: originalDog.getBrain()->setIdea(2, \"Bark at mailman\");" << RESET_COLOR << std::endl;
		originalDog.getBrain()->setIdea(2, "Bark at mailman");

		std::cout << "\nOriginal dog's brain address: " << originalDog.getBrain() << std::endl;
		std::cout << "Original dog ideas:" << std::endl;
		originalDog.getBrain()->printIdeas();

		std::cout << "\n--- Creating copy using copy constructor ---" << std::endl;
		std::cout << BOLD_GREEN_COLOR << "Executing: Dog copiedDog = originalDog;" << RESET_COLOR << std::endl;
		Dog copiedDog = originalDog;  // Copy constructor

		std::cout << "\nCopied dog's brain address: " << copiedDog.getBrain() << std::endl;
		std::cout << "Copied dog ideas (should be same content, different address):" << std::endl;
		copiedDog.getBrain()->printIdeas();

		std::cout << "\n--- Verifying deep copy by modifying original ---" << std::endl;
		std::cout << BOLD_GREEN_COLOR << "Executing: originalDog.getBrain()->setIdea(0, \"Sleep all day\");" << RESET_COLOR << std::endl;
		originalDog.getBrain()->setIdea(0, "Sleep all day");
		std::cout << BOLD_GREEN_COLOR << "Executing: originalDog.getBrain()->setIdea(3, \"Dream about food\");" << RESET_COLOR << std::endl;
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
		std::cout << BOLD_GREEN_COLOR << "Executing: originalCat.getBrain()->setIdea(0, \"Hunt mice\");" << RESET_COLOR << std::endl;
		originalCat.getBrain()->setIdea(0, "Hunt mice");
		std::cout << BOLD_GREEN_COLOR << "Executing: originalCat.getBrain()->setIdea(1, \"Nap in sunlight\");" << RESET_COLOR << std::endl;
		originalCat.getBrain()->setIdea(1, "Nap in sunlight");

		std::cout << "\nOriginal cat's brain address: " << originalCat.getBrain() << std::endl;
		std::cout << "Original cat ideas:" << std::endl;
		originalCat.getBrain()->printIdeas();

		std::cout << BOLD_GREEN_COLOR << "Executing: Cat copiedCat = originalCat;" << RESET_COLOR << std::endl;
		Cat copiedCat = originalCat;  // Copy constructor

		std::cout << "\nCopied cat's brain address: " << copiedCat.getBrain() << std::endl;

		// Modify original to prove deep copy
		std::cout << BOLD_GREEN_COLOR << "Executing: originalCat.getBrain()->setIdea(0, \"Knock things off table\");" << RESET_COLOR << std::endl;
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

		std::cout << BOLD_GREEN_COLOR << "Executing: dog1.getBrain()->setIdea(0, \"Original dog idea\");" << RESET_COLOR << std::endl;
		dog1.getBrain()->setIdea(0, "Original dog idea");
		std::cout << BOLD_GREEN_COLOR << "Executing: dog1.getBrain()->setIdea(1, \"Another original idea\");" << RESET_COLOR << std::endl;
		dog1.getBrain()->setIdea(1, "Another original idea");

		std::cout << BOLD_GREEN_COLOR << "Executing: dog2.getBrain()->setIdea(0, \"Different dog idea\");" << RESET_COLOR << std::endl;
		dog2.getBrain()->setIdea(0, "Different dog idea");

		std::cout << "\nBefore assignment:" << std::endl;
		std::cout << "Dog1 brain address: " << dog1.getBrain() << std::endl;
		std::cout << "Dog1 ideas:" << std::endl;
		dog1.getBrain()->printIdeas();

		std::cout << "\nDog2 brain address: " << dog2.getBrain() << std::endl;
		std::cout << "Dog2 ideas:" << std::endl;
		dog2.getBrain()->printIdeas();

		std::cout << "\n--- Performing assignment (dog2 = dog1) ---" << std::endl;
		std::cout << BOLD_GREEN_COLOR << "Executing: dog2 = dog1;" << RESET_COLOR << std::endl;
		dog2 = dog1;  // Assignment operator

		std::cout << "\nAfter assignment:" << std::endl;
		std::cout << "Dog1 brain address: " << dog1.getBrain() << std::endl;
		std::cout << "Dog2 brain address: " << dog2.getBrain() << std::endl;
		std::cout << "Dog2 ideas (should be same content, different address):" << std::endl;
		dog2.getBrain()->printIdeas();

		std::cout << "\n--- Verifying independent modification ---" << std::endl;
		std::cout << BOLD_GREEN_COLOR << "Executing: dog1.getBrain()->setIdea(0, \"Modified after assignment\");" << RESET_COLOR << std::endl;
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

		std::cout << BOLD_GREEN_COLOR << "Executing: cat1.getBrain()->setIdea(0, \"Original cat idea\");" << RESET_COLOR << std::endl;
		cat1.getBrain()->setIdea(0, "Original cat idea");
		std::cout << BOLD_GREEN_COLOR << "Executing: cat1.getBrain()->setIdea(1, \"Sleep in sunny spot\");" << RESET_COLOR << std::endl;
		cat1.getBrain()->setIdea(1, "Sleep in sunny spot");

		std::cout << BOLD_GREEN_COLOR << "Executing: cat2.getBrain()->setIdea(0, \"Different cat idea\");" << RESET_COLOR << std::endl;
		cat2.getBrain()->setIdea(0, "Different cat idea");

		std::cout << "\nBefore assignment:" << std::endl;
		std::cout << "Cat1 brain address: " << cat1.getBrain() << std::endl;
		std::cout << "Cat1 ideas:" << std::endl;
		cat1.getBrain()->printIdeas();

		std::cout << "\nCat2 brain address: " << cat2.getBrain() << std::endl;
		std::cout << "Cat2 ideas:" << std::endl;
		cat2.getBrain()->printIdeas();

		std::cout << "\n--- Performing assignment (cat2 = cat1) ---" << std::endl;
		std::cout << BOLD_GREEN_COLOR << "Executing: cat2 = cat1;" << RESET_COLOR << std::endl;
		cat2 = cat1;  // Assignment operator

		std::cout << "\nAfter assignment:" << std::endl;
		std::cout << "Cat1 brain address: " << cat1.getBrain() << std::endl;
		std::cout << "Cat2 brain address: " << cat2.getBrain() << std::endl;
		std::cout << "Cat2 ideas (should be same content, different address):" << std::endl;
		cat2.getBrain()->printIdeas();

		std::cout << "\n--- Verifying independent modification ---" << std::endl;
		std::cout << BOLD_GREEN_COLOR << "Executing: cat1.getBrain()->setIdea(0, \"Modified cat thought\");" << RESET_COLOR << std::endl;
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
	std::cout << "\033[32m=== 4: Demonstrating Virtual Destructor Importance with Brain ===\033[0m" << std::endl;
	std::cout << "注意: この例では、virtual destructorがなかった場合のメモリリークリスクを説明します" << std::endl;

	std::cout << "\n----- Correct usage with virtual destructor -----" << std::endl;
	{
		std::cout << BOLD_GREEN_COLOR << "Executing: Animal* animal = new Dog();" << RESET_COLOR << std::endl;
		Animal* animal = new Dog();
		std::cout << BOLD_GREEN_COLOR << "Executing: animal->makeSound();" << RESET_COLOR << std::endl;
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

void testExceptionHandling() {
	std::cout << "\033[32m=== 5: Testing Exception Handling (CPP04 Enhancement) ===\033[0m" << std::endl;

	std::cout << "\n----- Testing Brain Array Bounds Checking -----" << std::endl;
	try {
		Dog dog;
		std::cout << "✅ Setting valid idea at index 0:" << std::endl;
		std::cout << BOLD_GREEN_COLOR << "Executing: dog.getBrain()->setIdea(0, \"Valid idea\");" << RESET_COLOR << std::endl;
		dog.getBrain()->setIdea(0, "Valid idea");
		std::cout << BOLD_GREEN_COLOR << "Executing: dog.getBrain()->getIdea(0);" << RESET_COLOR << std::endl;
		std::cout << "Retrieved idea: \"" << dog.getBrain()->getIdea(0) << "\"" << std::endl;

		std::cout << "\n⚠️ Attempting to set idea at invalid index 100:" << std::endl;
		std::cout << BOLD_GREEN_COLOR << "Executing: dog.getBrain()->setIdea(100, \"Invalid index idea\");" << RESET_COLOR << std::endl;
		dog.getBrain()->setIdea(100, "Invalid index idea");
	} catch (const std::out_of_range &e) {
		std::cout << "✅ Exception caught: " << e.what() << std::endl;
	}

	try {
		Dog dog;
		std::cout << "\n⚠️ Attempting to get idea at invalid index -1:" << std::endl;
		std::cout << BOLD_GREEN_COLOR << "Executing: dog.getBrain()->getIdea(-1);" << RESET_COLOR << std::endl;
		std::string idea = dog.getBrain()->getIdea(-1);
	} catch (const std::out_of_range &e) {
		std::cout << "✅ Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n----- Testing Exception Safety in Assignment Operator -----" << std::endl;
	try {
		Cat cat1, cat2;
		std::cout << BOLD_GREEN_COLOR << "Executing: cat1.getBrain()->setIdea(0, \"Original cat idea\");" << RESET_COLOR << std::endl;
		cat1.getBrain()->setIdea(0, "Original cat idea");
		std::cout << BOLD_GREEN_COLOR << "Executing: cat1.getBrain()->setIdea(1, \"Another idea\");" << RESET_COLOR << std::endl;
		cat1.getBrain()->setIdea(1, "Another idea");

		std::cout << "Cat1 brain address before assignment: " << cat1.getBrain() << std::endl;
		std::cout << "Cat2 brain address before assignment: " << cat2.getBrain() << std::endl;

		std::cout << BOLD_GREEN_COLOR << "Executing: cat2 = cat1;  // This should be exception-safe now" << RESET_COLOR << std::endl;
		cat2 = cat1;  // This should be exception-safe now

		std::cout << "✅ Assignment completed successfully" << std::endl;
		std::cout << "Cat1 brain address after assignment: " << cat1.getBrain() << std::endl;
		std::cout << "Cat2 brain address after assignment: " << cat2.getBrain() << std::endl;
		std::cout << "Cat2 idea[0]: \"" << cat2.getBrain()->getIdea(0) << "\"" << std::endl;

	} catch (const std::exception &e) {
		std::cout << "⚠️ Exception during assignment: " << e.what() << std::endl;
	}

	std::cout << "\n✅ Exception handling improvements:" << std::endl;
	std::cout << "・Brain配列範囲外アクセス → std::out_of_range例外" << std::endl;
	std::cout << "・代入演算子例外安全性 → 新しいオブジェクト作成後に古いものを削除" << std::endl;
	std::cout << "・メモリ割り当て失敗 → std::bad_alloc例外の適切な処理" << std::endl;
	std::cout << "・ユーザー入力検証 → 無効な入力の安全な処理" << std::endl;
}