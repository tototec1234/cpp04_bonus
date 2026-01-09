/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/10 03:04:50 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

#include <iostream>
#include <string>

class ICharacter;

class Ice : public AMateria
{
	// protected:
	// 	std::string _type;

	public:
	
		Ice(Ice const & other);
		Ice(const AMateria & other);
		Ice&operator=(const AMateria & other);
		virtual ~AMateria();
	
		std::string const & getType() const; //Returns the materia type
	
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
