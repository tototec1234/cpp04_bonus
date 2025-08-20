/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment_exception_demo.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:43:06 by toruinoue         #+#    #+#             */
/*   Updated: 2025/08/20 14:46:52 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "AnsiColor.hpp"
#include <iostream>

void demonstrateAssignmentOperatorException() {
	std::cout << "\n🎯 === 代入演算子での例外処理デモ ===" << std::endl;

	// Step 1: 正常な2つのCatオブジェクトを作成
	std::cout << "\n📝 Step 1: 2つのCatオブジェクト作成" << std::endl;
	Cat cat1;
	Cat cat2;

	// cat1にideasを設定
	cat1.getBrain()->setIdea(0, "Cat1's original idea");
	cat1.getBrain()->setIdea(1, "Cat1's second idea");

	cat2.getBrain()->setIdea(0, "Cat2's original idea");

	std::cout << "\n📊 代入前の状態:" << std::endl;
	std::cout << "cat1.brain address: " << cat1.getBrain() << std::endl;
	std::cout << "cat1 idea[0]: \"" << cat1.getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "cat2.brain address: " << cat2.getBrain() << std::endl;
	std::cout << "cat2 idea[0]: \"" << cat2.getBrain()->getIdea(0) << "\"" << std::endl;

	// Step 2: 代入演算子実行（通常は成功）
	std::cout << "\n⚡ Step 2: 代入演算子実行 (cat2 = cat1)" << std::endl;

	try {
		std::cout << "🔄 代入演算子を実行中..." << std::endl;

		cat2 = cat1;  // ← 代入演算子実行

		std::cout << "✅ 代入演算子が正常完了しました！" << std::endl;

		std::cout << "\n📊 代入後の状態:" << std::endl;
		std::cout << "cat1.brain address: " << cat1.getBrain() << std::endl;
		std::cout << "cat2.brain address: " << cat2.getBrain() << " (新しいアドレス)" << std::endl;
		std::cout << "cat2 idea[0]: \"" << cat2.getBrain()->getIdea(0) << "\" (cat1からコピー)" << std::endl;

	} catch (const std::bad_alloc &e) {
		std::cout << "\n🚨 代入演算子でstd::bad_alloc例外発生！" << std::endl;
		std::cout << "❌ new Brain(*other.brain) が失敗しました" << std::endl;
		std::cout << "📋 例外メッセージ: " << e.what() << std::endl;

		std::cout << "\n🛡️ 例外後の状態確認:" << std::endl;
		std::cout << "cat2.brain address: " << cat2.getBrain() << " (元のまま)" << std::endl;
		std::cout << "cat2 idea[0]: \"" << cat2.getBrain()->getIdea(0) << "\" (変更されていない)" << std::endl;

		std::cout << "\n✅ 重要なポイント:" << std::endl;
		std::cout << "・cat2のbrainポインタは有効なまま" << std::endl;
		std::cout << "・cat2の元のデータは保持されている" << std::endl;
		std::cout << "・メモリリークは発生していない" << std::endl;
		std::cout << "・オブジェクトは使用可能な状態" << std::endl;

	} catch (const std::exception &e) {
		std::cout << "\n🚨 その他の例外: " << e.what() << std::endl;
	}

	std::cout << "\n✨ 代入演算子処理完了後:" << std::endl;
	std::cout << "両方のCatオブジェクトは正常に使用可能" << std::endl;

	// 動作確認
	std::cout << "\n🧪 動作確認:" << std::endl;
	std::cout << "cat1.makeSound(): ";
	cat1.makeSound();
	std::cout << "cat2.makeSound(): ";
	cat2.makeSound();
}

int main() {
	std::cout << "🎯 === Assignment Operator Exception Safety Demo ===" << std::endl;

	demonstrateAssignmentOperatorException();

	std::cout << "\n🏁 プログラム正常終了" << std::endl;
	return 0;
}

/*
コンパイル・実行:
cd /Users/toruinoue/CPP/0817cpp04/ex01 && c++ -Wall -Wextra -Werror -std=c++98 assignment_exception_demo.cpp Cat.cpp Dog.cpp Animal.cpp Brain.cpp WrongAnimal.cpp WrongCat.cpp WrongDog.cpp -o assignment_exception_demo && ./assignment_exception_demo
*/
