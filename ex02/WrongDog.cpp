/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/21 02:43:31 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"
#include "AnsiColor.hpp"

WrongDog::WrongDog() : WrongAnimal("WrongDog") {
	std::cout << CYAN_COLOR << "WrongDog default constructor called     this: " << this << RESET_COLOR << std::endl;
}

WrongDog::WrongDog(const WrongDog &other) : WrongAnimal(other) {
	std::cout << CYAN_COLOR << "WrongDog copy constructor called        this: " << this << RESET_COLOR << std::endl;
}

WrongDog &WrongDog::operator=(const WrongDog &other) {
	std::cout << CYAN_COLOR << "WrongDog assignment operator called    this: " << this << RESET_COLOR << std::endl;
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongDog::~WrongDog() {
	std::cout << CYAN_COLOR << "WrongDog destructor called             this: " << this << RESET_COLOR << std::endl;
}

void WrongDog::makeSound() const {
	std::cout << "Wrong Woof! (This won't be called in polymorphism)" << std::endl;
}
