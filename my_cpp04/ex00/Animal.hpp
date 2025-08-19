/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/19 16:53:07 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(const std::string &animalType);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();

		virtual void makeSound() const;
		std::string getType() const;
};

#endif

/*
virtualデストラクタ (~Animal):
- 基底クラスのデストラクタをvirtualにすることで、派生クラスのオブジェクトが基底クラスのポインタを通じて
  適切に解放されることを保証します。これにより、メモリリークを防ぎます。

virtual makeSound:
- このメソッドをvirtualにすることで、実行時に適切な派生クラスのmakeSoundが呼び出されます（動的ディスパッチ）。
- これにより、Dog::makeSound()やCat::makeSound()のような派生クラスの実装が、基底クラスのポインタを通じて
  正しく呼び出されることが保証されます。
*/

/*
virtualキーワードの語源と出典・参考文献:

【語源的な流れ】
Latin: virtus (力、効力、美徳)
  ↓
Medieval Latin: virtualis (潜在的な力を持つ)
  ↓  
Modern English: virtual (実質的な、事実上の)
  ↓
Computer Science: functionally equivalent (機能的に同等)

【日本語出典】
- Microsoft Learn - virtual (C++): 
  https://learn.microsoft.com/ja-jp/cpp/cpp/virtual-cpp?view=msvc-170
- IBM Documentation - 仮想関数: 
  https://www.ibm.com/docs/ja/i/7.2?topic=only-virtual-functions-c
- Programming Place Plus - 仮想メソッド: 
  https://programming-place.net/ppp/contents/cpp/language/024.html
- C++入門 - 仮想関数: 
  https://beginner-engineer-study.com/virtual-function/
- まくまくC++ノート: 
  https://maku77.github.io/cpp/virtual.html

【英語出典】
- C++ Reference - Virtual function: 
  https://en.cppreference.com/w/cpp/language/virtual
- ISO C++ FAQ - Virtual Functions: 
  https://isocpp.org/wiki/faq/virtual-functions

注意: C++の「virtual」は日本語の「仮想」ではなく、英語の「実質的な」「事実上の」
「機能的に同等」を意味する。基底クラスポインタでも「実質的に」派生クラスとして動作。
*/

/*
計算機科学での一貫した使用法
用語	意味
Virtual Memory	物理メモリではないが、実際のメモリと同じ機能
Virtual Machine	物理マシンではないが、実際のマシンと同じ動作
Virtual Function	基底クラス関数ではないが、実際にその機能を実現
🔍 C++におけるvirtualの正確な意味
「virtual」が表現すること
"Acting as if" - まるで〜であるかのように振る舞う
"Functionally equivalent" - 機能的に同等
"In effect" - 実質的に、事実上
"For practical purposes" - 実用的な目的において
*/