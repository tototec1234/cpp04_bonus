/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_wrong_copy.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:21:16 by toruinoue         #+#    #+#             */
/*   Updated: 2025/08/20 22:11:01 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"
#include "WrongCat.hpp"
#include "AnsiColor.hpp"
#include "tests.hpp"

void testWrongShallowCopy() {
	std::cout << "\033[31m=== 4: Wrong系の浅いコピー詳細実証 ===\033[0m" << std::endl;
	std::cout << "Deep copyテストと同じ操作をWrong系で行い、浅いコピーの危険性を実証します\n" << std::endl;

	std::cout << "\n----- Testing WrongDog Shallow Copy (危険な実装) -----" << std::endl;
	{
		WrongDog originalDog;
		std::cout << BOLD_GREEN_COLOR << "Executing: originalDog.getBrain().setIdea(0, \"Chase squirrels\");" << RESET_COLOR << std::endl;
		originalDog.getBrain().setIdea(0, "Chase squirrels");
		std::cout << BOLD_GREEN_COLOR << "Executing: originalDog.getBrain().setIdea(1, \"Protect house\");" << RESET_COLOR << std::endl;
		originalDog.getBrain().setIdea(1, "Protect house");
		std::cout << BOLD_GREEN_COLOR << "Executing: originalDog.getBrain().setIdea(2, \"Bark at mailman\");" << RESET_COLOR << std::endl;
		originalDog.getBrain().setIdea(2, "Bark at mailman");

		std::cout << "\nOriginal dog's brain address: " << &originalDog.getBrain() << std::endl;
		std::cout << "Original dog ideas:" << std::endl;
		originalDog.getBrain().printIdeas();

		std::cout << "\n--- Creating copy using copy constructor ---" << std::endl;
		std::cout << BOLD_GREEN_COLOR << "Executing: WrongDog copiedDog = originalDog;  // CAUTION SHALLOW COPY!" << RESET_COLOR << std::endl;
		WrongDog copiedDog = originalDog;  // CAUTION Shallow copy!

		std::cout << "\nCopied dog's brain address: " << &copiedDog.getBrain() << std::endl;
		
		if (&originalDog.getBrain() == &copiedDog.getBrain()) {
			std::cout << "❌ SHALLOW COPY確認: 同じBrainオブジェクトを共有！" << std::endl;
		}

		std::cout << "Copied dog ideas (same content, SAME address - 危険!):" << std::endl;
		copiedDog.getBrain().printIdeas();

		std::cout << "\n--- 浅いコピーの危険性実証: originalを変更 ---" << std::endl;
		std::cout << BOLD_GREEN_COLOR << "Executing: originalDog.getBrain().setIdea(0, \"Sleep all day\");" << RESET_COLOR << std::endl;
		originalDog.getBrain().setIdea(0, "Sleep all day");
		std::cout << BOLD_GREEN_COLOR << "Executing: originalDog.getBrain().setIdea(3, \"Dream about food\");" << RESET_COLOR << std::endl;
		originalDog.getBrain().setIdea(3, "Dream about food");

		std::cout << "\nAfter modifying original:" << std::endl;
		std::cout << "Original dog ideas (modified):" << std::endl;
		originalDog.getBrain().printIdeas();

		std::cout << "❌ Copied dog ideas (ALSO CHANGED - 危険な浅いコピー！):" << std::endl;
		copiedDog.getBrain().printIdeas();

		std::cout << "\n🚨 CRITICAL PROBLEM: 浅いコピーのため両方が同じBrainを参照" << std::endl;
		std::cout << "・originalDogの変更がcopiedDogにも影響" << std::endl;
		std::cout << "・独立したオブジェクトではない" << std::endl;
		std::cout << "・スコープを出るときにdouble deleteの危険性" << std::endl;
	}

	std::cout << "\n----- Testing WrongCat Deep Copy (比較用: 正常な実装) -----" << std::endl;
	{
		WrongCat originalCat;
		std::cout << BOLD_GREEN_COLOR << "Executing: originalCat.getBrain().setIdea(0, \"Hunt mice\");" << RESET_COLOR << std::endl;
		originalCat.getBrain().setIdea(0, "Hunt mice");
		std::cout << BOLD_GREEN_COLOR << "Executing: originalCat.getBrain().setIdea(1, \"Nap in sunlight\");" << RESET_COLOR << std::endl;
		originalCat.getBrain().setIdea(1, "Nap in sunlight");

		std::cout << "\nOriginal cat's brain address: " << &originalCat.getBrain() << std::endl;
		std::cout << "Original cat ideas:" << std::endl;
		originalCat.getBrain().printIdeas();

		std::cout << BOLD_GREEN_COLOR << "Executing: WrongCat copiedCat = originalCat;  // Deep copy (normal)" << RESET_COLOR << std::endl;
		WrongCat copiedCat = originalCat;  // Deep copy

		std::cout << "\nCopied cat's brain address: " << &copiedCat.getBrain() << std::endl;
		
		if (&originalCat.getBrain() != &copiedCat.getBrain()) {
			std::cout << "✅ Deep copy確認: 異なるBrainオブジェクト" << std::endl;
		}

		// Modify original to prove deep copy
		std::cout << BOLD_GREEN_COLOR << "Executing: originalCat.getBrain().setIdea(0, \"Knock things off table\");" << RESET_COLOR << std::endl;
		originalCat.getBrain().setIdea(0, "Knock things off table");

		std::cout << "\nAfter modifying original cat:" << std::endl;
		std::cout << "Original cat ideas (modified):" << std::endl;
		originalCat.getBrain().printIdeas();

		std::cout << "✅ Copied cat ideas (UNCHANGED - 正常なdeep copy):" << std::endl;
		copiedCat.getBrain().printIdeas();
	}

	std::cout << "\n📚 比較まとめ:" << std::endl;
	std::cout << "🔴 WrongDog: SHALLOW COPY" << std::endl;
	std::cout << "   ・同じBrainアドレス → double delete危険性" << std::endl;
	std::cout << "   ・一方の変更が他方に影響 → 予期しない動作" << std::endl;
	std::cout << "   ・課題書違反: \"A copy mustn't be shallow\"" << std::endl;
	std::cout << "\n✅ WrongCat: DEEP COPY" << std::endl;
	std::cout << "   ・異なるBrainアドレス → 安全なメモリ管理" << std::endl;
	std::cout << "   ・独立したオブジェクト → 予期可能な動作" << std::endl;
	std::cout << "   ・課題書準拠: \"A copy mustn't be shallow\"" << std::endl;
}
