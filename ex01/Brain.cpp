/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/20 08:50:19 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "AnsiColor.hpp"

Brain::Brain() {
	std::cout << CYAN_COLOR << "Brain default constructor called         this: " << this << RESET_COLOR << std::endl;
	for (int i = 0; i < 100; i++) {
	    ideas[i] = "";
	}
}

Brain::Brain(const Brain &other) {
	std::cout << CYAN_COLOR << "Brain copy constructor called            this: " << this << RESET_COLOR << std::endl;
	for (int i = 0; i < 100; i++) {
	    this->ideas[i] = other.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << CYAN_COLOR << "Brain assignment operator called        this: " << this << RESET_COLOR << std::endl;
	if (this != &other) {
	    for (int i = 0; i < 100; i++) {
	        this->ideas[i] = other.ideas[i];
	    }
	}
	return *this;
}

Brain::~Brain() {
	std::cout << CYAN_COLOR << "Brain destructor called                 this: " << this << RESET_COLOR << std::endl;
}

void Brain::setIdea(int index, const std::string &idea) {
	if (index < 0 || index >= 100) {
	    throw std::out_of_range("Brain::setIdea: Index out of range (0-99). Given index: " + std::to_string(index));
	}
	ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
	if (index < 0 || index >= 100) {
	    throw std::out_of_range("Brain::getIdea: Index out of range (0-99). Given index: " + std::to_string(index));
	}
	return ideas[index];
}

void Brain::printIdeas() const {
	std::cout << "Brain ideas:" << std::endl;
	for (int i = 0; i < 5; i++) {  // Print first 5 ideas
	    if (!ideas[i].empty()) {
	        std::cout << "  [" << i << ":" << &ideas[i] << "]: " << ideas[i] << std::endl;
	    }
	}
}

