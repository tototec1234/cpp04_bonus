/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_wrong_comprehensive_demo.cpp               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:21:16 by toruinoue         #+#    #+#             */
/*   Updated: 2025/08/20 22:11:01 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "AnsiColor.hpp"
#include "tests.hpp"

void testWrongComprehensiveDemo() {
	std::cout << "\033[31m=== 4: Wrong系包括的設計欠陥実証 ===\033[0m" << std::endl;
	std::cout << "Wrong系の複数の設計問題（浅いコピー・Virtual欠如）を包括的に実証します\n" << std::endl;

	std::cout << "\n----- Testing WrongDog Shallow Copy (危険な実装) -----" << std::endl;
	{
		std::cout << BOLD_GREEN_COLOR << "Executing: WrongDog originalDog;" << RESET_COLOR << std::endl;
		WrongDog originalDog;
		std::cout << std::endl;

		std::cout << BOLD_GREEN_COLOR << "Executing: originalDog.getBrain().setIdea(0, \"Chase squirrels\");" << RESET_COLOR << std::endl;
		originalDog.getBrain().setIdea(0, "Chase squirrels");
		std::cout << std::endl;

		std::cout << BOLD_GREEN_COLOR << "Executing: originalDog.getBrain().setIdea(1, \"Protect house\");" << RESET_COLOR << std::endl;
		originalDog.getBrain().setIdea(1, "Protect house");
		std::cout << std::endl;

		std::cout << BOLD_GREEN_COLOR << "Executing: originalDog.getBrain().setIdea(2, \"Bark at mailman\");" << RESET_COLOR << std::endl;
		originalDog.getBrain().setIdea(2, "Bark at mailman");
		std::cout << std::endl;

		std::cout << "\nOriginal dog's brain address: " << &originalDog.getBrain() << std::endl;
		std::cout << "Original dog ideas:" << std::endl;
		originalDog.getBrain().printIdeas();

		std::cout << "\n--- Creating copy using copy constructor ---" << std::endl;
		std::cout << BOLD_GREEN_COLOR << "Executing: WrongDog copiedDog = originalDog;  // CAUTION SHALLOW COPY!" << RESET_COLOR << std::endl;
		WrongDog copiedDog = originalDog;  // CAUTION Shallow copy!
		std::cout << std::endl;

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
		std::cout << std::endl;

		std::cout << "\nAfter modifying original:" << std::endl;
		std::cout << "Original dog ideas (modified):" << std::endl;
		originalDog.getBrain().printIdeas();

		std::cout << "❌ Copied dog ideas (ALSO CHANGED - 危険な浅いコピー！):" << std::endl;
		copiedDog.getBrain().printIdeas();

		std::cout << "\n🚨 CRITICAL PROBLEM: 浅いコピーのため両方が同じBrainを参照" << std::endl;
		std::cout << "・originalDogの変更がcopiedDogにも影響" << std::endl;
		std::cout << "・独立したオブジェクトではない" << std::endl;
		std::cout << "・スコープを出るときにdouble deleteの危険性" << std::endl;

		std::cout << "\n⚠️ 安全対策: レビュー時クラッシュ防止のため以下を実行" << std::endl;
		std::cout << "copiedDog のbrainポインタをNULLに設定してdouble delete回避" << std::endl;
		
        // Safety measure: Set one pointer to NULL to prevent crashes without reviewer consensus
        // This prevents double delete (the inherent danger has already been demonstrated above)
		std::cout << BOLD_GREEN_COLOR << "Executing: copiedDog.nullifyBrainForSafety();  // Set one to NULL (to prevent double delete)" << RESET_COLOR << std::endl;

		copiedDog.nullifyBrainForSafety();  // Set one to NULL (to prevent double delete)
		
		
		std::cout << "✅ Double delete回避完了。実際の危険性は上記で実証済み。" << std::endl;
		std::cout << "📝 レビュアー注記: 実際のdouble deleteクラッシュを見る場合は、" << std::endl;
		std::cout << "   test_wrong_comprehensive_demo.cpp内の" << std::endl;
		std::cout << "   copiedDog.nullifyBrainForSafety(); をコメントアウトしてください。" << std::endl;
	}

	std::cout << "\n----- Testing WrongCat Deep Copy (比較用: 正常な実装) -----" << std::endl;
	{
		std::cout << BOLD_GREEN_COLOR << "Executing: WrongCat originalCat;" << RESET_COLOR << std::endl;
		WrongCat originalCat;
		std::cout << std::endl;

		std::cout << BOLD_GREEN_COLOR << "Executing: originalCat.getBrain().setIdea(0, \"Hunt mice\");" << RESET_COLOR << std::endl;
		originalCat.getBrain().setIdea(0, "Hunt mice");

		std::cout << BOLD_GREEN_COLOR << "Executing: originalCat.getBrain().setIdea(1, \"Nap in sunlight\");" << RESET_COLOR << std::endl;
		originalCat.getBrain().setIdea(1, "Nap in sunlight");

		std::cout << "\nOriginal cat's brain address: " << &originalCat.getBrain() << std::endl;
		std::cout << "Original cat ideas:" << std::endl;
		originalCat.getBrain().printIdeas();

		std::cout << BOLD_GREEN_COLOR << "Executing: WrongCat copiedCat = originalCat;  // Deep copy (normal)" << RESET_COLOR << std::endl;
		WrongCat copiedCat = originalCat;  // Deep copy
		std::cout << std::endl;

		std::cout << "\nCopied cat's brain address: " << &copiedCat.getBrain() << std::endl;
		
		if (&originalCat.getBrain() != &copiedCat.getBrain()) {
			std::cout << "✅ Deep copy確認: 異なるBrainオブジェクト" << std::endl;
		}
		std::cout << std::endl;

		// Modify original to prove deep copy
		std::cout << BOLD_GREEN_COLOR << "Executing: originalCat.getBrain().setIdea(0, \"Knock things off table\");" << RESET_COLOR << std::endl;
		originalCat.getBrain().setIdea(0, "Knock things off table");
		std::cout << std::endl;

		std::cout << "\nAfter modifying original cat:" << std::endl;
		std::cout << "Original cat ideas (modified):" << std::endl;
		originalCat.getBrain().printIdeas();

		std::cout << "✅ Copied cat ideas (UNCHANGED - 正常なdeep copy):" << std::endl;
		copiedCat.getBrain().printIdeas();
	}

	std::cout << "\n📚 コピー実装比較まとめ:" << std::endl;
	std::cout << "🔴 WrongDog: SHALLOW COPY" << std::endl;
	std::cout << "   ・同じBrainアドレス → double delete危険性" << std::endl;
	std::cout << "   ・一方の変更が他方に影響 → 予期しない動作" << std::endl;
	std::cout << "   ・課題書違反: \"A copy mustn't be shallow\"" << std::endl;
	std::cout << "\n✅ WrongCat: DEEP COPY" << std::endl;
	std::cout << "   ・異なるBrainアドレス → 安全なメモリ管理" << std::endl;
	std::cout << "   ・独立したオブジェクト → 予期可能な動作" << std::endl;
	std::cout << "   ・課題書準拠: \"A copy mustn't be shallow\"" << std::endl;

	std::cout << "\n\n=== Virtual Polymorphismとデストラクタ被害の実証 ===" << std::endl;
	std::cout << "Brain書き込み済み状態でのポリモーフィック削除時の被害レベル比較\n" << std::endl;

	std::cout << "----- 🔴 WrongDog: Shallow Copy + Virtual欠如 (最悪ケース) -----" << std::endl;
	{
		std::cout << BOLD_GREEN_COLOR << "Executing: WrongAnimal* wrongAnimal = new WrongDog();" << RESET_COLOR << std::endl;
		WrongAnimal* wrongAnimal = new WrongDog();
		std::cout << std::endl;

		// Cast to access WrongDog specific methods for demonstration
		// Note: dynamic_cast won't work due to non-polymorphic WrongAnimal (no virtual functions)
		WrongDog* wrongDog = static_cast<WrongDog*>(wrongAnimal);
		if (wrongDog) {
			std::cout << BOLD_GREEN_COLOR << "Executing: wrongDog->getBrain().setIdea(0, \"Important dog memory\");" << RESET_COLOR << std::endl;
			wrongDog->getBrain().setIdea(0, "Important dog memory");
			std::cout << std::endl;

			std::cout << "WrongDog brain address: " << &wrongDog->getBrain() << std::endl;
			std::cout << "Stored idea: \"" << wrongDog->getBrain().getIdea(0) << "\"" << std::endl;
		}
		std::cout << std::endl;

		std::cout << "🚨 危険なポリモーフィック削除を実行:" << std::endl;
		std::cout << BOLD_GREEN_COLOR << "Executing: delete wrongAnimal;  // DANGER: 浅いコピー + virtual欠如" << RESET_COLOR << std::endl;
		std::cout << "・WrongAnimalのデストラクタのみ呼ばれる（virtualなし）" << std::endl;
		std::cout << "・WrongDogのBrainが適切に削除されない可能性" << std::endl;
		std::cout << "・メモリリーク + 浅いコピー問題の組み合わせ" << std::endl;
		delete wrongAnimal;  // DANGER: Non-virtual destructor + shallow copy issues
		std::cout << std::endl;
	}

	std::cout << "----- ⚠️ WrongCat: Deep Copy + Virtual欠如 (中程度問題) -----" << std::endl;
	{
		std::cout << BOLD_GREEN_COLOR << "Executing: WrongAnimal* wrongAnimal = new WrongCat();" << RESET_COLOR << std::endl;
		WrongAnimal* wrongAnimal = new WrongCat();
		std::cout << std::endl;

		// Cast to access WrongCat specific methods for demonstration
		// Note: dynamic_cast won't work due to non-polymorphic WrongAnimal (no virtual functions)
		WrongCat* wrongCat = static_cast<WrongCat*>(wrongAnimal);
		if (wrongCat) {
			std::cout << BOLD_GREEN_COLOR << "Executing: wrongCat->getBrain().setIdea(0, \"Important cat memory\");" << RESET_COLOR << std::endl;
			wrongCat->getBrain().setIdea(0, "Important cat memory");
			std::cout << std::endl;

			std::cout << "WrongCat brain address: " << &wrongCat->getBrain() << std::endl;
			std::cout << "Stored idea: \"" << wrongCat->getBrain().getIdea(0) << "\"" << std::endl;
		}
		std::cout << std::endl;

		std::cout << "⚠️ 問題のあるポリモーフィック削除を実行:" << std::endl;
		std::cout << BOLD_GREEN_COLOR << "Executing: delete wrongAnimal;  // WARNING: virtual欠如のみ" << RESET_COLOR << std::endl;
		std::cout << "・WrongAnimalのデストラクタのみ呼ばれる（virtualなし）" << std::endl;
		std::cout << "・WrongCatのBrainは適切に削除されない可能性" << std::endl;
		std::cout << "・ただし、deep copyのためdouble delete問題はなし" << std::endl;
		delete wrongAnimal;  // WARNING: Non-virtual destructor but no shallow copy
		std::cout << std::endl;
	}

	std::cout << "\n🔍 被害レベル分析:" << std::endl;
	std::cout << "🔴 WrongDog (最悪): 浅いコピー + Virtual欠如" << std::endl;
	std::cout << "   → Double delete + メモリリーク + 予期しない動作" << std::endl;
	std::cout << "⚠️ WrongCat (中程度): Deep copy + Virtual欠如" << std::endl;
	std::cout << "   → メモリリークのみ（double delete問題なし）" << std::endl;
	std::cout << "\n💡 教訓: 複数の設計欠陥が組み合わさると被害が指数的に増加" << std::endl;
}
