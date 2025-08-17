#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog();

    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    ~Dog();
    
    void makeSound() const;
};

#endif
    /*
    コピーコンストラクタは基底クラス(Animal)のコピーコンストラクタを呼び出すだけで、
    Dogクラス固有のメンバ変数を持たないため、明示的な実装は不要です。
    コンパイラが生成するデフォルトのコピーコンストラクタで十分です。
    */