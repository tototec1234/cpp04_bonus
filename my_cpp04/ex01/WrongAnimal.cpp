/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/19 12:19:46 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "AnsiColor.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << MAGENTA_COLOR << "WrongAnimal default constructor called  this: " << this << RESET_COLOR << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &animalType) : type(animalType) {
	std::cout << MAGENTA_COLOR << "WrongAnimal parameterized constructor called this: " << this << RESET_COLOR << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
	std::cout << MAGENTA_COLOR << "WrongAnimal copy constructor called     this: " << this << RESET_COLOR << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << MAGENTA_COLOR << "WrongAnimal assignment operator called this: " << this << RESET_COLOR << std::endl;
	if (this != &other) {
	    this->type = other.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << MAGENTA_COLOR << "WrongAnimal destructor called           this: " << this << RESET_COLOR << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal makes a wrong sound" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}
