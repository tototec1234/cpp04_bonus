/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/20 18:22:34 by toruinoue        ###   ########.fr       */
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
	// 🔴 SHALLOW COPY: ポインタのみコピー（危険な実装例）
	this->brain = other.brain;
	std::cout << CYAN_COLOR << "  ⚠️  SHALLOW COPY: brain pointer copied from " << other.brain << RESET_COLOR << std::endl;
}

WrongDog &WrongDog::operator=(const WrongDog &other) {
	std::cout << CYAN_COLOR << "WrongDog assignment operator called    this: " << this << RESET_COLOR << std::endl;
	if (this != &other) {
		WrongAnimal::operator=(other);
		// 🔴 SHALLOW COPY: 古いbrainを削除せずにポインタのみコピー（危険な実装例）
		// delete this->brain;  // メモリリークを避けるためコメントアウトしていない実装例
		this->brain = other.brain;  // ポインタのみコピー！
		std::cout << CYAN_COLOR << "  ⚠️  SHALLOW COPY: brain pointer assigned from " << other.brain << RESET_COLOR << std::endl;
	}
	return *this;
}

WrongDog::~WrongDog() {
	std::cout << CYAN_COLOR << "WrongDog destructor called             this: " << this << RESET_COLOR << std::endl;
	delete this->brain;
}

void WrongDog::makeSound() const {
	std::cout << "Wrong Woof! (This won't be called in polymorphism)" << std::endl;
}

WrongBrain& WrongDog::getBrain() const {
	return *this->brain;
}
