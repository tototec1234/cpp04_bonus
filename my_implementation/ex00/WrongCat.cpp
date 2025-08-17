#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat default constructor called" << std::endl;
    std::cout << "type: " << type << ", this: " << this << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    std::cout << "type: " << type << ", this: " << this << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    std::cout << "WrongCat assignment operator called" << std::endl;
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

// 警告: WrongAnimalは非virtualデストラクタなので、ポインタ経由でのdeleteでは呼ばれない可能性
WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
    std::cout << "WrongAnimalは非virtualデストラクタなので、ポインタ経由でのdeleteでは呼ばれない可能性" << std::endl;
    std::cout << "type: " << type << ", this: " << this << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Wrong Meow! (This won't be called in polymorphism)" << std::endl;
}
