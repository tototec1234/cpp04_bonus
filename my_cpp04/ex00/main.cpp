/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/19 21:33:56 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "AnsiColor.hpp"

void testCorrectPolymorphism();
void testWrongPolymorphism();
void testVirtualDestructorImportance();


int main() {
	while (true) {
	    std::cout << YELLOW_COLOR << "\n\n=== Animal Test Menu ===" << RESET_COLOR << std::endl;
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
	            testWrongPolymorphism();
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
	std::cout << GREEN_COLOR << "=== Testing Correct Polymorphism ===" << RESET_COLOR << std::endl;

	const Animal* meta = new Animal();
	std::cout << std::endl;
	const Animal* j = new Dog();
	std::cout << std::endl;
	const Animal* i = new Cat();

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

	std::cout << "\n=== Testing Copy ===" << std::endl;
	
	// std::cout << "\n=== Testing Stack Objects ===\n" << std::endl;

	// Cat stackCat;
	// std::cout << std::endl;

	// std::cout << "\n----- Stack object sounds -----" << std::endl;
	// stackCat.makeSound();
}

void testWrongPolymorphism() {
	std::cout << MAGENTA_COLOR << "=== Testing Wrong Polymorphism ===" << RESET_COLOR << std::endl;

	// const WrongAnimal* wrongCat = new WrongCat();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << std::endl;

	std::cout << wrongCat->getType() << " " << std::endl;
	
	std::cout << std::endl;

	std::cout << "\n----- Wrong sounds (should both be WrongAnimal sound) -----" << std::endl;
		std::cout << std::endl;

	wrongCat->makeSound();
		std::cout << std::endl;

	std::cout << "\n----- Destroying wrong animals -----" << std::endl;
	delete wrongCat;
	std::cout << std::endl;

	std::cout << "\n=== Testing Stack Objects ===\n" << std::endl;
	// WrongCat stackWrongCat;
	WrongAnimal stackWrongCat = WrongCat();
	
	std::cout << std::endl;

	std::cout << "\n----- Stack object sounds -----" << std::endl;
	stackWrongCat.makeSound();
}

void testVirtualDestructorImportance() {
	std::cout << MAGENTA_COLOR << "=== Demonstrating Virtual Destructor Importance ===" << RESET_COLOR << std::endl;
	std::cout << YELLOW_COLOR << "注意: この例では非virtualデストラクタによる問題を明確に示します" << RESET_COLOR << std::endl;
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

	std::cout << MAGENTA_COLOR << "=== 問題の説明 ===" << RESET_COLOR << std::endl;
	std::cout << "• virtualデストラクタがない場合、基底クラスポインタ経由での削除時に" << std::endl;
	std::cout << "  派生クラスのデストラクタが呼ばれません" << std::endl;
	std::cout << "• これによりメモリリークやリソースリークが発生する可能性があります" << std::endl;
	std::cout << "• virtualキーワードは「実質的な」機能を提供し、適切な多態性を実現します" << std::endl;
	std::cout << std::endl;
}
