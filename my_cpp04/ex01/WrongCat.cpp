/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/17 17:35:19 by toruinoue        ###   ########.fr       */
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
