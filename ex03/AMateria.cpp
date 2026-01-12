/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/12 13:16:59 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "AnsiColor.hpp"

#include <iostream>

#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type) : _type(type){
	std::cerr << MAGENTA_COLOR << "AMateria parameterized constructor called this: " << this << RESET_COLOR << std::endl;
}

		// AMateria(const AMateria & other);
		// AMateria &operator=(const AMateria & other);

AMateria::~AMateria(){
	std::cerr << MAGENTA_COLOR << "AMateria destructor called                this: " << this << RESET_COLOR << std::endl;
}

std::string const & AMateria::getType() const {
	return this->_type;
}


// virtual AMateria* clone() const = 0;

// void AMateria::use(ICharacter& target) {
// 	std::cout << "* uses materia of type " << this->_type
// 			  << " on " << target.getName() << " *" << std::endl;
//   }
void AMateria::use(ICharacter& target) {
	(void)target;
}

