/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/20 14:51:23 by toruinoue        ###   ########.fr       */
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

	// 学習用デモ: 以下のコメントアウトを外すとコンパイルエラーが発生
	// void makeSound() const = 0;  // NOT virtual!
	// エラー: 'makeSound' is not virtual and cannot be declared pure
	// 理由: C++では純粋仮想関数(= 0)にするには必ずvirtualキーワードが必要
	std::string getType() const;
};

#endif
