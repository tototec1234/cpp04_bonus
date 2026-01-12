/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/12 12:56:49 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	// protected:
	// 	std::string _type;

	public:
		Ice();
		Ice(Ice const & other);
		Ice(const AMateria & other);
		Ice&operator=(const Ice & other);
		~Ice();
	
		// std::string const & getType() const; //Returns the materia type
	
		AMateria* clone() const; // = 0;
		void use(ICharacter& target);
};

#endif
