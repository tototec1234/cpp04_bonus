/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/20 14:43:25 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "AnsiColor.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << MAGENTA_COLOR << "Cat default constructor called" << RESET_COLOR << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}



Cat::~Cat()
{
	std::cout << MAGENTA_COLOR << "Cat destructor called" << RESET_COLOR << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}

void Cat::makeSound() const
{
	std::cout << MAGENTA_COLOR << "Meow! Meow!" << RESET_COLOR << std::endl;
}
