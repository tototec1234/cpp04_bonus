/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/17 17:31:05 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
#include "AnsiColor.hpp"

Animal::Animal() : type("Animal") {
	std::cout << BLUE_COLOR << "Animal default constructor called        this: " << this << RESET_COLOR << std::endl;
}

Animal::Animal(const std::string &animalType) : type(animalType) {
	std::cout << BLUE_COLOR << "Animal parameterized constructor called this: " << this << RESET_COLOR << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
	std::cout << BLUE_COLOR << "Animal copy constructor called           this: " << this << RESET_COLOR << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << BLUE_COLOR << "Animal assignment operator called       this: " << this << RESET_COLOR << std::endl;
	if (this != &other) {
	    this->type = other.type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << BLUE_COLOR << "Animal destructor called                this: " << this << RESET_COLOR << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Animal makes a generic sound" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}
