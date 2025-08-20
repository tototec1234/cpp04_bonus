/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor_exception_demo.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:25:00 by toruinoue          #+#    #+#             */
/*   Updated: 2025/08/20 09:25:00 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <new>

// コンストラクタでの例外処理をシミュレートするためのクラス
class FailingBrain {
public:
    FailingBrain() {
        std::cout << "  📝 FailingBrain constructor - 必ず失敗します" << std::endl;
        throw std::bad_alloc();  // 必ず例外を投げる
    }
    
    FailingBrain(const FailingBrain &) {
        std::cout << "  📝 FailingBrain copy constructor - 必ず失敗します" << std::endl;
        throw std::bad_alloc();  // 必ず例外を投げる
    }
    
    ~FailingBrain() {
        std::cout << "  ♻️ FailingBrain destructor" << std::endl;
    }
};

class TestAnimal {
public:
    TestAnimal() {
        std::cout << "  🔵 TestAnimal constructor" << std::endl;
    }
    
    TestAnimal(const std::string &type) {
        std::cout << "  🔵 TestAnimal parameterized constructor: " << type << std::endl;
    }
    
    TestAnimal(const TestAnimal &) {
        std::cout << "  🔵 TestAnimal copy constructor" << std::endl;
    }
    
    ~TestAnimal() {
        std::cout << "  🔵 TestAnimal destructor" << std::endl;
    }
};

class TestCat : public TestAnimal {
private:
    FailingBrain* brain;
    
public:
    // デフォルトコンストラクタ - new Brain()で失敗
    TestCat() : TestAnimal("Cat") {
        std::cout << "  🐱 TestCat default constructor called" << std::endl;
        this->brain = new FailingBrain();  // ← ここで必ず例外発生
        std::cout << "  ❌ この行は実行されません" << std::endl;
    }
    
    // コピーコンストラクタ - new Brain(*other.brain)で失敗
    TestCat(const TestCat &other) : TestAnimal(other) {
        std::cout << "  🐱 TestCat copy constructor called" << std::endl;
        this->brain = new FailingBrain(*other.brain);  // ← ここで必ず例外発生
        std::cout << "  ❌ この行は実行されません" << std::endl;
    }
    
    ~TestCat() {
        std::cout << "  🐱 TestCat destructor called" << std::endl;
        delete this->brain;
    }
};

void demonstrateDefaultConstructorException() {
    std::cout << "\n🎯 === デフォルトコンストラクタでの例外処理 ===" << std::endl;
    std::cout << "Cat cat; で new Brain() が失敗する場合\n" << std::endl;
    
    try {
        std::cout << "🔄 TestCat cat; を実行中..." << std::endl;
        TestCat cat;  // ← デフォルトコンストラクタで例外発生
        
        std::cout << "❌ この行は実行されません - catオブジェクトは存在しません" << std::endl;
        
    } catch (const std::bad_alloc &e) {
        std::cout << "\n🚨 デフォルトコンストラクタで例外発生！" << std::endl;
        std::cout << "❌ new Brain() が失敗しました" << std::endl;
        std::cout << "📋 例外メッセージ: " << e.what() << std::endl;
        
        std::cout << "\n🔍 重要なポイント:" << std::endl;
        std::cout << "・catオブジェクトは作成されませんでした" << std::endl;
        std::cout << "・TestCatのデストラクタは呼ばれません" << std::endl;
        std::cout << "・TestAnimalのデストラクタは自動的に呼ばれます" << std::endl;
        std::cout << "・変数catは存在しません（スコープ外）" << std::endl;
    }
    
    std::cout << "\n✨ try-catch ブロック終了" << std::endl;
    // ここでcatは存在しません
}

void demonstrateCopyConstructorException() {
    std::cout << "\n🎯 === コピーコンストラクタでの例外処理 ===" << std::endl;
    std::cout << "Cat cat2(cat1); で new Brain(*other.brain) が失敗する場合\n" << std::endl;
    
    try {
        // まず正常なダミーオブジェクトを作成（簡易版）
        std::cout << "🔄 まず、コピー元として使える別のオブジェクトがあると仮定..." << std::endl;
        TestCat dummyOriginal;  // これは失敗するので、実際は別の方法で
        
    } catch (const std::bad_alloc &) {
        std::cout << "🚨 予想通り、元オブジェクトも作成失敗" << std::endl;
        
        std::cout << "\n📝 コピーコンストラクタ失敗の説明:" << std::endl;
        std::cout << "もし元オブジェクトが存在していて..." << std::endl;
        std::cout << "TestCat cat2(original); を実行した場合:" << std::endl;
        std::cout << "・TestAnimal copy constructor が実行される" << std::endl;
        std::cout << "・TestCat copy constructor が開始される" << std::endl;
        std::cout << "・new FailingBrain(*other.brain) で例外発生" << std::endl;
        std::cout << "・cat2オブジェクトは作成されない" << std::endl;
        std::cout << "・TestCatのデストラクタは呼ばれない" << std::endl;
        std::cout << "・TestAnimalのデストラクタは自動的に呼ばれる" << std::endl;
    }
}

int main() {
    std::cout << "🎯 === Constructor Exception Handling Demo ===" << std::endl;
    
    demonstrateDefaultConstructorException();
    demonstrateCopyConstructorException();
    
    std::cout << "\n🏁 プログラム正常終了" << std::endl;
    return 0;
}

/*
コンパイル・実行:
cd /Users/toruinoue/CPP/0817cpp04/ex01 && c++ -Wall -Wextra -Werror -std=c++98 constructor_exception_demo.cpp -o constructor_exception_demo && ./constructor_exception_demo
*/
