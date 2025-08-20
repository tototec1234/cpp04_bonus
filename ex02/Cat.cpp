/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/21 02:42:55 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "AnsiColor.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << YELLOW_COLOR << "Cat default constructor called           this: " << this << RESET_COLOR << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << YELLOW_COLOR << "Cat copy constructor called              this: " << this << RESET_COLOR << std::endl;
	this->brain = new Brain(*other.brain);  // Deep copy
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << YELLOW_COLOR << "Cat assignment operator called          this: " << this << RESET_COLOR << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);  // Deep copy
	}
	return *this;
}

Cat::~Cat() {
	std::cout << YELLOW_COLOR << "Cat destructor called                   this: " << this << RESET_COLOR << std::endl;
	delete this->brain;
}

void Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
	return this->brain;
}
