//#include<iostream>
//using namespace std;
//
////静态成员变量
//class person {
//public:
//
//	//所有成员共享一份数据
//	//编译阶段就分配内存
//	//类内声明，类外初始化
//	static int m_A;
//
//	//静态成员变量也是有访问权限的
//private:
//	static int m_b;
//
//
//};
//
//int person::m_A = 100;//初始化
//int person::m_b = 200;
//
//
//void test01() {
//	person p;
//	cout << p.m_A << endl;
//
//	person P2;
//	P2.m_A = 200;
//	cout << p.m_A << endl;
//}
//
//void test02() {
//	//静态成员变量 不属于某个对象上，所有对象都共享同一份数据
//	//因此静态成员变量有两种访问方式
//
//	//1.对象访问
//	//person p;
//	//cout << p.m_A << endl;
//
//	//2.类名访问
//	cout << person::m_A << endl;
//
//
//	//类外不可访问私有作用域的
//	//cout << person::m_b << endl;
//}
//
//int main()
//{
//	//test01();
//	test02();
//
//	system("pause");
//	return 0;
//}


/*
#include<iostream>
using namespace std;

//静态成员函数
//所有对象共享一份函数
//静态成员函数只能访问静态成员变量，不能访问非静态成员变量


//解释：  静态成员函数是属于类的，而不是属于某个对象实例，独立存在，
//        非静态成员，仅当实例化对象之后才存在
//		静态成员函数 产生在前，非静态成员函数 产生在后     静态函数无法访问一个不存在的东西


class person {
public:
	//静态成员函数
	static void func() {
		m_A = 100;//静态成员函数可以访问静态成员变量

		//m_B = 200;      //静态成员函数不能访问非静态成员变量，无法区分是哪个对象的m_B

		cout << "static void func调用" << endl;
	}

	static int m_A;//静态成员变量
	int m_B;//非静态成员变量


	//静态成员函数也是有访问权限的
	private:
		static void func2() {
		cout << "static void func2调用" << endl;
	}

};

int person::m_A = 10;

//两种访问方式
void test01() {

	//1.对象访问
	person p;
	p.func();

	//2.类名访问
	person::func();
	//person::func2(); // 私有静态成员函数，类外不可访问
}


int main()
{
	test01();

	system("pause");
	return 0;
}*/





/*
#include<iostream>
using namespace std;

//成员变量 和 成员函数 分开存储

class person {

	int m_A;//非静态成员变量  属于类的对象      //只有这个是

	static int m_B;//静态成员变量  不属于类的对象

	void func() {
		//非静态成员函数  不属于类的对象
	}
	static void func2() {}//静态成员函数  不属于类的对象
};

int person::m_B = 0;

void test01() {
	person p;
	//空对象 占用的内存空间 为1字节，不能为0字节，因为每个对象都必须有一个独一无二的地址   区分空对象占内存的位置
	cout << "sizeo of p =" << sizeof(p) << endl;
}

void test02() {
		person p;
	cout << "sizeo of p =" << sizeof(p) << endl;
}

int main() {
		//test01();
	test02();

	system("pause");
	return 0;
}*/


/*
#include<iostream>
using namespace std;

class person {
public:
	person(int age)//构造函数
	{
		//this指针指向的是被调用的成员函数所属的对象
		this->age = age;
	}

	//以值返回的话会创建一个新对象，不是p2
	//以引用返回的话就不会创建新对象，返回的就是p2本身
	person & personaddage(person& p) {
		this->age += p.age;
		//this指向p2的指针，而*this指向p2对象本身
		return *this;
	}

	int age;
};

//1.解决名称冲突
void test01() {
	person p1(18);
	cout<<"p1的年龄为："<<p1.age<<endl;
}

//2.返回对象本身用*this
void test02() {
	person p1(10);
	person p2(10);
	//p2.personaddage(p1);
	p2.personaddage(p1).personaddage(p1).personaddage(p1);//链式编程思想
	cout << "p2的年龄为：" << p2.age << endl;
}


int main() {

	//test01();

	test02();

	system("pause");
	return 0;
}
*/


/*
#include<iostream>
using namespace std;

//空指针调用成员函数

class person {
public:
	void showclassname() {
		cout << "this is person class" << endl;
	}

	void showpersonage() {
		//报错的原因是因为传入的指针是为NULL
		if (this == NULL)
		{
			return;
		}
		cout << "age=" << m_age << endl;
	}

	int m_age;
};

void test01() {
	person* p = NULL;
	p->showclassname();
	p->showpersonage();
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

//常函数
class person {
public:

	//this指针的本质  是指针常量  指向p  指针的指向是不可修改的
	
	//this 相当于person*const this     指向的值是可以修改的
	
	//在成员函数后面加const，修饰的是this指向，让指针指向的值也不可修改

	void showperson()const
	{
		this->m_B = 200;
		//this->m_A = 100;
		//this=NULL:	//this指针的指向不可修改
	}

	void func() {}//普通成员函数

	int m_A;
	mutable int m_B;//特殊变量，即使在常函数中，也可以修改这个值,加mutable

};

void test01() {
	person p;
	p.showperson();
}

//常对象
void test02() {
	const person p;//在对象前加const，变为常对象
	//p.m_A = 100;//常对象只能访问常函数，常函数中不能修改成员变量的值，所以报错

	p.m_B = 200;//m_B是特殊值，在常对象下也可以修改这个值

	//常对象只能调用常函数，常函数只能访问常对象
	p.showperson();
	//p.func();		//常对象 不可以调用普通成员函数，因为普通成员函数可以修改属性，而常对象不允许修改属性，所以报错
}


int main() {
		test01();
	system("pause");
	return 0;	
}
*/