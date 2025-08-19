/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/19 17:30:33 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "AnsiColor.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << BLUE_COLOR << "Animal default constructor called" << RESET_COLOR << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}

Animal::Animal(const std::string &animalType) : type(animalType)
{
	std::cout << BLUE_COLOR << "Animal parameterized constructor called" << RESET_COLOR << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << BLUE_COLOR << "Animal copy constructor called" << RESET_COLOR << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << BLUE_COLOR << "Animal assignment operator called" << RESET_COLOR << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << BLUE_COLOR << "Animal destructor called" << RESET_COLOR << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}

void Animal::makeSound() const
{
	std::cout << BLUE_COLOR << "Animal makes a generic sound" << RESET_COLOR << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}

