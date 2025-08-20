/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_basic.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:00:00 by toruinoue        #+#    #+#             */
/*   Updated: 2025/01/27 22:00:00 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "AnsiColor.hpp"
#include "tests.hpp"

void testSubjectRequiredBasic() {
	std::cout << "\033[32m=== 1: 課題書要求の基本テスト ===\033[0m" << std::endl;
	std::cout << "Ex01要求：Dog/CatにBrainを追加、配列でテスト、deep copyの確認\n" << std::endl;

	const int ARRAY_SIZE = 4;
	Animal* animals[ARRAY_SIZE];

	std::cout << "----- Animal配列の作成 (半分Dog、半分Cat) -----" << std::endl;
	for (int i = 0; i < ARRAY_SIZE / 2; i++) {
		std::cout << "Dog[" << i << "]を作成:" << std::endl;
		animals[i] = new Dog();
	}
	for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; i++) {
		std::cout << "Cat[" << i << "]を作成:" << std::endl;
		animals[i] = new Cat();
	}

	std::cout << "\n----- 各動物の鳴き声テスト (virtual正常動作) -----" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++) {
		std::cout << "animals[" << i << "] type: " << animals[i]->getType() << " -> ";
		animals[i]->makeSound();
	}

	std::cout << "\n----- Deep Copyテスト -----" << std::endl;
	{
		Cat cat1;
		cat1.getBrain().setIdea(0, "Original cat idea");
		
		std::cout << "Cat1のBrainアドレス: " << &cat1.getBrain() << std::endl;
		std::cout << "Cat1 idea[0]: \"" << cat1.getBrain().getIdea(0) << "\"" << std::endl;
		
		Cat cat2(cat1);  // Copy constructor
		std::cout << "Cat2のBrainアドレス: " << &cat2.getBrain() << std::endl;
		std::cout << "Cat2 idea[0]: \"" << cat2.getBrain().getIdea(0) << "\"" << std::endl;
		
		if (&cat1.getBrain() != &cat2.getBrain()) {
			std::cout << "✅ Deep copy成功：異なるBrainオブジェクト" << std::endl;
		} else {
			std::cout << "❌ Shallow copy：同じBrainオブジェクト" << std::endl;
		}
		
		cat2.getBrain().setIdea(0, "Modified cat idea");
		std::cout << "Cat2のidea変更後:" << std::endl;
		std::cout << "Cat1 idea[0]: \"" << cat1.getBrain().getIdea(0) << "\"" << std::endl;
		std::cout << "Cat2 idea[0]: \"" << cat2.getBrain().getIdea(0) << "\"" << std::endl;
		
		if (cat1.getBrain().getIdea(0) != cat2.getBrain().getIdea(0)) {
			std::cout << "✅ Deep copy確認：Cat1に影響なし" << std::endl;
		} else {
			std::cout << "❌ Shallow copy：Cat1も変更された" << std::endl;
		}
	}

	std::cout << "\n----- 配列の削除 (virtual destructor動作確認) -----" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++) {
		std::cout << "animals[" << i << "]を削除:" << std::endl;
		delete animals[i];
	}
	
	std::cout << "\n✅ 課題書要求の基本機能テスト完了" << std::endl;
}
