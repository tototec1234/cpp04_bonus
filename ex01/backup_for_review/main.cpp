/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/21 00:53:03 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AnsiColor.hpp"
#include "tests.hpp"
#include <iostream>
#include <limits>

int main() {
	int choice;
	bool running = true;

	while (running) {
		std::cout << YELLOW_COLOR << "\n=== CPP04 Exercise 01: I don’t want to set the world on fire. ===" << RESET_COLOR << std::endl;
		
		std::cout << "1: Subject Required Basic Test                        課題書要求の基本テスト" << std::endl;
		std::cout << "2: Deep Copy Test                                     ディープコピーテスト" << std::endl;
		std::cout << "3: Virtual欠如問題の実証                              Virtual polymorphism failure" << std::endl;
		std::cout << "4: 浅いコピー問題の実証 (WrongDog)                    Shallow copy problem" << std::endl;
		// std::cout << "5: Wrong系浅いコピー詳細実証                          Wrong shallow copy detailed" << std::endl;	// 旧メニュー
		// std::cout << "5: Wrong系包括的設計欠陥実証                          Wrong comprehensive design flaws" << std::endl;	// 新メニュー：包括的実証
		std::cout << "6: Assignment Operator Test                           代入演算子テスト" << std::endl;
		// std::cout << "7: Exception Handling Test                            例外処理テスト" << std::endl;
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
					testDeepCopy();
					break;
				case 3:
					testVirtualPolymorphismProblem();
					break;
				case 4:
					testShallowCopyProblem();
					break;
				// case 5:
					// testWrongShallowCopy();	//
					// testWrongComprehensiveDemo();
					break;
				case 6:
					testAssignmentOperator();
					break;
				case 7:
					testExceptionHandling();
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

/*
valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./brain_test

valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./brain_test > VALGLIND.log 2>&1

*/