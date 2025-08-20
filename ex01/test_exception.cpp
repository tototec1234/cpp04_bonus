/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_exception.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:00:00 by toruinoue        #+#    #+#             */
/*   Updated: 2025/01/27 22:00:00 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "AnsiColor.hpp"
#include "tests.hpp"

void testExceptionHandling() {
	std::cout << "\033[32m=== 7: Testing Exception Handling (CPP04 Enhancement) ===\033[0m" << std::endl;

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
