/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:06 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/20 08:35:30 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "AnsiColor.hpp"
#include <stdexcept>					// Added for exception handling
#include <algorithm>					// Added for std::min function

Brain::Brain() : ideas(IDEAS_COUNT, "") {		// Added: initializer list for vector
	std::cout << CYAN_COLOR << "Brain default constructor called         this: " << this << RESET_COLOR << std::endl;
	// std::vector is automatically initialized with 100 empty strings
	/*
	// Removed: Manual loop initialization (Module 04 constraint)
	for (int i = 0; i < IDEAS_COUNT; i++) {
	    ideas[i] = "";
	}
	*/
}

Brain::Brain(const Brain &other) : ideas(other.ideas) {	// Added: direct copy using vector's copy constructor
	std::cout << CYAN_COLOR << "Brain copy constructor called            this: " << this << RESET_COLOR << std::endl;
	// std::vector's copy constructor handles deep copy automatically
	/*
	// Removed: Manual loop copying (Module 04 constraint)
	for (int i = 0; i < IDEAS_COUNT; i++) {
	    this->ideas[i] = other.ideas[i];
	}
	*/
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << CYAN_COLOR << "Brain assignment operator called        this: " << this << RESET_COLOR << std::endl;
	if (this != &other) {
	    ideas = other.ideas;  // Added: std::vector's assignment operator handles deep copy
	    /*
	    // Removed: Manual loop assignment (Module 04 constraint)
	    for (int i = 0; i < IDEAS_COUNT; i++) {
	        this->ideas[i] = other.ideas[i];
	    }
	    */
	}
	return *this;
}

Brain::~Brain() {
	std::cout << CYAN_COLOR << "Brain destructor called                 this: " << this << RESET_COLOR << std::endl;
}

void Brain::setIdea(size_t index, const std::string &idea) {		// Added: safe size_t parameter
	try {								// Added: exception handling (Module 08+)
		ideas.at(index) = idea;				// Added: automatic boundary check (Module 08+)
	} catch (const std::out_of_range& e) {
		std::cerr << "Error: Index " << index << " is out of range (size: " << ideas.size() << ")" << std::endl;
	}
	/*
	// Removed: unsafe manual boundary check (Module 04 constraint)
	if (index >= 0 && index < IDEAS_COUNT) {
	    ideas[index] = idea;
	}
	*/
}

std::string Brain::getIdea(size_t index) const {			// Added: safe size_t parameter
	try {								// Added: exception handling (Module 08+)
		return ideas.at(index);				// Added: automatic boundary check (Module 08+)
	} catch (const std::out_of_range& e) {
		std::cerr << "Error: Index " << index << " is out of range (size: " << ideas.size() << ")" << std::endl;
		return "";
	}
	/*
	// Removed: unsafe manual boundary check (Module 04 constraint)
	if (index >= 0 && index < IDEAS_COUNT) {
	    return ideas[index];
	}
	return "";
	*/
}

void Brain::printIdeas() const {
	std::cout << "Brain ideas (showing first 5):" << std::endl;
	for (size_t i = 0; i < std::min(static_cast<size_t>(5), ideas.size()); ++i) {	// Added: safe iterator with std::min
		if (!ideas[i].empty()) {
			std::cout << "  [" << i << ":" << &ideas[i] << "]: " << ideas[i] << std::endl;
		}
	}
	/*
	// Removed: unsafe manual loop (Module 04 constraint)
	for (int i = 0; i < 5; i++) {
	    if (!ideas[i].empty()) {
	        std::cout << "  [" << i << ":" << &ideas[i] << "]: " << ideas[i] << std::endl;
	    }
	}
	*/
}

size_t Brain::size() const {					// Added: accessor for container size (Module 08+)
	return ideas.size();
}
