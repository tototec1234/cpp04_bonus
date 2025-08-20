/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_flow_demo.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 08:52:00 by toruinoue          #+#    #+#             */
/*   Updated: 2025/08/20 08:52:00 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

// 例外処理の流れを段階的に説明するためのデモクラス
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

void demonstrateExceptionFlow() {
    std::cout << "\n🎯 === new失敗時の例外処理の流れ ===" << std::endl;
    std::cout << "（step-by-step 説明）\n" << std::endl;
    
    SimpleDemo obj;
    std::cout << "📊 初期状態: data = " << obj.data << " (値: " << *obj.data << ")" << std::endl;
    
    std::cout << "\n🔄 Step 1: try文に入る" << std::endl;
    try {
        std::cout << "   ↓ try ブロック開始" << std::endl;
        
        std::cout << "\n⚡ Step 2: new操作実行" << std::endl;
        std::cout << "   ↓ new int[巨大サイズ] を実行..." << std::endl;
        
        // 意図的に大量メモリを要求してbad_allocを発生
        size_t huge_size = 1000000000000UL;  // 1TBのint配列
        int* newData = new int[huge_size];
        
        std::cout << "   ✅ new成功（予想外！）" << std::endl;
        std::cout << "\n📝 Step 3: 正常処理継続" << std::endl;
        std::cout << "   ↓ 古いデータ削除" << std::endl;
        delete obj.data;
        std::cout << "   ↓ 新しいデータ設定" << std::endl;
        obj.data = newData;
        
        std::cout << "   ✅ すべて正常完了" << std::endl;
        
    } catch (const std::bad_alloc &e) {
        std::cout << "\n🚨 Step 2b: 例外発生！" << std::endl;
        std::cout << "   ↓ new操作が失敗しました" << std::endl;
        std::cout << "   ↓ std::bad_alloc例外が投げられました" << std::endl;
        std::cout << "   ↓ catch文にジャンプ！" << std::endl;
        
        std::cout << "\n🛡️ Step 3b: 例外処理" << std::endl;
        std::cout << "   ↓ エラーメッセージ: " << e.what() << std::endl;
        std::cout << "   ↓ オブジェクト状態は変更されていません" << std::endl;
        std::cout << "   📊 data = " << obj.data << " (元のまま)" << std::endl;
        
        std::cout << "\n✨ Step 4b: 安全に回復" << std::endl;
        std::cout << "   ↓ プログラムはクラッシュしません" << std::endl;
        std::cout << "   ↓ 元のデータは保持されています" << std::endl;
    }
    
    std::cout << "\n🎉 Step 4: 処理継続" << std::endl;
    std::cout << "   ↓ try-catch後の処理実行" << std::endl;
    std::cout << "   📊 最終状態: data = " << obj.data << " (値: " << *obj.data << ")" << std::endl;
}

int main() {
    demonstrateExceptionFlow();
    std::cout << "\n🏁 プログラム正常終了" << std::endl;
    return 0;
}

/*
コンパイル・実行コマンド:
cd /Users/toruinoue/CPP/0817cpp04/ex01 && c++ -Wall -Wextra -Werror -std=c++98 exception_flow_demo.cpp -o exception_flow_demo && ./exception_flow_demo
*/
