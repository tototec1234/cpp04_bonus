/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:28:41 by toruinoue         #+#    #+#             */
/*   Updated: 2025/08/17 15:28:42 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat default constructor called" << std::endl;
    std::cout << "type: " << type << ", this: " << this << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    std::cout << "type: " << type << ", this: " << this << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

// 注意: 派生クラスデストラクタは基底クラスより先に実行されるため、typeメンバはまだ有効
Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    std::cout << "派生クラスデストラクタは基底クラスより先に実行されるため、typeメンバはまだ有効" << std::endl;
    std::cout << "type: " << type << ", this: " << this << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}
