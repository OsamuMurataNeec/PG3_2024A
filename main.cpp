#include <iostream>
using namespace std;


// 自作クラス
class MyClass {
public:
    void Update();

    void func1();
    void func2();
	void func3();
	// メンバ関数ポインタのテーブル
    static void (MyClass::* table[])();
	bool end_flag = false;
private:
    int index = 0;
};

void MyClass::func1(){
    cout << "敵が接近、こっちくんな" << endl;
}

void MyClass::func2(){
	cout << "敵の攻撃！本当に撃ちやがった！" << endl;
}

void MyClass::func3() {
	cout << "敵が撤退！！逃げんな！" << endl;
}

void MyClass::Update() {
	(this->*table[index])();

	puts("数字を入力…ゼロで次に移行");
	int a;
	scanf_s("%d",&a);

	if (a == 0)
		if (index == 2)
			index = 0;
		else
			index++;
	else if (a == 1)
		end_flag = true;
}

// staticで宣言したメンバ関数ポインタテーブルの実体
void (MyClass::* MyClass::table[])() = {
  &MyClass::func1,	// 要素番号0
  &MyClass::func2,	// 要素番号1
  &MyClass::func3	// 要素番号1
};


int main()
{
    MyClass my;

	while(my.end_flag == false)
		my.Update();

	return 0;
}

/*
class CSAMPLE
{
	private:
		void Func01();	// 何かする関数1
		void Func02();	// 何かする関数2
		void Func03();	// 何かする関数3

		void ( CSAMPLE::*m_pFunc[3] )();	// 関数ポインタの配列

	public:
		// コンストラクタ
		CSAMPLE():m_FuncCount(0)
		{
			m_pFunc[0] = &CSAMPLE::Func01;	// Func01 のアドレスをセット
			m_pFunc[1] = &CSAMPLE::Func02;	// Func02 のアドレスをセット
			m_pFunc[2] = &CSAMPLE::Func03;	// Func03 のアドレスをセット
		}

		// CSAMPLE::UpDate() を呼ぶことで
		// セットされている関数を実行する
		void UpDate()
		{
			(this->*m_pFunc[m_FuncCount])();
		}

};
*/