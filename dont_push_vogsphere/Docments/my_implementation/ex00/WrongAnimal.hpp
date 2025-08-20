/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:28:46 by toruinoue         #+#    #+#             */
/*   Updated: 2025/08/17 15:28:47 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
    std::string type;

public:
    WrongAnimal();
    WrongAnimal(const std::string &animalType);
    WrongAnimal(const WrongAnimal &other);
    WrongAnimal &operator=(const WrongAnimal &other);
    ~WrongAnimal();

    void makeSound() const;  // NOT virtual!
    std::string getType() const;
};

#endif
