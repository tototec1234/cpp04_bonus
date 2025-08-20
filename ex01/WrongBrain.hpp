/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongBrain.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:00:00 by toruinoue        #+#    #+#             */
/*   Updated: 2025/01/27 22:00:00 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGBRAIN_HPP
#define WRONGBRAIN_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class WrongBrain {
private:
	std::string ideas[100];

public:
	WrongBrain();
	WrongBrain(const WrongBrain &other);
	WrongBrain &operator=(const WrongBrain &other);
	~WrongBrain();

	void setIdea(int index, const std::string &idea);
	std::string getIdea(int index) const;
	void printIdeas() const;
};

#endif
