/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/21 00:12:53 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"
#include "AnsiColor.hpp"

WrongDog::WrongDog() : WrongAnimal("WrongDog") {
	std::cout << CYAN_COLOR << "WrongDog default constructor called     this: " << this << RESET_COLOR << std::endl;
	this->brain = new WrongBrain();
}

WrongDog::WrongDog(const WrongDog &other) : WrongAnimal(other) {
	std::cout << CYAN_COLOR << "WrongDog copy constructor called        this: " << this << RESET_COLOR << std::endl;
	// SHALLOW COPY: Only pointer copied (dangerous implementation example)
	this->brain = other.brain;
	std::cout << CYAN_COLOR << "  ⚠️  SHALLOW COPY: brain pointer copied from " << other.brain << RESET_COLOR << std::endl;
}

WrongDog &WrongDog::operator=(const WrongDog &other) {
	std::cout << CYAN_COLOR << "WrongDog assignment operator called    this: " << this << RESET_COLOR << std::endl;
	if (this != &other) {
		WrongAnimal::operator=(other);
		// SHALLOW COPY: Only pointer copied without deleting old brain (dangerous implementation example)
		// delete this->brain;  // Implementation example without commenting out to avoid memory leaks
		this->brain = other.brain;  // Only pointer copied!
		std::cout << CYAN_COLOR << "  ⚠️  SHALLOW COPY: brain pointer assigned from " << other.brain << RESET_COLOR << std::endl;
	}
	return *this;
}

WrongDog::~WrongDog() {
	std::cout << CYAN_COLOR << "WrongDog destructor called             this: " << this << RESET_COLOR << std::endl;
	// 安全対策: NULLチェックを追加してdouble delete防止
	if (this->brain != NULL) {  // 安全対策追加
		delete this->brain;
		this->brain = NULL;  // 二重削除防止
	}
}

void WrongDog::makeSound() const {
	std::cout << "Wrong Woof! (This won't be called in polymorphism)" << std::endl;
}

WrongBrain& WrongDog::getBrain() const {
	return *this->brain;
}

// レビュー時安全対策用メソッド実装
void WrongDog::nullifyBrainForSafety() {
	std::cout << CYAN_COLOR << "  🛡️  SAFETY: brainポインタをNULLに設定 (double delete防止)" << RESET_COLOR << std::endl;
	this->brain = NULL;  // 安全対策: double delete防止のためNULLに設定
}
