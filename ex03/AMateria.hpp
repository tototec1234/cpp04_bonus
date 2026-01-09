/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/10 03:05:10 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria(std::string const & type);
		// AMateria(const AMateria & other);
		// AMateria &operator=(const AMateria & other);
		virtual ~AMateria();
	
		std::string const & getType() const; //Returns the materia type
	
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
