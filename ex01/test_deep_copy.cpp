/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_deep_copy.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 02:56:04 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/21 02:56:11 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "AnsiColor.hpp"
#include "tests.hpp"

void testDeepCopy() {
	std::cout << "\033[32m=== 2: Testing Deep Copy (Copy Constructor) ===\033[0m" << std::endl;

	std::cout << "\n----- Testing Dog Deep Copy -----" << std::endl;
	{
		Dog originalDog;
		std::cout << BOLD_GREEN_COLOR << "Executing: originalDog.getBrain()->setIdea(0, \"Chase squirrels\");" << RESET_COLOR << std::endl;
		originalDog.getBrain()->setIdea(0, "Chase squirrels");
		std::cout << BOLD_GREEN_COLOR << "Executing: originalDog.getBrain()->setIdea(1, \"Protect house\");" << RESET_COLOR << std::endl;
		originalDog.getBrain()->setIdea(1, "Protect house");
		std::cout << BOLD_GREEN_COLOR << "Executing: originalDog.getBrain()->setIdea(2, \"Bark at mailman\");" << RESET_COLOR << std::endl;
		originalDog.getBrain()->setIdea(2, "Bark at mailman");

		std::cout << "\nOriginal dog's brain address: " << originalDog.getBrain() << std::endl;
		std::cout << "Original dog ideas:" << std::endl;
		originalDog.getBrain()->printIdeas();

		std::cout << "\n--- Creating copy using copy constructor ---" << std::endl;
		std::cout << BOLD_GREEN_COLOR << "Executing: Dog copiedDog = originalDog;" << RESET_COLOR << std::endl;
		Dog copiedDog = originalDog;  // Copy constructor

		std::cout << "\nCopied dog's brain address: " << copiedDog.getBrain() << std::endl;
		std::cout << "Copied dog ideas (should be same content, different address):" << std::endl;
		copiedDog.getBrain()->printIdeas();

		std::cout << "\n--- Verifying deep copy by modifying original ---" << std::endl;
		std::cout << BOLD_GREEN_COLOR << "Executing: originalDog.getBrain()->setIdea(0, \"Sleep all day\");" << RESET_COLOR << std::endl;
		originalDog.getBrain()->setIdea(0, "Sleep all day");
		std::cout << BOLD_GREEN_COLOR << "Executing: originalDog.getBrain()->setIdea(3, \"Dream about food\");" << RESET_COLOR << std::endl;
		originalDog.getBrain()->setIdea(3, "Dream about food");

		std::cout << "\nAfter modifying original:" << std::endl;
		std::cout << "Original dog ideas (modified):" << std::endl;
		originalDog.getBrain()->printIdeas();

		std::cout << "Copied dog ideas (should be unchanged - proof of deep copy):" << std::endl;
		copiedDog.getBrain()->printIdeas();

		std::cout << "\n✅ Deep copy verified: Different brain addresses, independent content" << std::endl;
	}

	std::cout << "\n----- Testing Cat Deep Copy -----" << std::endl;
	{
		Cat originalCat;
		std::cout << BOLD_GREEN_COLOR << "Executing: originalCat.getBrain()->setIdea(0, \"Hunt mice\");" << RESET_COLOR << std::endl;
		originalCat.getBrain()->setIdea(0, "Hunt mice");
		std::cout << BOLD_GREEN_COLOR << "Executing: originalCat.getBrain()->setIdea(1, \"Nap in sunlight\");" << RESET_COLOR << std::endl;
		originalCat.getBrain()->setIdea(1, "Nap in sunlight");

		std::cout << "\nOriginal cat's brain address: " << originalCat.getBrain() << std::endl;
		std::cout << "Original cat ideas:" << std::endl;
		originalCat.getBrain()->printIdeas();

		std::cout << BOLD_GREEN_COLOR << "Executing: Cat copiedCat = originalCat;" << RESET_COLOR << std::endl;
		Cat copiedCat = originalCat;  // Copy constructor

		std::cout << "\nCopied cat's brain address: " << copiedCat.getBrain() << std::endl;

		// Modify original to prove deep copy
		std::cout << BOLD_GREEN_COLOR << "Executing: originalCat.getBrain()->setIdea(0, \"Knock things off table\");" << RESET_COLOR << std::endl;
		originalCat.getBrain()->setIdea(0, "Knock things off table");

		std::cout << "\nAfter modifying original cat:" << std::endl;
		std::cout << "Original cat ideas (modified):" << std::endl;
		originalCat.getBrain()->printIdeas();

		std::cout << "Copied cat ideas (should be unchanged - proof of deep copy):" << std::endl;
		copiedCat.getBrain()->printIdeas();
	}
}
