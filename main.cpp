#include <iostream>
using namespace std;


// 自作クラス
class MyClass {
public:
    void Update();
    void func1();
    void func2();
    // メンバ関数ポインタのテーブル
    static void (MyClass::* table[])();
private:
    int index = 0;
};

void MyClass::func1(){
    cout << "1" << endl;
}

void MyClass::func2(){
	cout << "2" << endl;
}

void MyClass::Update() {
	(this->*table[index])();
}

// staticで宣言したメンバ関数ポインタテーブルの実体
void (MyClass::* MyClass::table[])() = {
  &MyClass::func1,	// 要素番号0
  &MyClass::func2	// 要素番号1
};


int main()
{
    MyClass my;

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