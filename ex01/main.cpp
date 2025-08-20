/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/20 17:27:11 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include "WrongBrain.hpp"
#include "AnsiColor.hpp"
#include <limits>

// 実験計画法的アプローチ：2つの核心問題に焦点を絞ったテスト
void testSubjectRequiredBasic();
void testVirtualPolymorphismProblem();
void testShallowCopyProblem();

int main() {
	int choice;
	bool running = true;

	while (running) {
		std::cout << YELLOW_COLOR << "\n=== CPP04 Ex01: 実験計画法的テスト ===" << RESET_COLOR << std::endl;
		std::cout << "課題書要求：A copy of a Dog or a Cat mustn't be shallow." << std::endl;
		std::cout << "Wrong系クラスで2つの問題を実証します：\n" << std::endl;
		
		std::cout << "1: Subject Required Basic Test                         課題書要求の基本テスト" << std::endl;
		std::cout << "2: Virtual不足問題の実証                              Virtual polymorphism failure" << std::endl;
		std::cout << "3: 浅いコピー問題の実証 (WrongDog)                    Shallow copy problem" << std::endl;
		std::cout << "0: Exit                                               終了" << std::endl;
		std::cout << "選択してください: ";

		if (!(std::cin >> choice)) {
			std::cout << "⚠️ 無効な入力です！数字を入力してください。" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		try {
			switch (choice) {
				case 1:
					testSubjectRequiredBasic();
					break;
				case 2:
					testVirtualPolymorphismProblem();
					break;
				case 3:
					testShallowCopyProblem();
					break;
				case 0:
					running = false;
					break;
				default:
					std::cout << "無効な選択です。もう一度試してください。" << std::endl;
			}
		} catch (const std::exception &e) {
			std::cout << "⚠️ Exception caught: " << e.what() << std::endl;
		}
	}

	return 0;
}

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

void testVirtualPolymorphismProblem() {
	std::cout << "\033[31m=== 2: Virtual不足問題の実証 ===\033[0m" << std::endl;
	std::cout << "Wrong系クラスにはvirtualキーワードがありません！\n" << std::endl;

	std::cout << "----- ✅ 正常なポリモーフィズム (Animal系 - virtual使用) -----" << std::endl;
	{
		std::cout << "Animal* animal = new Dog();" << std::endl;
		Animal* animal = new Dog();
		std::cout << "animal->makeSound(); // virtual -> Dog::makeSound()が呼ばれる" << std::endl;
		animal->makeSound();
		delete animal;
		std::cout << "✅ 期待通り：Dogの鳴き声\n" << std::endl;
	}

	std::cout << "----- 🔴 問題のあるポリモーフィズム (WrongAnimal系 - virtual未使用) -----" << std::endl;
	{
		std::cout << "WrongAnimal* wrongAnimal = new WrongCat();" << std::endl;
		WrongAnimal* wrongAnimal = new WrongCat();
		std::cout << "wrongAnimal->makeSound(); // NOT virtual -> WrongAnimal::makeSound()が呼ばれる" << std::endl;
		wrongAnimal->makeSound();
		delete wrongAnimal;  // ⚠️ メモリリークも発生
		std::cout << "❌ 問題：WrongAnimalの鳴き声（WrongCatではない）\n" << std::endl;
	}

	{
		std::cout << "WrongAnimal* wrongAnimal = new WrongDog();" << std::endl;
		WrongAnimal* wrongAnimal = new WrongDog();
		std::cout << "wrongAnimal->makeSound(); // NOT virtual -> WrongAnimal::makeSound()が呼ばれる" << std::endl;
		wrongAnimal->makeSound();
		delete wrongAnimal;  // ⚠️ メモリリークも発生
		std::cout << "❌ 問題：WrongAnimalの鳴き声（WrongDogではない）\n" << std::endl;
	}

	std::cout << "📚 学習ポイント:" << std::endl;
	std::cout << "・virtualなしではベースクラスのメソッドが呼ばれる" << std::endl;
	std::cout << "・ポリモーフィズムが機能しない" << std::endl;
	std::cout << "・virtual destructorなしでメモリリークも発生" << std::endl;
}

void testShallowCopyProblem() {
	std::cout << "\033[31m=== 3: 浅いコピー問題の実証 (WrongDog) ===\033[0m" << std::endl;
	std::cout << "WrongDogは意図的に浅いコピー実装になっています！\n" << std::endl;

	std::cout << "----- ✅ 正常なDeep Copy (Cat) -----" << std::endl;
	{
		Cat cat1;
		cat1.getBrain().setIdea(0, "Original cat idea");
		
		std::cout << "Cat1 brain address: " << &cat1.getBrain() << std::endl;
		
		Cat cat2(cat1);  // Deep copy
		std::cout << "Cat2 brain address: " << &cat2.getBrain() << std::endl;
		
		if (&cat1.getBrain() != &cat2.getBrain()) {
			std::cout << "✅ Deep copy: 異なるBrainオブジェクト" << std::endl;
		}
		
		cat2.getBrain().setIdea(0, "Modified by cat2");
		std::cout << "Cat1 idea[0]: \"" << cat1.getBrain().getIdea(0) << "\"" << std::endl;
		std::cout << "Cat2 idea[0]: \"" << cat2.getBrain().getIdea(0) << "\"" << std::endl;
		std::cout << "✅ 独立したBrain：お互いに影響なし\n" << std::endl;
	}

	std::cout << "----- 🔴 問題のあるShallow Copy (WrongDog) -----" << std::endl;
	{
		WrongDog dog1;
		dog1.getBrain().setIdea(0, "Original dog idea");
		
		std::cout << "WrongDog1 brain address: " << &dog1.getBrain() << std::endl;
		
		WrongDog dog2(dog1);  // ⚠️ Shallow copy!
		std::cout << "WrongDog2 brain address: " << &dog2.getBrain() << std::endl;
		
		if (&dog1.getBrain() == &dog2.getBrain()) {
			std::cout << "❌ Shallow copy: 同じBrainオブジェクトを共有！" << std::endl;
		}
		
		dog2.getBrain().setIdea(0, "Modified by dog2");
		std::cout << "WrongDog1 idea[0]: \"" << dog1.getBrain().getIdea(0) << "\"" << std::endl;
		std::cout << "WrongDog2 idea[0]: \"" << dog2.getBrain().getIdea(0) << "\"" << std::endl;
		std::cout << "❌ 危険：dog1のideaもdog2によって変更された！" << std::endl;
		
		std::cout << "\n🚨 この後、スコープを出るときにdouble deleteが発生する可能性があります..." << std::endl;
		std::cout << "dog1とdog2の両方が同じbrainポインタを削除しようとします！" << std::endl;
	}
	// ここでdog1とdog2が破棄される際、同じbrainを2回deleteしようとして
	// double deleteエラーが発生する可能性があります

	std::cout << "\n📚 学習ポイント:" << std::endl;
	std::cout << "・浅いコピーでは複数オブジェクトが同じリソースを共有" << std::endl;
	std::cout << "・一方の変更が他方に影響する" << std::endl;
	std::cout << "・double deleteエラーのリスク" << std::endl;
	std::cout << "・課題書要求：「A copy of a Dog or a Cat mustn't be shallow」" << std::endl;
}