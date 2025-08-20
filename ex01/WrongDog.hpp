/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/21 00:09:49 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include "WrongAnimal.hpp"
#include "WrongBrain.hpp"

class WrongDog : public WrongAnimal {
private:
	WrongBrain* brain;

public:
	WrongDog();
	WrongDog(const WrongDog &other);
	WrongDog &operator=(const WrongDog &other);
	~WrongDog();

	void makeSound() const;  // NOT virtual!
	WrongBrain& getBrain() const;
	
	// レビュー時安全対策用メソッド (double delete防止)
	void nullifyBrainForSafety();  // レビュアー合意なしクラッシュ防止用
};

#endif
