/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_virtual.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:21:07 by toruinoue         #+#    #+#             */
/*   Updated: 2025/08/20 18:36:50 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include "AnsiColor.hpp"
#include "tests.hpp"

void testVirtualPolymorphismProblem() {
	std::cout << "\033[31m=== 3: Virtual不足問題の実証 ===\033[0m" << std::endl;
	std::cout << "Wrong系クラスにはvirtualキーワードがありません！\n" << std::endl;

	std::cout << "----- ✅ 正常なポリモーフィズム (Animal系 - virtual使用) -----" << std::endl;
	{
		std::cout << BOLD_GREEN_COLOR << "Executing: Animal* animal = new Dog();" << RESET_COLOR << std::endl;
		Animal* animal = new Dog();
		std::cout << BOLD_GREEN_COLOR << "Executing: animal->makeSound(); // virtual -> Dog::makeSound()が呼ばれる" << RESET_COLOR << std::endl;
		animal->makeSound();
		std::cout << BOLD_GREEN_COLOR << "Executing: delete animal;" << RESET_COLOR << std::endl;
		delete animal;
		std::cout << "✅ 期待通り：Dogの鳴き声\n" << std::endl;
	}

	std::cout << "----- 🔴 問題のあるポリモーフィズム (WrongAnimal系 - virtual未使用) -----" << std::endl;
	{
		std::cout << BOLD_GREEN_COLOR << "Executing: WrongAnimal* wrongAnimal = new WrongCat();" << RESET_COLOR << std::endl;
		WrongAnimal* wrongAnimal = new WrongCat();
		std::cout << BOLD_GREEN_COLOR << "Executing: wrongAnimal->makeSound(); // NOT virtual -> WrongAnimal::makeSound()が呼ばれる" << RESET_COLOR << std::endl;
		wrongAnimal->makeSound();
		std::cout << BOLD_GREEN_COLOR << "Executing: delete wrongAnimal; // ⚠️ メモリリークも発生" << RESET_COLOR << std::endl;
		delete wrongAnimal;  // CAUTION Memory leak also occurs
		std::cout << "❌ 問題：WrongAnimalの鳴き声（WrongCatではない）\n" << std::endl;
	}

	{
		std::cout << BOLD_GREEN_COLOR << "Executing: WrongAnimal* wrongAnimal = new WrongDog();" << RESET_COLOR << std::endl;
		WrongAnimal* wrongAnimal = new WrongDog();
		std::cout << BOLD_GREEN_COLOR << "Executing: wrongAnimal->makeSound(); // NOT virtual -> WrongAnimal::makeSound()が呼ばれる" << RESET_COLOR << std::endl;
		wrongAnimal->makeSound();
		std::cout << BOLD_GREEN_COLOR << "Executing: delete wrongAnimal; // ⚠️ メモリリークも発生" << RESET_COLOR << std::endl;
		delete wrongAnimal;  /// CAUTION Memory leak also occurs
		std::cout << "❌ 問題：WrongAnimalの鳴き声（WrongDogではない）\n" << std::endl;
	}

	std::cout << "📚 学習ポイント:" << std::endl;
	std::cout << "・virtualなしではベースクラスのメソッドが呼ばれる" << std::endl;
	std::cout << "・ポリモーフィズムが機能しない" << std::endl;
	std::cout << "・virtual destructorなしでメモリリークも発生" << std::endl;
}
