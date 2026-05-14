#include<iostream>
#include<string>
using namespace std;

//构造函数的分类及调用
// 分类
//无参构造(默认构造)   有参构造
//普通构造      拷贝构造
class person
{
public:
	//构造函数
	person()
	{
		cout << "person的无参构造函数调用" << endl;
	}
	person(int a)
	{
		age = a;
		cout << "person的有参构造函数调用" << endl;
	}
	person(const person & p)
	{
		age = p.age;//将传入的all属性全部拷贝到这个身上
		cout << "person的拷贝函数调用" << endl;

	}
	~person()
	{
		cout << "person的析构函数调用" << endl;
	}
	int age;
};

//调用
void test01()
{
	//括号法
	person p1;//默认构造函数调用
	person p2(10);//有参构造函数
	person p3(p2);//拷贝构造函数

	cout << "p2的年龄为：" << p2.age << endl;
	cout << "p3的年龄为：" << p3.age << endl;

	//显示法

	//隐式转换法
}

int main()
{
	test01();

	system("pause");
}