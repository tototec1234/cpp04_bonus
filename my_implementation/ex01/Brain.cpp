#include "Brain.hpp"
#include "AnsiColor.hpp"

Brain::Brain() {
    std::cout << CYAN_COLOR << "Brain default constructor called         this: " << this << RESET_COLOR << std::endl;
    for (int i = 0; i < IDEAS_COUNT; i++) {
        ideas[i] = "";
    }
}

Brain::Brain(const Brain &other) {
    std::cout << CYAN_COLOR << "Brain copy constructor called            this: " << this << RESET_COLOR << std::endl;
    for (int i = 0; i < IDEAS_COUNT; i++) {
        this->ideas[i] = other.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &other) {
    std::cout << CYAN_COLOR << "Brain assignment operator called        this: " << this << RESET_COLOR << std::endl;
    if (this != &other) {
        for (int i = 0; i < IDEAS_COUNT; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << CYAN_COLOR << "Brain destructor called                 this: " << this << RESET_COLOR << std::endl;
}

void Brain::setIdea(int index, const std::string &idea) {
    if (index >= 0 && index < IDEAS_COUNT) {
        ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < IDEAS_COUNT) {
        return ideas[index];
    }
    return "";
}

void Brain::printIdeas() const {
    std::cout << "Brain ideas:" << std::endl;
    for (int i = 0; i < 5; i++) {  // Print first 5 ideas
        if (!ideas[i].empty()) {
            std::cout << "  [" << i << "]: " << ideas[i] << std::endl;
        }
    }
}
