/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_cat_exception_demo.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:49:32 by toruinoue         #+#    #+#             */
/*   Updated: 2025/08/20 14:49:37 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

void demonstrateConstructorVsAssignmentException() {
	std::cout << "\n🎯 === 実際のCatクラスでの例外処理比較 ===" << std::endl;

	std::cout << "\n📝 ケース1: デフォルトコンストラクタでの例外" << std::endl;
	std::cout << "Cat cat; で new Brain() が失敗した場合:" << std::endl;

	try {
		std::cout << "🔄 Cat cat; を実行..." << std::endl;
		Cat cat;  // 通常は成功

		std::cout << "✅ 正常に作成されました" << std::endl;
		std::cout << "cat.brain address: " << cat.getBrain() << std::endl;

		std::cout << "\n🚨 もし new Brain() が失敗していたら:" << std::endl;
		std::cout << "・Animal('Cat') は実行される" << std::endl;
		std::cout << "・Cat default constructor が開始される" << std::endl;
		std::cout << "・this->brain = new Brain() で例外発生" << std::endl;
		std::cout << "・Cat destructor は呼ばれない" << std::endl;
		std::cout << "・Animal destructor は自動実行される" << std::endl;
		std::cout << "・変数 cat は存在しない" << std::endl;

	} catch (const std::bad_alloc &e) {
		std::cout << "🚨 Constructor exception: " << e.what() << std::endl;
	}

	std::cout << "\n📝 ケース2: コピーコンストラクタでの例外" << std::endl;

	try {
		Cat cat1;
		cat1.getBrain()->setIdea(0, "Original idea");

		std::cout << "\n🔄 Cat cat2(cat1); を実行..." << std::endl;
		Cat cat2(cat1);  // 通常は成功

		std::cout << "✅ 正常にコピーされました" << std::endl;
		std::cout << "cat1.brain: " << cat1.getBrain() << std::endl;
		std::cout << "cat2.brain: " << cat2.getBrain() << " (異なるアドレス)" << std::endl;
		std::cout << "cat2 idea[0]: \"" << cat2.getBrain()->getIdea(0) << "\"" << std::endl;

		std::cout << "\n🚨 もし new Brain(*other.brain) が失敗していたら:" << std::endl;
		std::cout << "・Animal(other) は実行される" << std::endl;
		std::cout << "・Cat copy constructor が開始される" << std::endl;
		std::cout << "・this->brain = new Brain(*other.brain) で例外発生" << std::endl;
		std::cout << "・Cat destructor は呼ばれない" << std::endl;
		std::cout << "・Animal destructor は自動実行される" << std::endl;
		std::cout << "・変数 cat2 は存在しない" << std::endl;
		std::cout << "・cat1 は影響を受けない" << std::endl;

	} catch (const std::bad_alloc &e) {
		std::cout << "🚨 Copy constructor exception: " << e.what() << std::endl;
	}

	std::cout << "\n📝 ケース3: 代入演算子での例外（比較用）" << std::endl;

	try {
		Cat cat1, cat2;
		cat1.getBrain()->setIdea(0, "Assignment test");
		cat2.getBrain()->setIdea(0, "Original cat2 data");

		std::cout << "\n代入前:" << std::endl;
		std::cout << "cat2.brain: " << cat2.getBrain() << std::endl;
		std::cout << "cat2 idea[0]: \"" << cat2.getBrain()->getIdea(0) << "\"" << std::endl;

		std::cout << "\n🔄 cat2 = cat1; を実行..." << std::endl;
		cat2 = cat1;  // 通常は成功

		std::cout << "✅ 正常に代入されました" << std::endl;
		std::cout << "cat2.brain: " << cat2.getBrain() << " (新しいアドレス)" << std::endl;
		std::cout << "cat2 idea[0]: \"" << cat2.getBrain()->getIdea(0) << "\"" << std::endl;

		std::cout << "\n🚨 もし new Brain(*other.brain) が失敗していたら:" << std::endl;
		std::cout << "・Animal::operator=(other) は実行される" << std::endl;
		std::cout << "・new Brain(*other.brain) で例外発生" << std::endl;
		std::cout << "・delete this->brain は実行されない" << std::endl;
		std::cout << "・cat2.brain は元のアドレスのまま" << std::endl;
		std::cout << "・cat2 は元のデータを保持" << std::endl;
		std::cout << "・cat2 オブジェクトは使用可能" << std::endl;

	} catch (const std::bad_alloc &e) {
		std::cout << "🚨 Assignment operator exception: " << e.what() << std::endl;
	}
}

int main() {
	std::cout << "🎯 === Real Cat Class Exception Comparison ===" << std::endl;

	demonstrateConstructorVsAssignmentException();

	std::cout << "\n🏁 プログラム正常終了" << std::endl;
	return 0;
}

/*
コンパイル・実行:
cd /Users/toruinoue/CPP/0817cpp04/ex01 && c++ -Wall -Wextra -Werror -std=c++98 real_cat_exception_demo.cpp Cat.cpp Dog.cpp Animal.cpp Brain.cpp WrongAnimal.cpp WrongCat.cpp WrongDog.cpp -o real_cat_exception_demo && ./real_cat_exception_demo
*/
