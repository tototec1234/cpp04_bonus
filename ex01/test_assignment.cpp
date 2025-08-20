/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_assignment.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:20:03 by toruinoue         #+#    #+#             */
/*   Updated: 2025/08/21 02:42:04 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "AnsiColor.hpp"
#include "tests.hpp"

void testAssignmentOperator() {
	std::cout << "\033[32m=== 6: Testing Deep Copy (Assignment Operator) ===\033[0m" << std::endl;

	std::cout << "\n----- Testing Dog Assignment Operator -----" << std::endl;
	{
		Dog dog1;
		Dog dog2;

		std::cout << BOLD_GREEN_COLOR << "Executing: dog1.getBrain()->setIdea(0, \"Original dog idea\");" << RESET_COLOR << std::endl;
		dog1.getBrain()->setIdea(0, "Original dog idea");
		std::cout << BOLD_GREEN_COLOR << "Executing: dog1.getBrain()->setIdea(1, \"Another original idea\");" << RESET_COLOR << std::endl;
		dog1.getBrain()->setIdea(1, "Another original idea");

		std::cout << BOLD_GREEN_COLOR << "Executing: dog2.getBrain()->setIdea(0, \"Different dog idea\");" << RESET_COLOR << std::endl;
		dog2.getBrain()->setIdea(0, "Different dog idea");

		std::cout << "\nBefore assignment:" << std::endl;
		std::cout << "Dog1 brain address: " << dog1.getBrain() << std::endl;
		std::cout << "Dog1 ideas:" << std::endl;
		dog1.getBrain()->printIdeas();

		std::cout << "\nDog2 brain address: " << dog2.getBrain() << std::endl;
		std::cout << "Dog2 ideas:" << std::endl;
		dog2.getBrain()->printIdeas();

		std::cout << "\n--- Performing assignment (dog2 = dog1) ---" << std::endl;
		std::cout << BOLD_GREEN_COLOR << "Executing: dog2 = dog1;" << RESET_COLOR << std::endl;
		dog2 = dog1;  // Assignment operator

		std::cout << "\nAfter assignment:" << std::endl;
		std::cout << "Dog1 brain address: " << dog1.getBrain() << std::endl;
		std::cout << "Dog2 brain address: " << dog2.getBrain() << std::endl;
		std::cout << "Dog2 ideas (should be same content, different address):" << std::endl;
		dog2.getBrain()->printIdeas();

		std::cout << "\n--- Verifying independent modification ---" << std::endl;
		std::cout << BOLD_GREEN_COLOR << "Executing: dog1.getBrain()->setIdea(0, \"Modified after assignment\");" << RESET_COLOR << std::endl;
		dog1.getBrain()->setIdea(0, "Modified after assignment");

		std::cout << "\nAfter modifying dog1:" << std::endl;
		std::cout << "Dog1 ideas (modified):" << std::endl;
		dog1.getBrain()->printIdeas();

		std::cout << "Dog2 ideas (should be unchanged - proof of deep copy):" << std::endl;
		dog2.getBrain()->printIdeas();

		std::cout << "\n✅ Dog assignment operator deep copy verified" << std::endl;
	}

	std::cout << "\n----- Testing Cat Assignment Operator -----" << std::endl;
	{
		Cat cat1;
		Cat cat2;

		std::cout << BOLD_GREEN_COLOR << "Executing: cat1.getBrain()->setIdea(0, \"Original cat idea\");" << RESET_COLOR << std::endl;
		cat1.getBrain()->setIdea(0, "Original cat idea");
		std::cout << BOLD_GREEN_COLOR << "Executing: cat1.getBrain()->setIdea(1, \"Sleep in sunny spot\");" << RESET_COLOR << std::endl;
		cat1.getBrain()->setIdea(1, "Sleep in sunny spot");

		std::cout << BOLD_GREEN_COLOR << "Executing: cat2.getBrain()->setIdea(0, \"Different cat idea\");" << RESET_COLOR << std::endl;
		cat2.getBrain()->setIdea(0, "Different cat idea");

		std::cout << "\nBefore assignment:" << std::endl;
		std::cout << "Cat1 brain address: " << cat1.getBrain() << std::endl;
		std::cout << "Cat1 ideas:" << std::endl;
		cat1.getBrain()->printIdeas();

		std::cout << "\nCat2 brain address: " << cat2.getBrain() << std::endl;
		std::cout << "Cat2 ideas:" << std::endl;
		cat2.getBrain()->printIdeas();

		std::cout << "\n--- Performing assignment (cat2 = cat1) ---" << std::endl;
		std::cout << BOLD_GREEN_COLOR << "Executing: cat2 = cat1;" << RESET_COLOR << std::endl;
		cat2 = cat1;  // Assignment operator

		std::cout << "\nAfter assignment:" << std::endl;
		std::cout << "Cat1 brain address: " << cat1.getBrain() << std::endl;
		std::cout << "Cat2 brain address: " << cat2.getBrain() << std::endl;
		std::cout << "Cat2 ideas (should be same content, different address):" << std::endl;
		cat2.getBrain()->printIdeas();

		std::cout << "\n--- Verifying independent modification ---" << std::endl;
		std::cout << BOLD_GREEN_COLOR << "Executing: cat1.getBrain()->setIdea(0, \"Modified cat thought\");" << RESET_COLOR << std::endl;
		cat1.getBrain()->setIdea(0, "Modified cat thought");

		std::cout << "\nAfter modifying cat1:" << std::endl;
		std::cout << "Cat1 ideas (modified):" << std::endl;
		cat1.getBrain()->printIdeas();

		std::cout << "Cat2 ideas (should be unchanged - proof of deep copy):" << std::endl;
		cat2.getBrain()->printIdeas();

		std::cout << "\n✅ Cat assignment operator deep copy verified" << std::endl;
	}
}
