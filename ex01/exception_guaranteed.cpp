/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_guaranteed.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:15:00 by toruinoue          #+#    #+#             */
/*   Updated: 2025/08/20 09:15:00 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <new>

// 強制的に例外を発生させるクラス
class ForceException {
public:
    ForceException() {
        // nothrow版を使わずに、明示的に例外を投げる
        throw std::bad_alloc();
    }
};

class SimpleDemo {
public:
    int* data;
    
    SimpleDemo() {
        std::cout << "📝 SimpleDemo constructor" << std::endl;
        data = new int(42);
    }
    
    ~SimpleDemo() {
        std::cout << "♻️ SimpleDemo destructor" << std::endl;
        delete data;
    }
};

void demonstrateGuaranteedExceptionFlow() {
    std::cout << "\n🎯 === 例外発生保証デモ ===" << std::endl;
    std::cout << "（必ず例外が発生するパターン）\n" << std::endl;
    
    SimpleDemo obj;
    std::cout << "📊 初期状態: data = " << obj.data << " (値: " << *obj.data << ")" << std::endl;
    
    std::cout << "\n🔄 Step 1: try文に入る" << std::endl;
    try {
        std::cout << "   ↓ try ブロック開始" << std::endl;
        
        std::cout << "\n⚡ Step 2: 必ず失敗する操作実行" << std::endl;
        std::cout << "   ↓ ForceException() を実行（必ず例外発生）..." << std::endl;
        
        // 必ず例外を発生させる
        ForceException* forcedFail = new ForceException();
        
        std::cout << "   ❌ この行は実行されません！" << std::endl;
        std::cout << "\n📝 Step 3: 到達不可能コード" << std::endl;
        delete obj.data;
        obj.data = reinterpret_cast<int*>(forcedFail);
        
    } catch (const std::bad_alloc &e) {
        std::cout << "\n🚨 Step 2b: 例外発生！（予想通り）" << std::endl;
        std::cout << "   ↓ ForceException()が失敗しました" << std::endl;
        std::cout << "   ↓ std::bad_alloc例外が投げられました" << std::endl;
        std::cout << "   ↓ catch文にジャンプ！" << std::endl;
        
        std::cout << "\n🛡️ Step 3b: 例外処理" << std::endl;
        std::cout << "   ↓ エラーメッセージ: " << e.what() << std::endl;
        std::cout << "   ↓ オブジェクト状態は変更されていません" << std::endl;
        std::cout << "   📊 data = " << obj.data << " (値: " << *obj.data << ") - 元のまま！" << std::endl;
        
        std::cout << "\n✨ Step 4b: 安全に回復" << std::endl;
        std::cout << "   ↓ プログラムはクラッシュしません" << std::endl;
        std::cout << "   ↓ 元のデータは完全に保持されています" << std::endl;
    }
    
    std::cout << "\n🎉 Step 4: 処理継続" << std::endl;
    std::cout << "   ↓ try-catch後の処理実行" << std::endl;
    std::cout << "   📊 最終状態: data = " << obj.data << " (値: " << *obj.data << ")" << std::endl;
    std::cout << "   ✅ 完全に元の状態を維持！" << std::endl;
}

void simulateAssignmentOperatorException() {
    std::cout << "\n🔧 === 代入演算子での例外シミュレーション ===" << std::endl;
    
    std::cout << "📝 改修前の危険な実装をシミュレート:" << std::endl;
    std::cout << "   1. delete this->brain  ← 先に削除" << std::endl;
    std::cout << "   2. this->brain = new Brain(...)  ← ここで例外発生" << std::endl;
    std::cout << "   結果: brainポインタがダングリング状態！\n" << std::endl;
    
    std::cout << "✅ 改修後の安全な実装:" << std::endl;
    std::cout << "   1. Brain* newBrain = new Brain(...)  ← 先に新しいもの作成" << std::endl;
    std::cout << "   2. delete this->brain  ← 成功後に削除" << std::endl;
    std::cout << "   3. this->brain = newBrain" << std::endl;
    std::cout << "   結果: 例外発生時もオブジェクト状態保持！" << std::endl;
}

int main() {
    std::cout << "🎯 === Guaranteed Exception Flow Demo ===" << std::endl;
    
    demonstrateGuaranteedExceptionFlow();
    simulateAssignmentOperatorException();
    
    std::cout << "\n🏁 プログラム正常終了 - 例外は適切に処理されました！" << std::endl;
    return 0;
}

/*
コンパイル・実行:
cd /Users/toruinoue/CPP/0817cpp04/ex01 && c++ -Wall -Wextra -Werror -std=c++98 exception_guaranteed.cpp -o exception_guaranteed && ./exception_guaranteed
*/

/*


*/