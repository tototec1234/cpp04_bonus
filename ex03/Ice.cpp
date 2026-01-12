/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/12 13:17:03 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

#include <iostream>

#include "ICharacter.hpp"
#include "AnsiColor.hpp"


Ice::Ice() : AMateria("ice") {
	std::cerr << YELLOW_COLOR << "Ice default constructor called           this: " << this << RESET_COLOR << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other) {
	std::cerr << YELLOW_COLOR << "Ice copy constructor called              this: " << this << RESET_COLOR << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
	std::cerr << YELLOW_COLOR << "Ice assignment operator called          this: " << this << RESET_COLOR << std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

Ice::~Ice() {
	std::cerr << YELLOW_COLOR << "Ice destructor called                   this: " << this << RESET_COLOR << std::endl;
}

AMateria* Ice::clone() const {
  return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at "
			 << target.getName()
			 << " *" << std::endl;
}
