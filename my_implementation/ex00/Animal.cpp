/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:04:25 by toruinoue         #+#    #+#             */
/*   Updated: 2025/08/17 15:28:19 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}

Animal::Animal(const std::string &animalType) : type(animalType) {
	std::cout << "Animal parameterized constructor called" << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
	std::cout << "Animal copy constructor called" << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

// 注意: デストラクタでtypeメンバにアクセス可能（まだ破棄されていない）
Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
	std::cout << "デストラクタでtypeメンバにアクセス可能（まだ破棄されていない）" << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Animal makes a generic sound" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}
