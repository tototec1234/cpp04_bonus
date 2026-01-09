/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/10 07:25:21 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

#include <iostream>

#include "ICharacter.hpp"
#include "AnsiColor.hpp"


Cure::Cure() : AMateria("Cure") {
	std::cout << YELLOW_COLOR << "Cure default constructor called           this: " << this << RESET_COLOR << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other) {
	std::cout << YELLOW_COLOR << "Cure copy constructor called              this: " << this << RESET_COLOR << std::endl;
}

Cure &Cure::operator=(const Cure &other) {
	std::cout << YELLOW_COLOR << "Cure assignment operator called          this: " << this << RESET_COLOR << std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

Cure::~Cure() {
	std::cout << YELLOW_COLOR << "Cure destructor called                   this: " << this << RESET_COLOR << std::endl;
}

AMateria* Cure::clone() const {
  return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals "
 			 << target.getName()
			 << "'s wounds *" << std::endl;
}
