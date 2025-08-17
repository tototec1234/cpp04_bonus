#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
    std::cout << "type: " << type << ", this: " << this << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &animalType) : type(animalType) {
    std::cout << "WrongAnimal parameterized constructor called" << std::endl;
    std::cout << "type: " << type << ", this: " << this << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    std::cout << "type: " << type << ", this: " << this << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

// 注意: 非virtualデストラクタなので多態性での適切な破棄順序は保証されない
WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
    std::cout << "非virtualデストラクタなので多態性での適切な破棄順序は保証されない" << std::endl;
    std::cout << "type: " << type << ", this: " << this << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal makes a wrong sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}
