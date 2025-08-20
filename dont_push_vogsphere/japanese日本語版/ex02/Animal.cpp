/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/20 18:26:23 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "AnsiColor.hpp"

Animal::Animal() : type("Animal") {
	std::cout << MAGENTA_COLOR << "Animal default constructor called        this: " << this << RESET_COLOR << std::endl;
}

Animal::Animal(const std::string &animalType) : type(animalType) {
	std::cout << MAGENTA_COLOR << "Animal parameterized constructor called this: " << this << RESET_COLOR << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
	std::cout << MAGENTA_COLOR << "Animal copy constructor called           this: " << this << RESET_COLOR << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << MAGENTA_COLOR << "Animal assignment operator called       this: " << this << RESET_COLOR << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << MAGENTA_COLOR << "Animal destructor called                this: " << this << RESET_COLOR << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}
