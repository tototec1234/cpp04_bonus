/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/19 22:15:52 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "AnsiColor.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << BLUE_COLOR << "WrongAnimal default constructor called" << RESET_COLOR << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &animalType) : type(animalType)
{
	std::cout << BLUE_COLOR << "WrongAnimal parameterized constructor called" << RESET_COLOR << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}



WrongAnimal::~WrongAnimal()
{
	std::cout << BLUE_COLOR << "WrongAnimal destructor called" << RESET_COLOR << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << BLUE_COLOR << "WrongAnimal makes a wrong sound" << RESET_COLOR << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}
