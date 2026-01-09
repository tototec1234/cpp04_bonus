# Exercise 03: Interface & recap（インターフェースと復習）

|  Exercise: 03  |   |
| --- | --- |
|  Interface & recap  |   |
|  Turn-in directory: ex03/  |   |
|  Files to turn in: Makefile, main.cpp, *.cpp, *.{h, hpp}  |   |
|  Forbidden functions: None  |   |

C++98にはインターフェースが存在しません（C++20でも存在しません）。しかし、純粋抽象クラスは一般的にインターフェースと呼ばれます。したがって、この最後の演習では、このモジュールを理解していることを確認するために、インターフェースを実装してみましょう。

以下のAMateriaクラスの定義を完成させ、必要なメンバー関数を実装してください。

```cpp
class AMateria
{
protected:
[...]
public:
AMateria(std::string const & type);
[...]
std::string const & getType() const; // マテリアのタイプを返す
virtual AMateria* clone() const = 0;
virtual void use(ICharacter& target);
};
```

Materiaの具象クラスを実装してください：IceとCure。タイプを設定するために、それらの名前を小文字で使用してください（Iceには"ice"、Cureには"cure"）。もちろん、それらのメンバー関数clone()は同じタイプの新しいインスタンスを返します（つまり、Ice Materiaをクローンすると、新しいIce Materiaが得られます）。

use(ICharacter&)メンバー関数は以下を表示します：

- Ice: '* shoots an ice bolt at <name> *'
- Cure: '* heals <name>'s wounds *'

<name>はパラメータとして渡されたCharacterの名前です。角括弧（<と>）は印刷しないでください。

Materiaを別のMateriaに代入する際、タイプをコピーすることは意味がありません。

以下のインターフェースを実装する具象クラスCharacterを記述してください：

```cpp
class ICharacter
{
public:
virtual ~ICharacter() {}
virtual std::string const & getName() const = 0;
virtual void equip(AMateria* m) = 0;
virtual void unequip(int idx) = 0;
virtual void use(int idx, ICharacter& target) = 0;
};
```

Characterは4スロットのインベントリを持ちます。つまり、最大4つのMateriaを持てます。インベントリは構築時には空です。Materiaは最初に見つかった空のスロットに装備されます。順序は次の通りです：スロット0からスロット3まで。満杯のインベントリにMateriaを追加しようとしたり、存在しないMateriaを使用/装備解除しようとした場合、何も起こりません（ただし、バグは依然として禁止されています）。unequip()メンバー関数はMateriaを削除してはいけません！

Characterが床に置いたMateriaの処理は自由に行ってください。unequip()を呼び出す前にアドレスを保存するか、他の方法を使用してください。ただし、メモリリークを避ける必要があることを忘れないでください。

use(int, ICharacter&)メンバー関数は、スロット[idx]のMateriaを使用し、targetパラメータをAMateria::use関数に渡す必要があります。

あなたのCharacterのインベントリは、あらゆるタイプのAMateriaをサポートできる必要があります。

あなたのCharacterは、その名前をパラメータとして取るコンストラクタを持たなければなりません。Characterのコピー（コピーコンストラクタまたはコピー代入演算子を使用）は、ディープコピーでなければなりません。コピー中、CharacterのMateriaは、新しいMateriaがインベントリに追加される前に削除される必要があります。もちろん、Characterが破壊される際にMateriaは削除される必要があります。

以下のインターフェースを実装する具象クラスMateriaSourceを記述してください：

```cpp
class IMateriaSource
{
public:
virtual ~IMateriaSource() {}
virtual void learnMateria(AMateria*) = 0;
virtual AMateria* createMateria(std::string const & type) = 0;
};
```

- learnMateria(AMateria*)
パラメータとして渡されたMateriaをコピーし、後でクローンできるようにメモリに保存します。Characterと同様に、MateriaSourceは最大4つのMateriaを知ることができます。それらは必ずしも一意である必要はありません。

- createMateria(std::string const &)
新しいMateriaを返します。後者は、以前にMateriaSourceによって学習されたMateriaのコピーであり、そのタイプはパラメータとして渡されたタイプと等しいものです。タイプが不明な場合は0を返します。

要するに、あなたのMateriaSourceは、必要に応じてMateriaを作成するために、Materiaの「テンプレート」を学習できる必要があります。その後、そのタイプを識別する文字列を使用して新しいMateriaを生成できるようになります。

このコードを実行すると：

```cpp
int main()
{
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
ICharacter* me = new Character("me");
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
delete bob;
delete me;
delete src;
return 0;
}
```

以下の出力が得られるはずです：

```txt
$> clang++ -W -Wall -Werror *.cpp
$> ./a.out | cat -e
* shoots an ice bolt at bob *$
* heals bob's wounds *$
```

いつものように、上記で与えられたものよりも多くのテストを実装して提出してください。

このモジュールは、exercise 03を行わなくても合格できます。

---

## 提出とピア評価

いつものように、Gitリポジトリに課題を提出してください。評価中は、リポジトリ内の作業のみが評価されます。フォルダとファイルの名前が正しいことを確認してください。

評価中、プロジェクトの簡単な修正が時々要求される場合があります。これには、動作の小さな変更、数行のコードの記述または書き直し、または簡単に追加できる機能が含まれる場合があります。

このステップはすべてのプロジェクトに適用されるわけではありませんが、評価ガイドラインに記載されている場合は、それに備える必要があります。

このステップは、プロジェクトの特定の部分の実際の理解を確認するためのものです。修正は、選択した任意の開発環境（例：通常のセットアップ）で実行でき、数分以内に実行可能である必要があります。ただし、評価の一部として特定の時間枠が定義されている場合を除きます。

例えば、関数やスクリプトの小さな更新、表示の変更、新しい情報を保存するためのデータ構造の調整などが求められる場合があります。

詳細（範囲、ターゲットなど）は評価ガイドラインで指定され、同じプロジェクトでも評価ごとに異なる場合があります。
