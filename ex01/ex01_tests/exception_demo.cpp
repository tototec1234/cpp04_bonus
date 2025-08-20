/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_demo.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:48:09 by toruinoue         #+#    #+#             */
/*   Updated: 2025/08/20 14:48:15 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

cd /Users/toruinoue/CPP/0817cpp04/ex01 && c++ -Wall -Wextra -Werror -std=c++98 exception_demo.cpp Cat.cpp Dog.cpp Animal.cpp Brain.cpp WrongAnimal.cpp WrongCat.cpp WrongDog.cpp -o exception_demo

*/
#include "Cat.hpp"
#include "AnsiColor.hpp"
#include <iostream>
#include <stdexcept>

void demonstrateExceptionFlow() {
	std::cout << "\n🔍 === new失敗時の例外処理デモ ===" << std::endl;

	Cat cat1;
	Cat cat2;

	// cat1にideasを設定
	cat1.getBrain()->setIdea(0, "Original idea");

	std::cout << "\n📝 代入操作前の状態:" << std::endl;
	std::cout << "cat1 brain address: " << cat1.getBrain() << std::endl;
	std::cout << "cat2 brain address: " << cat2.getBrain() << std::endl;

	std::cout << "\n⚡ 代入操作開始 (cat2 = cat1)..." << std::endl;

	try {
		std::cout << "🔄 try ブロックに入りました" << std::endl;

		// 通常の代入操作（通常は成功）
		cat2 = cat1;

		std::cout << "✅ 代入操作が成功しました！" << std::endl;
		std::cout << "cat2 brain address: " << cat2.getBrain() << std::endl;
		std::cout << "cat2 idea[0]: \"" << cat2.getBrain()->getIdea(0) << "\"" << std::endl;

	} catch (const std::bad_alloc &e) {
		std::cout << "🚨 catch(std::bad_alloc) ブロックに入りました！" << std::endl;
		std::cout << "❌ メモリ割り当て失敗: " << e.what() << std::endl;
		std::cout << "📊 cat2の状態は変更されていません" << std::endl;
		std::cout << "cat2 brain address: " << cat2.getBrain() << " (変更なし)" << std::endl;

	} catch (const std::exception &e) {
		std::cout << "🚨 catch(std::exception) ブロックに入りました！" << std::endl;
		std::cout << "❌ その他の例外: " << e.what() << std::endl;
	}

	std::cout << "\n✨ 例外処理完了、プログラム継続中..." << std::endl;
}

void demonstrateMemoryExhaustion() {
	std::cout << "\n💥 === メモリ不足シミュレーション ===" << std::endl;

	try {
		std::cout << "🔄 大量メモリ割り当て試行中..." << std::endl;

		// 意図的に巨大なメモリを要求してbad_allocを発生させる
		// 注意: 実際のシステムでは危険なので、適度なサイズに調整
		size_t huge_size = static_cast<size_t>(-1) / 2;  // 最大サイズの半分
		char* huge_memory = new char[huge_size];

		std::cout << "✅ なぜか成功してしまいました（予想外）" << std::endl;
		delete[] huge_memory;

	} catch (const std::bad_alloc &e) {
		std::cout << "🚨 expected: std::bad_alloc例外をキャッチしました！" << std::endl;
		std::cout << "❌ メモリ不足: " << e.what() << std::endl;
		std::cout << "🛡️ プログラムはクラッシュせず、安全に継続します" << std::endl;
	}
}

int main() {
	std::cout << "🎯 === Exception Handling Flow Demo ===" << std::endl;

	demonstrateExceptionFlow();
	demonstrateMemoryExhaustion();

	std::cout << "\n🎉 すべてのテスト完了！プログラム正常終了" << std::endl;
	return 0;
}
