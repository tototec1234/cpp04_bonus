/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_shallow_copy.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 02:58:19 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/21 02:58:25 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "WrongDog.hpp"
#include "AnsiColor.hpp"
#include "tests.hpp"

void testShallowCopyProblem() {
	std::cout << "\033[31m=== 4: 浅いコピー問題の実証 (WrongDog) ===\033[0m" << std::endl;
	std::cout << "WrongDogは意図的に浅いコピー実装になっています！\n" << std::endl;

	std::cout << "----- ✅ 正常なDeep Copy (Cat) -----" << std::endl;
	{
		std::cout << BOLD_GREEN_COLOR << "Executing: Cat cat1;" << RESET_COLOR << std::endl;
		Cat cat1;
		std::cout << std::endl;

		std::cout << BOLD_GREEN_COLOR << "Executing: cat1.getBrain()->setIdea(0, \"Original cat idea\");" << RESET_COLOR << std::endl;
		cat1.getBrain()->setIdea(0, "Original cat idea");
		std::cout << std::endl;

		std::cout << "Cat1 brain address: " << cat1.getBrain() << std::endl;
		std::cout << std::endl;

		std::cout << BOLD_GREEN_COLOR << "Executing: Cat cat2(cat1);  // Deep copy" << RESET_COLOR << std::endl;
		Cat cat2(cat1);  // Deep copy
		std::cout << std::endl;

		std::cout << "Cat2 brain address: " << cat2.getBrain() << std::endl;
		if (cat1.getBrain() != cat2.getBrain()) {
			std::cout << "✅ Deep copy: 異なるBrainオブジェクト" << std::endl;
		}
		std::cout << std::endl;
		
		std::cout << BOLD_GREEN_COLOR << "Executing: cat2.getBrain()->setIdea(0, \"Modified by cat2\");" << RESET_COLOR << std::endl;
		cat2.getBrain()->setIdea(0, "Modified by cat2");
		std::cout << "Cat1 idea[0]: \"" << cat1.getBrain()->getIdea(0) << "\"" << std::endl;
		std::cout << "Cat2 idea[0]: \"" << cat2.getBrain()->getIdea(0) << "\"" << std::endl;
		std::cout << "✅ 独立したBrain：お互いに影響なし\n" << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "----- 🔴 問題のあるShallow Copy (WrongDog) -----" << std::endl;
	{
		std::cout << BOLD_GREEN_COLOR << "Executing: WrongDog dog1;" << RESET_COLOR << std::endl;
		WrongDog dog1;
		std::cout << std::endl;

		std::cout << BOLD_GREEN_COLOR << "Executing: dog1.getBrain().setIdea(0, \"Original dog idea\");" << RESET_COLOR << std::endl;
		dog1.getBrain().setIdea(0, "Original dog idea");
		std::cout << std::endl;

		std::cout << "WrongDog1 brain address: " << &dog1.getBrain() << std::endl;
		std::cout << std::endl;

		std::cout << BOLD_GREEN_COLOR << "Executing: WrongDog dog2(dog1);  // CAUTION Shallow copy!" << RESET_COLOR << std::endl;
		WrongDog dog2(dog1);  // CAUTION Shallow copy!
		std::cout << std::endl;

		std::cout << "WrongDog2 brain address: " << &dog2.getBrain() << std::endl;
		
		if (&dog1.getBrain() == &dog2.getBrain()) {
			std::cout << "❌ Shallow copy: 同じBrainオブジェクトを共有！" << std::endl;
		}
		std::cout << std::endl;
		
		std::cout << BOLD_GREEN_COLOR << "Executing: dog2.getBrain().setIdea(0, \"Modified by dog2\");" << RESET_COLOR << std::endl;
		dog2.getBrain().setIdea(0, "Modified by dog2");
		std::cout << "WrongDog1 idea[0]: \"" << dog1.getBrain().getIdea(0) << "\"" << std::endl;
		std::cout << "WrongDog2 idea[0]: \"" << dog2.getBrain().getIdea(0) << "\"" << std::endl;
		std::cout << "❌ 危険：dog1のideaもdog2によって変更された！" << std::endl;
		
		std::cout << "\n🚨 この後、スコープを出るときにdouble deleteが発生する可能性があります..." << std::endl;
		std::cout << "dog1とdog2の両方が同じbrainポインタを削除しようとします！" << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;

	// When dog1 and dog2 are destroyed here, they try to delete the same brain twice
	// There is a possibility of double delete error

	std::cout << "\n📚 学習ポイント:" << std::endl;
	std::cout << "・浅いコピーでは複数オブジェクトが同じリソースを共有" << std::endl;
	std::cout << "・一方の変更が他方に影響する" << std::endl;
	std::cout << "・double deleteエラーのリスク" << std::endl;
	std::cout << "・課題書要求：「A copy of a Dog or a Cat mustn't be shallow」" << std::endl;
}
