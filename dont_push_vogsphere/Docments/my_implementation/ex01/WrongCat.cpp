/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:59:50 by toruinoue         #+#    #+#             */
/*   Updated: 2025/08/20 17:00:22 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "AnsiColor.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << MAGENTA_COLOR << "WrongCat default constructor called     this: " << this << RESET_COLOR << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << MAGENTA_COLOR << "WrongCat copy constructor called        this: " << this << RESET_COLOR << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	std::cout << MAGENTA_COLOR << "WrongCat assignment operator called    this: " << this << RESET_COLOR << std::endl;
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << MAGENTA_COLOR << "WrongCat destructor called             this: " << this << RESET_COLOR << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Wrong Meow! (This won't be called in polymorphism)" << std::endl;
}
