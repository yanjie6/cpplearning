
//运算符重载



/*
//加号

#include<iostream>
using namespace std;

class person {
public:

	//1.成员函数重载+号
	//person operator+(person& p)
	//{
	//	person temp;
	//	temp.m_A = this->m_A + p.m_A;
	//	temp.m_B = this->m_B + p.m_B;
		//return temp;
	//}
	int m_A;
	int m_B;

};

//2.全局函数重载+号
person operator+(person& p1, person& p2) {
	person temp;
	temp.m_A = p1.m_A + p2.m_B;
	temp.m_B = p1.m_A + p2.m_B;
	return temp;
}

//函数重载的版本
person operator+(person& p, int num) {
	person temp;
	temp.m_A = p.m_A + num;
	temp.m_B = p.m_B + num;
	return temp;
}

void test01()
{
	person p1;
	p1.m_A = 10;
	p1.m_B = 10;

	person p2;
	p2.m_A = 10;
	p2.m_B = 10;

	//成员函数重载本质调用
	//person p3 = p1.operator+(p2);

	//全局函数本质调用
	//person p3 = operator+(p1, p2);

	person p3 = p1 + p2;//两种方法

	//运算符重载也可以发生函数重载
	person p4 = p1 + 10;  //person +int

	cout << p3.m_A << endl;
	cout << p3.m_B << endl;
	cout <<"p4  " <<p4.m_A << endl;
	cout <<"p4  "<< p4.m_B << endl;
}

int main() {
	test01();
	system("pause");
	return 0;
}
*/


/*
//左移运算符
#include<iostream>
using namespace std;

class person
{
	friend std::ostream& operator<<(ostream& cout, person& p);

public:
	//利用成员函数重载 左移运算符      p.operator<<(cout)的简化版本是p<<cout
	//但是我们一般写cout<<p,这个简化版本无法实现cout在左侧，所以不会利用成员函数重载<<运算符
	//void operator<<(cout){}
	person(int a, int b) {
		m_A = a;
		m_B = b;
	}
	
private:
	int m_A;
	int m_B;


};

//利用全局函数重载左移运算符
std::ostream& operator<<(ostream &cout,person &p)   //本质   operator<<(cout,p) 简化  cout<<p
{
	cout << p.m_A  << p.m_B;
	return cout;
}

void test01() {
	person p(10, 10);
	//p.m_A = 10;
	//p.m_B = 10;

	cout << p << endl;     //直接输出p的所有值
}

int main() {

	test01();
	system("pause");
	return 0;
}
*/




/*
#include<iostream>
using namespace std;

//递增运算符


//自定义整型
class Myinteger
{
	friend ostream& operator<<(ostream& cout, Myinteger myint);
public:
	Myinteger() {
		m_num = 0;
	}

	//重载前置++运算符
	Myinteger & operator++()//根据之前知识，用&返回的是本身，不会创建新对象,可以连续了
	{
		//先进行++运算
		m_num++;
		//再将自身做返回
		return *this;
	}
	//重载后置++运算符
	//int  代表占位参数，可以用于区分前置和后置递增
	Myinteger operator++(int)//不加&，因为返回的话是temp，而temp在函数结束后就释放，后面就是非法操作
	{
		//先  记录当时结果
		Myinteger temp = *this;
		//后 递增
		m_num++;

		//最后将记录结果做返回
		return temp;
	}


private:
	int m_num;
};

//重载<<运算符
ostream& operator<<(ostream& cout, Myinteger myint)
{
	cout << myint.m_num;
	return cout;
}


void test01() {
	Myinteger myint;

	//cout << myint << endl;//左移重载
	cout << ++myint << endl;
	cout << myint << endl;
}
void test02()
{
	Myinteger myint;
	cout << myint++ << endl;
	cout << myint << endl;

}

int main() {
	test01();
	test02();
	system("pause");
		return 0;
}

*/


/*
//赋值运算符
#include<iostream>
using namespace std;

class person
{
public:
	person(int age)
	{
		m_age = new int(age);//
	}

	~person() {
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}
	}

	//重载赋值运算符
	person& operator=(person& p)
	{
		//编译器提供浅拷贝
		//m_age = p.m_age;

		//应该先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
		if (m_age != NULL)
		{
			delete m_age;//释放旧的堆内存，防止泄露
			m_age = NULL;
		}
		//深拷贝
		m_age = new int(*p.m_age);

		//返回对象本身，链式思想
		return *this;
	}

	int* m_age;
};

void test01() {
	person p1(18);

	cout << "p1的年龄" << *p1.m_age << endl;

	person p2(20);

person p3(30);

	p2 = p1;

	p3 = p2 = p1;//赋值操作

	cout << "p2的年龄" << *p2.m_age << endl;

	cout << "p3的年龄" << *p3.m_age << endl;
}


int main() {
	test01();
	system("pause");
	return 0;
}*/


/*
#include<iostream>
using namespace std;

//关系运算符重载   

class person {
public:
	person(string name, int age)//写了有参构造函数，编译器就不给普通的了，创建对象时要传参数
	{
		m_name = name;
		m_age = age;
	}


//重载==

bool operator==(person& p)
{
	if (this->m_name == p.m_name && this->m_age == p.m_age)
		return true;
	return false;
}

//重载！=

bool operator!=(person& p)
{
	if (this->m_age != p.m_age || this->m_name != p.m_name)
		return true;
	return false;
}

	string m_name;
	int m_age;
};



void test01() {
	person p1("tom", 18);

	person p2("gone", 18);

	if (p1 == p2)//要重载==
	{
		cout << "p1 p2相等" << endl;
	}
	else
	{
		cout << "p1 p1不相等" << endl;
	}
	if (p1 != p2)//要重载!=
	{
		cout << "p1 p2不相等" << endl;
	}
	else
	{
		cout << "p1 p1相等" << endl;
	}
}

int main() {
	test01();
	system("pause");
	return 0;
}
*/



/*
#include<iostream>
using namespace std;
#include<string>
//函数调用运算符重载(仿函数）

//打印输出类
class Myprint {
public:
	//重载函数调用运算符
	void operator()(string test)
	{
		cout << test << endl;
	}
};

void Myprint01(string test) {
	cout << test << endl;
}

void test01() {
	Myprint myprint;
	myprint("hello world");//函数调用运算符重载      由于使用起来特别像函数调用，所以成为仿函数

	Myprint01("hello world");//函数调用
}

//仿函数非常灵活，没有固定写法

//加法类

class Myadd
{
public:
	int operator()(int num1,int num2) {
		return num1 + num2;
	}
};

void test02() {
	Myadd myadd;
	int ret=myadd(100, 200);
	cout << ret << endl;

	//匿名函数对象
	cout << Myadd()(100, 200) << endl;//当前行运行完就被释放
}


int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
*/

