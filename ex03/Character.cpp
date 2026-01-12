/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2026/01/12 12:22:04 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Character.hpp"

#include "../incs/AMateria.hpp"

class AMateria;

Character::Character() : _name("") {
  for (int i = 0; i < 4; ++i) _inventory[i] = NULL;
}	

Character::Character(std::string const & name) : _name(name) {
  for (int i = 0; i < 4; ++i) _inventory[i] = NULL;
}

Character::Character(Character const & other) : _name(other._name) {
  for (int i = 0; i < 4; ++i) {
    if (other._inventory[i] != NULL) {
      _inventory[i] = other._inventory[i]->clone();
    } else {
      _inventory[i] = NULL;
    }
  }
}
		Character& operator=(Character const & other);
		~Character();

		std::string const & getName() const;
		AMateria* getMateria(int idx) const;

		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

	private:
		std::string _name;
		AMateria* _inventory[4];
};

#endif
