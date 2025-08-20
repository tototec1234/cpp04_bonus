/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:48:18 by torinoue          #+#    #+#             */
/*   Updated: 2025/08/20 08:37:19 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#include <vector>					// Added for Module 08+ style

class Brain {
private:
	// static const int IDEAS_COUNT = 100;		// Removed: Module 04 style
	static const size_t IDEAS_COUNT = 100;		// Added: size_t for safer indexing
	// std::string ideas[IDEAS_COUNT];		// Removed: raw array (Module 04 constraint)
	std::vector<std::string> ideas;			// Added: modern C++ container (Module 08+)

public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	// void setIdea(int index, const std::string &idea);	// Removed: unsafe int indexing
	void setIdea(size_t index, const std::string &idea);	// Added: safe size_t indexing
	// std::string getIdea(int index) const;		// Removed: unsafe int indexing
	std::string getIdea(size_t index) const;		// Added: safe size_t indexing
	void printIdeas() const;
	size_t size() const;					// Added: access to container size
};

#endif
