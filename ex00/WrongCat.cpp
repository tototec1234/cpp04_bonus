/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/21 02:41:23 by torinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "AnsiColor.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << MAGENTA_COLOR << "WrongCat default constructor called" << RESET_COLOR << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << MAGENTA_COLOR << "WrongCat destructor called" << RESET_COLOR << std::endl;
	std::cout << MAGENTA_COLOR << "継承的インスタンス化 (Inheritance-based Instantiation: WrongCat* = new WrongCat()) の場合: このデストラクタが呼ばれる" << RESET_COLOR << std::endl;
	std::cout << MAGENTA_COLOR << "多態的インスタンス化 (Polymorphic Instantiation: WrongAnimal* = new WrongCat()) の場合: virtualがないため呼ばれない！" << RESET_COLOR << std::endl;
	std::cout << "type: " << type << ", this: " << this << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << MAGENTA_COLOR << "Wrong Meow! (継承的インスタンス化 / Inheritance-based Instantiation でのみ呼ばれる)" << RESET_COLOR << std::endl;
	std::cout << MAGENTA_COLOR << "注意: 基底クラスポインタ (Base Class Pointer) 経由では virtualがないため基底クラスのmakeSound()が呼ばれる" << RESET_COLOR << std::endl;
}
