# CPP04 - Subtype Polymorphism, Abstract Classes, and Interfaces

## 課題概要
42Tokyo CPP04モジュール - サブタイプ多態性、抽象クラス、インターフェースの学習

## Exercise 構成
- **ex00**: Polymorphism (多態性)
- **ex01**: Deep Copy (深いコピー)
- **ex02**: Abstract Class (抽象クラス)  
- **ex03**: Interface (インターフェース)

## 重要概念

### virtualキーワードの真の意味
C++の`virtual`は日本語の「仮想」ではなく、英語の「実質的な」「事実上の」「機能的に同等」を意味します。

#### 語源
- **Latin**: `virtus` (力、効力、美徳)
- **Medieval Latin**: `virtualis` (潜在的な力を持つ)  
- **Modern English**: `virtual` (実質的な、事実上の、機能的に同等)

#### 実装での意味
```cpp
Animal* ptr = new Dog();
ptr->makeSound();  // virtualにより「実質的に」Dog::makeSound()が呼ばれる
```

## 参考文献

### 公式ドキュメント (日本語)
- [Microsoft Learn - virtual (C++)](https://learn.microsoft.com/ja-jp/cpp/cpp/virtual-cpp?view=msvc-170)
- [IBM Documentation - 仮想関数 (C++ のみ)](https://www.ibm.com/docs/ja/i/7.2?topic=only-virtual-functions-c)

### 技術解説 (日本語)
- [Programming Place Plus - 仮想メソッド用語集](https://programming-place.net/ppp/contents/cpp/language/024.html)
- [C++入門 - 仮想関数](https://beginner-engineer-study.com/virtual-function/)
- [まくまくC++ノート - virtual関数とオーバーライド](https://maku77.github.io/cpp/virtual.html)
- [フルキタプログラマー - 仮想関数とオーバーライド](https://frkz.jp/study/cpp/virtual-func-override)

### 公式文献 (英語)
- [C++ Reference - Virtual function](https://en.cppreference.com/w/cpp/language/virtual)
- [ISO C++ FAQ - Virtual Functions](https://isocpp.org/wiki/faq/virtual-functions)

### 設計哲学
- Bjarne Stroustrup, "The Design and Evolution of C++"
- Scott Meyers, "Effective C++" - Item 7: Declare destructors virtual in polymorphic base classes

## コンパイル方法
```bash
make        # ビルド
make clean  # オブジェクトファイル削除
make fclean # 全て削除
make re     # 再ビルド
```

## 実行例
```bash
./polymorphism  # ex00の実行
./brain_test    # ex01の実行
```

## 学習のポイント
1. **virtual関数**: 実行時多態性の実現
2. **深いコピー**: メモリ管理とリソース管理
3. **抽象クラス**: 純粋仮想関数による設計
4. **デストラクタ順序**: 派生→基底の破棄順序

---
*42Tokyo CPP04 Module Implementation*
