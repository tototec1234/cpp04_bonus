/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torinoue <torinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/21 02:41:00 by torinoue         ###   ########.fr       */
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
		virtual ~Animal();

		virtual void makeSound() const;
		std::string getType() const;
};

#endif

/*
Virtual Destructor (~Animal):
- By making the base class destructor virtual, we ensure that derived class objects are
	properly released when accessed through base class pointers. This prevents memory leaks.

virtual makeSound:
- By making this method virtual, the appropriate derived class makeSound is called at runtime (dynamic dispatch).
- This ensures that derived class implementations like Dog::makeSound() or Cat::makeSound() are
	correctly called through base class pointers.
*/

/*
Etymology and References for the 'virtual' keyword:

[Etymological Flow]
Latin: virtus (power, effectiveness, virtue)
	↓
Medieval Latin: virtualis (having potential power)
	↓  
Modern English: virtual (actual, effective)
	↓
Computer Science: functionally equivalent

[Japanese References]
- Microsoft Learn - virtual (C++): 
	https://learn.microsoft.com/ja-jp/cpp/cpp/virtual-cpp?view=msvc-170
- IBM Documentation - Virtual Functions: 
	https://www.ibm.com/docs/ja/i/7.2?topic=only-virtual-functions-c
- Programming Place Plus - Virtual Methods: 
	https://programming-place.net/ppp/contents/cpp/language/024.html
- C++ Introduction - Virtual Functions: 
	https://beginner-engineer-study.com/virtual-function/
- Makumaku C++ Notes: 
	https://maku77.github.io/cpp/virtual.html

[English References]
- C++ Reference - Virtual function: 
	https://en.cppreference.com/w/cpp/language/virtual
- ISO C++ FAQ - Virtual Functions: 
	https://isocpp.org/wiki/faq/virtual-functions

Note: C++'s "virtual" doesn't mean "simulated" but rather "actual" or "effective".
It means "functionally equivalent". Base class pointers behave "effectively" as derived classes.
*/

/*
Consistent Usage in Computer Science
Term			Meaning
Virtual Memory		Not physical memory, but functions the same as actual memory
Virtual Machine		Not physical machine, but behaves like an actual machine
Virtual Function	Not base class function, but actually realizes that functionality
Exact meaning of 'virtual' in C++
What "virtual" expresses:
"Acting as if" - behaves as if it were something else
"Functionally equivalent" - functionally equivalent
"In effect" - in effect, practically
"For practical purposes" - for practical purposes
*/