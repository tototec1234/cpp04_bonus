/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:28:55 by toruinoue         #+#    #+#             */
/*   Updated: 2025/08/17 15:28:56 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog();

    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    ~Dog();
    
    void makeSound() const;
};

#endif
    /*
    コピーコンストラクタは基底クラス(Animal)のコピーコンストラクタを呼び出すだけで、
    Dogクラス固有のメンバ変数を持たないため、明示的な実装は不要です。
    コンパイラが生成するデフォルトのコピーコンストラクタで十分です。
    */