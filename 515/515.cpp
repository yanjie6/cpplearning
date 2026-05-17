//#include<iostream>
//using namespace std;
/*
//拷贝构造函数的调用时机

//1.使用一个已经创建完毕的对象来初始化一个新对象

class person
{
public:
	person()
	{
		cout << "person默认构造函数调用" << endl;
	}
	person(int age)
	{
		cout << "person有参构造函数调用" << endl;
		m_age = age;
	}
	person(const person& p)
	{
		m_age = p.m_age;
		cout << "person拷贝构造函数调用" << endl;
	}

	~person()
	{
		cout << "person析构函数调用" << endl;
	}
	int m_age;
};

void test01()
{
	person p1(20);
	person p2(p1);
	cout << "p2的年龄：" << p2.m_age << endl;
}

//2.值传递的方式给函数参数传值
void dowork(person p)
{

}

void test02() {
	person p;
	dowork(p);
}


//3.值方式返回局部对象
person dowork2()
{
	person p1;
	cout << (int*)&p1 << endl;
	return p1;
}
void test03()
{
	person p = dowork2();
	cout << (int*)&p << endl;
}

int main()
{
	//test01();
	//test02();
	test03();
}*/



/*
//构造函数的调用规则
#include<iostream>
using namespace std;

//1.创建一个类，c++编译器会给每个类都添加至少3个函数
//默认构造（空实现
//析构函数（空实现
//拷贝构造（值拷贝

//2.如果我们写了有参构造函数，编译器就不再提供默认构造，依然提供拷贝构造
//如果我们写了拷贝构造函数，编译器就不再提供其他普通构造函数

class person
{
public:
	//person()
	//{
	//	cout << "person默认构造函数调用" << endl;
	//}
	//person(int age)
	//{
	//	cout << "person有参构造函数调用" << endl;
	//	m_age = age;
	//}
	person(const person& p)
	{
		m_age = p.m_age;
		cout << "person拷贝构造函数调用" << endl;
	}
	
	~person()
	{
		cout << "person析构函数调用" << endl;
	}
	int m_age;
};

//void test01()
//{
//	person p;
//	p.m_age = 18;
//	person p2(p);
//	cout << "p2的年龄为：" << p2.m_age << endl;
//}

void test02()
{
	person p;
	//cout << "p1的年龄：" << p1.m_age << endl;
}
int main()
{
	//test01();
	test02();
}*/


//
////面试经典问题：深浅拷贝
//
////浅拷贝问题是堆区的内存重复释放，利用深拷贝解决
//
//#include<iostream>
//using namespace std;
//class person {
//public:
//	person()
//	{
//		cout << "person默认构造函数调用" << endl;
//	}
//	person(int age,int height)
//	{
//		cout << "person有参构造函数调用" << endl;
//		m_age = age;
//		m_height=new int(height);//将数据创建在堆区
//	}
//
//	//自己实现一个拷贝构造函数，解决浅拷贝问题
//	person(const person& p)
//	{
//		cout << "person拷贝构造函数调用" << endl;
//		m_age = p.m_age;
//		//m_height=p.m_height  //编译器默认的拷贝构造函数就是这样写的，导致了浅拷贝问题
//		//深拷贝操作
//
//		m_height = new int(*p.m_height);//将数据创建在堆区，并且将p对象的m_height指向的数据进行复制一份给自己对象的m_height指向
//	}
//
//	~person()
//	{
//		//析构代码，将堆区开辟数据做释放操作
//		if (m_height != NULL)
//		{
//			delete m_height;
//			m_height = NULL;//防止野指针出现，做一个置空操作
//		}
//		cout << "person析构函数调用" << endl;
//	}
//	int m_age;
//	int* m_height;
//};
////栈区：先进的后出
//void test01()
//{
//	person p1(18,160);
//
//	cout << "p1的年龄：" << p1.m_age  << "身高为"<<*p1.m_height<<endl;
//
//	person p2(p1);
//
//	cout << "p2的年龄：" << p2.m_age  << "身高为" <<* p2.m_height << endl;
//}
//
//int main()
//{
//	test01();
//}