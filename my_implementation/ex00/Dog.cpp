#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog default constructor called" << std::endl;
    std::cout << "type: " << type << ", this: " << this << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    std::cout << "type: " << type << ", this: " << this << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

// 注意: 派生クラスデストラクタは基底クラスより先に実行されるため、typeメンバはまだ有効
Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    std::cout << "派生クラスデストラクタは基底クラスより先に実行されるため、typeメンバはまだ有効" << std::endl;
    std::cout << "type: " << type << ", this: " << this << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}
