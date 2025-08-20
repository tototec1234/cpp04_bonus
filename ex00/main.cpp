/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/20 13:52:09 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "AnsiColor.hpp"
#include <limits>

void testCorrectPolymorphism();
void testPolymorphicInstantiationProblems();
void testInheritanceBasedInstantiation();
void testVirtualDestructorImportance();


int main() {
	int choice;
	bool running = true;

	while (running) {
	    std::cout << YELLOW_COLOR << "\n\n=== Animal Test Menu ===" << RESET_COLOR << std::endl;
	    std::cout << "=== 動物テストメニュー ===" << std::endl;
	    std::cout << "1: Test Correct Polymorphism (Animal* with virtual)          正しい多態性テスト" << std::endl;
	    std::cout << "2: Test Polymorphic Instantiation Problems (WrongAnimal*)    多態性インスタンス化問題" << std::endl;
	    std::cout << "3: Test Inheritance-based Instantiation (WrongCat* direct)   継承ベースインスタンス化" << std::endl;
	    std::cout << "4: Demonstrate Virtual Destructor Importance                 仮想デストラクタの重要性" << std::endl;
	    std::cout << "0: Exit                                                      終了" << std::endl;
	    std::cout << "Choose an option / 選択してください: ";

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
	                testCorrectPolymorphism();
	                break;
	            case 2:
	                testPolymorphicInstantiationProblems();
	                break;
	            case 3:
	                testInheritanceBasedInstantiation();
	                break;
	            case 4:
	                testVirtualDestructorImportance();
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


void testCorrectPolymorphism() {
	std::cout << GREEN_COLOR << "=== Testing Correct Polymorphism ===" << RESET_COLOR << std::endl;

	const Animal* meta = nullptr;
	const Animal* j = nullptr;
	const Animal* i = nullptr;

	try {
	    meta = new Animal();
	    std::cout << std::endl;
	    j = new Dog();
	    std::cout << std::endl;
	    i = new Cat();

	    std::cout << j->getType() << " " << std::endl;
	    std::cout << i->getType() << " " << std::endl;

	    std::cout << "\n----- Sounds (should be specific to each animal) -----" << std::endl;
	    meta->makeSound();
	    i->makeSound();
	    j->makeSound();

	    std::cout << "\n----- Destroying animals -----" << std::endl;
	    delete meta;
	    std::cout << std::endl;
	    delete j;
	    std::cout << std::endl;
	    delete i;
	    std::cout << std::endl;
	} catch (const std::bad_alloc &e) {
	    std::cout << "⚠️ Memory allocation failed: " << e.what() << std::endl;
	    std::cout << "Cleaning up allocated animals..." << std::endl;
	    delete meta;
	    delete j;
	    delete i;
	} catch (const std::exception &e) {
	    std::cout << "⚠️ Exception during test: " << e.what() << std::endl;
	    delete meta;
	    delete j;
	    delete i;
	}
}
void testPolymorphicInstantiationProblems() {
	std::cout << MAGENTA_COLOR << "=== Testing Polymorphic Instantiation Problems ===" << RESET_COLOR << std::endl;
	std::cout << YELLOW_COLOR << "基底クラスポインタ経由のインスタンス化 (virtualキーワードなし)" << RESET_COLOR << std::endl;

	const WrongAnimal* wrongCat = nullptr;

	try {
	    // 多態的インスタンス化の試み（基底クラスポインタ使用）
	    wrongCat = new WrongCat();
	    std::cout << std::endl;

	    std::cout << "Type: " << wrongCat->getType() << std::endl;
	    
	    std::cout << std::endl;

	    std::cout << "\n----- 問題: 静的バインディングにより基底クラスのメソッドが呼ばれる -----" << std::endl;
	    std::cout << std::endl;

	    wrongCat->makeSound();  // WrongAnimalのmakeSound()が呼ばれる（問題！）
	    
	    std::cout << "\n----- Destroying WrongCat -----" << std::endl;
	    std::cout << std::endl;
	    delete wrongCat;
	    std::cout << std::endl;
	} catch (const std::bad_alloc &e) {
	    std::cout << "⚠️ Memory allocation failed: " << e.what() << std::endl;
	    delete wrongCat;
	} catch (const std::exception &e) {
	    std::cout << "⚠️ Exception during test: " << e.what() << std::endl;
	    delete wrongCat;
	}
}

void testInheritanceBasedInstantiation() {
	std::cout << GREEN_COLOR << "=== Testing Inheritance-based Instantiation ===" << RESET_COLOR << std::endl;
	std::cout << YELLOW_COLOR << "具象型ポインタによる直接的インスタンス化 (CPP03スタイル)" << RESET_COLOR << std::endl;

	const WrongCat* wrongCat = nullptr;

	try {
	    // 継承的インスタンス化（具象型ポインタ使用）
	    wrongCat = new WrongCat();
	    std::cout << std::endl;

	    std::cout << "Type: " << wrongCat->getType() << std::endl;
	    
	    std::cout << std::endl;

	    std::cout << "\n----- 期待通り: 派生クラスのメソッドが呼ばれる -----" << std::endl;
	    std::cout << std::endl;

	    wrongCat->makeSound();  // WrongCatのmakeSound()が呼ばれる（正常）
	    
	    std::cout << "\n----- Destroying WrongCat -----" << std::endl;
	    std::cout << std::endl;
	    delete wrongCat;
	    std::cout << std::endl;
	} catch (const std::bad_alloc &e) {
	    std::cout << "⚠️ Memory allocation failed: " << e.what() << std::endl;
	    delete wrongCat;
	} catch (const std::exception &e) {
	    std::cout << "⚠️ Exception during test: " << e.what() << std::endl;
	    delete wrongCat;
	}
}

void testVirtualDestructorImportance() {
	std::cout << MAGENTA_COLOR << "=== Demonstrating Virtual Destructor Importance ===" << RESET_COLOR << std::endl;
	std::cout << YELLOW_COLOR << "注意: この例では非virtualデストラクタによる問題を明確に示します" << RESET_COLOR << std::endl;
	std::cout << std::endl;

	std::cout << "\n----- 正しい多態性での破棄 (virtualデストラクタあり) -----" << std::endl;
	{
	    const Animal* correctAnimal = nullptr;
	    try {
	        correctAnimal = new Cat();
	        std::cout << "Type: " << correctAnimal->getType() << std::endl;
	        correctAnimal->makeSound();
	        std::cout << "\n破棄時: virtualデストラクタにより適切な順序で呼ばれます" << std::endl;
	        delete correctAnimal;  // Cat → Animal の順で適切に破棄される
	        std::cout << std::endl;
	        std::cout << std::endl;
	    } catch (const std::bad_alloc &e) {
	        std::cout << "⚠️ Memory allocation failed: " << e.what() << std::endl;
	        delete correctAnimal;
	    } catch (const std::exception &e) {
	        std::cout << "⚠️ Exception during test: " << e.what() << std::endl;
	        delete correctAnimal;
	    }
	}

	std::cout << "\n----- 間違った多態性での破棄 (非virtualデストラクタ) -----" << std::endl;
	{
	    const WrongAnimal* wrongAnimal = nullptr;
	    try {
	        wrongAnimal = new WrongCat();
	        std::cout << "Type: " << wrongAnimal->getType() << std::endl;
	        wrongAnimal->makeSound();
	        std::cout << "\n破棄時: 非virtualデストラクタのため問題が発生します" << std::endl;
	        delete wrongAnimal;  // WrongCatのデストラクタが呼ばれない！
	        std::cout << std::endl;
	    } catch (const std::bad_alloc &e) {
	        std::cout << "⚠️ Memory allocation failed: " << e.what() << std::endl;
	        delete wrongAnimal;
	    } catch (const std::exception &e) {
	        std::cout << "⚠️ Exception during test: " << e.what() << std::endl;
	        delete wrongAnimal;
	    }
	}

	std::cout << MAGENTA_COLOR << "=== 問題の説明 ===" << RESET_COLOR << std::endl;
	std::cout << "• virtualデストラクタがない場合、基底クラスポインタ経由での削除時に" << std::endl;
	std::cout << "  派生クラスのデストラクタが呼ばれません" << std::endl;
	std::cout << "• これによりメモリリークやリソースリークが発生する可能性があります" << std::endl;
	std::cout << "• virtualキーワードは「実質的な」機能を提供し、適切な多態性を実現します" << std::endl;
	std::cout << std::endl;
}
