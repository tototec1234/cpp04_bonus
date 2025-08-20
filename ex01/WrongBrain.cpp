/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongBrain.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:22:04 by toruinoue         #+#    #+#             */
/*   Updated: 2025/08/20 18:22:10 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongBrain.hpp"
#include "AnsiColor.hpp"
#include <sstream>

WrongBrain::WrongBrain() {
	std::cout << RED_COLOR << "WrongBrain default constructor called   this: " << this << RESET_COLOR << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = "";
	}
}

WrongBrain::WrongBrain(const WrongBrain &other) {
	std::cout << RED_COLOR << "WrongBrain copy constructor called      this: " << this << RESET_COLOR << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = other.ideas[i];
	}
}

WrongBrain &WrongBrain::operator=(const WrongBrain &other) {
	std::cout << RED_COLOR << "WrongBrain assignment operator called   this: " << this << RESET_COLOR << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

WrongBrain::~WrongBrain() {
	std::cout << RED_COLOR << "WrongBrain destructor called            this: " << this << RESET_COLOR << std::endl;
}

void WrongBrain::setIdea(int index, const std::string &idea) {
	if (index < 0 || index >= 100) {
		std::stringstream ss;
		ss << index;
		throw std::out_of_range("WrongBrain::setIdea: Index out of range (0-99). Given index: " + ss.str());
	}
	ideas[index] = idea;
}

std::string WrongBrain::getIdea(int index) const {
	if (index < 0 || index >= 100) {
		std::stringstream ss;
		ss << index;
		throw std::out_of_range("WrongBrain::getIdea: Index out of range (0-99). Given index: " + ss.str());
	}
	return ideas[index];
}

void WrongBrain::printIdeas() const {
	std::cout << "WrongBrain ideas:" << std::endl;
	for (int i = 0; i < 5; i++) {  // Print first 5 ideas
		if (!ideas[i].empty()) {
			std::cout << "  [" << i << ":" << &ideas[i] << "]: " << ideas[i] << std::endl;
		}
	}
}
