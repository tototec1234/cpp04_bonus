/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/19 21:02:14 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"
#include "AnsiColor.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << MAGENTA_COLOR << "WrongCat default constructor called" << RESET_COLOR << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << MAGENTA_COLOR << "WrongCat copy constructor called" << RESET_COLOR << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << MAGENTA_COLOR << "WrongCat assignment operator called" << RESET_COLOR << std::endl;
	if (this != &other) {
	    WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << MAGENTA_COLOR << "WrongCat destructor called" << RESET_COLOR << std::endl;
	std::cout << "WrongCat* WrongCat = new WrongCat(); あくまでWrongCatクラスのインスタンスされた時　かスタックの時" << std::endl;
	std::cout << "呼び出されるのは　WrongAnimalのPolymorphismとしてのWrongCat でWrongCat* WrongCat = new WrongCat(); された時　かスタックの時" << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << MAGENTA_COLOR << "Wrong Meow! (This won't be called in polymorphism)" << RESET_COLOR << std::endl;
}
