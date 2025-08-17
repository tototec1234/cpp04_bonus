/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/17 17:27:06 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"
#include "AnsiColor.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << RED_COLOR << "WrongCat default constructor called" << RESET_COLOR << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << RED_COLOR << "WrongCat copy constructor called" << RESET_COLOR << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	std::cout << RED_COLOR << "WrongCat assignment operator called" << RESET_COLOR << std::endl;
	if (this != &other) {
	    WrongAnimal::operator=(other);
	}
	return *this;
}

// 警告: WrongAnimalは非virtualデストラクタなので、ポインタ経由でのdeleteでは呼ばれない可能性
WrongCat::~WrongCat() {
	std::cout << RED_COLOR << "WrongCat destructor called" << RESET_COLOR << std::endl;
	std::cout << "WrongAnimalは非virtualデストラクタなので、ポインタ経由でのdeleteでは呼ばれない可能性" << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << RED_COLOR << "Wrong Meow! (This won't be called in polymorphism)" << RESET_COLOR << std::endl;
}
