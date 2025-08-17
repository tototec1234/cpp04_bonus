/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/17 17:27:06 by toruinoue        ###   ########.fr       */
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

// 注意: 派生クラスデストラクタは基底クラスより先に実行されるため、typeメンバはまだ有効
Dog::~Dog() {
	std::cout << GREEN_COLOR << "Dog destructor called" << RESET_COLOR << std::endl;
	std::cout << "派生クラスデストラクタは基底クラスより先に実行されるため、typeメンバはまだ有効" << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}

void Dog::makeSound() const {
	std::cout << GREEN_COLOR << "Woof! Woof!" << RESET_COLOR << std::endl;
}
