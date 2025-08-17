#include "Animal.hpp"
#include "AnsiColor.hpp"

Animal::Animal() : type("Animal") {
    std::cout << BLUE_COLOR << "Animal default constructor called        this: " << this << RESET_COLOR << std::endl;
}

Animal::Animal(const std::string &animalType) : type(animalType) {
    std::cout << BLUE_COLOR << "Animal parameterized constructor called this: " << this << RESET_COLOR << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
    std::cout << BLUE_COLOR << "Animal copy constructor called           this: " << this << RESET_COLOR << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    std::cout << BLUE_COLOR << "Animal assignment operator called       this: " << this << RESET_COLOR << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << BLUE_COLOR << "Animal destructor called                this: " << this << RESET_COLOR << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}
