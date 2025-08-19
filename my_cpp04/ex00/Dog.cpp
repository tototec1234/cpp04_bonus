/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/19 17:30:20 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "AnsiColor.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << GREEN_COLOR << "Dog default constructor called" << RESET_COLOR << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << GREEN_COLOR << "Dog copy constructor called" << RESET_COLOR << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << GREEN_COLOR << "Dog assignment operator called" << RESET_COLOR << std::endl;
	if (this != &other) {
	    Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << GREEN_COLOR << "Dog destructor called" << RESET_COLOR << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}

void Dog::makeSound() const {
	std::cout << GREEN_COLOR << "Woof! Woof!" << RESET_COLOR << std::endl;
}
