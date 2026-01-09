/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/10 06:30:09 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP




#include "AMateria.hpp"

class Cure : public AMateria
{
	// protected:
	// 	std::string _type;

	public:
		Cure();
		Cure(Cure const & other);
		Cure(const Cure & other);
		Cure&operator=(const Cure & other);
		~Cure();
	
		// std::string const & getType() const; //Returns the materia type
	
		AMateria* clone() const // = 0;
		void use(ICharacter& target);
};

#endif
