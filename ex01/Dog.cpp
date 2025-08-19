/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/17 17:33:29 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "AnsiColor.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << GREEN_COLOR << "Dog default constructor called           this: " << this << RESET_COLOR << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << GREEN_COLOR << "Dog copy constructor called              this: " << this << RESET_COLOR << std::endl;
	this->brain = new Brain(*other.brain);  // Deep copy
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << GREEN_COLOR << "Dog assignment operator called          this: " << this << RESET_COLOR << std::endl;
	if (this != &other) {
	    Animal::operator=(other);
	    delete this->brain;
	    this->brain = new Brain(*other.brain);  // Deep copy
	}
	return *this;
}

Dog::~Dog() {
	std::cout << GREEN_COLOR << "Dog destructor called                   this: " << this << RESET_COLOR << std::endl;
	delete this->brain;
}

void Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
	return this->brain;
}
