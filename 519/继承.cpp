/*
#include<iostream>
using namespace std;

//普通实现页面
//
////Java页面
//class Java
//{
//public:
//	void header() {
//		cout << "首页、公开课、登陆、注册...（公共头部）"<<endl;
//	}
//
//	void footer() {
//		cout << "帮助中心、交流合作、站内地图...(公共底部）" << endl;
//	}
//
//	void left() {
//		cout << "Java、Python、c++...(公共分类列表）" << endl;
//	}
//	void content() {
//		cout << "Java学科视频" << endl;
//	}
//};
//
////Python页面
//class Python
//{
//public:
//	void header() {
//		cout << "首页、公开课、登陆、注册...（公共头部）" << endl;
//	}
//
//	void footer() {
//		cout << "帮助中心、交流合作、站内地图...(公共底部）" << endl;
//	}
//
//	void left() {
//		cout << "Java、Python、c++...(公共分类列表）" << endl;
//	}
//	void content() {
//		cout << "Python学科视频" << endl;
//	}
//};
//
////c++页面
//class cpp
//{
//public:
//	void header() {
//		cout << "首页、公开课、登陆、注册...（公共头部）" << endl;
//	}
//
//	void footer() {
//		cout << "帮助中心、交流合作、站内地图...(公共底部）" << endl;
//	}
//
//	void left() {
//		cout << "Java、Python、c++...(公共分类列表）" << endl;
//	}
//	void content() {
//		cout << "c++学科视频" << endl;
//	}
//};


//继承实现页面
//继承的好处：减少重复的代码
//语法：class 子类 : 继承方式 父类
//子类也称为派生类
//父类     基类

class BasePage {
public:
	void header() {
		cout << "首页、公开课、登陆、注册...（公共头部）" << endl;
	}

	void footer() {
		cout << "帮助中心、交流合作、站内地图...(公共底部）" << endl;
	}

	void left() {
		cout << "Java、Python、c++...(公共分类列表）" << endl;
	}
	
};

//Java页面
class Java :public BasePage//继承
{
public:
	void content() {
		cout << "Java学科视频" << endl;
	}
};

//Python页面
class Python :public BasePage//继承
{
public:
	void content() {
		cout << "python学科视频" << endl;
	}
};

//cpp页面
class cpp :public BasePage//继承
{
public:
	void content() {
		cout << "cpp学科视频" << endl;
	}
};

void test01() {
	cout << "Java下载视频页面如下:" << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();

	cout << endl << "----------------------------" << endl;
	cout << "Python下载视频页面如下:" << endl;
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();

	cout << endl << "----------------------------" << endl;
	cout << "c++下载视频页面如下:" << endl;
	cpp c;
	c.header();
	c.footer();
	c.left();
	c.content();
}

int main() {
	test01();
	system("pause");
	return 0;
}
*/


/*
//继承方式

//公共继承
class Base1 {
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};

class son1 :public Base1
{
public:
	void func() {
		m_a = 10;//说明父类中的公共权限成员  到子类中依然是公共权限
		m_b = 10;//说明父类中的保护权限成员  到子类中依然是保护权限
		//m_c = 10;//父类中的私有权限成员   子类访问不到
	}
};

void test01() {
	son1 s1;
	s1.m_a = 100;
	//s1.m_b = 100;//到son1中m_b是保护权限   类外访问不到
}


//保护继承
class Base2 {
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};

class son2 :protected Base2 {
public:
	void func() {
		m_a = 100;//说明父类中的公共权限成员  到子类中  是 保护权限
		m_b = 100;//说明父类中的保护权限成员  到子类中依然是保护权限
		//m_c = 100;//父类中的私有权限成员   子类访问不到
	}
};


void test02() {
	son2 s1;
	//s1.m_a = 1000;    //在son2中m_a变为保护权限，因此类外访问不到
	//s1.m_b=1000;      //son2中m_b为保护权限  类外访问不到
}


//私有继承
class Base3 {
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};

class son3 :private Base3 {
public:
	void func() {
		m_a = 100;//父类公共  到子类  变 私有
		m_b = 100;//父类保护  到子类  变 私有
		//m_c = 100;////父类中的私有权限成员   子类访问不到
	}
};

class gradson3 :public son3 {
	void func() {
		//m_a = 1000;//是son3中私有成员，son3的子类访问不到
	}
};


void test03() {
	son3 s1;
	//s1.m_a = 1000;		//到son3中变为私有成员   类外访问不到
	//s1.m_b = 1000;		//到son3中变为私有成员   类外访问不到
}*/



/*
#include<iostream>
using namespace std;

//继承中的对象模型

class Base {
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};

class son :public Base {
public:
	int m_d;
};

//利用开发人员命令提示工具查看对象模型
//跳转盘符 D:
//跳转文件路径  cd 具体路径下
//查看命令     cl \d1 reportSingleClassLayout类名 文件名（按tab自动补齐）

void test01() {
	//16
	//父类中所有非静态成员属性都会被子类继承下去
	//父类私有成员属性 是被编译器给隐藏了，因此是访问不到，但是确实被继承下去了
	cout << "sizeof son=" << sizeof(son) << endl;
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

//继承中的构造和析构顺序

class Base {
public:
	Base() {
		cout << "Base的构造函数" << endl;
	}

	~Base() {
		cout << "Base的析构函数" << endl;
	}
};

class son :public Base
{
public:
	son() {
		cout << "son的构造函数" << endl;
	}

	~son() {
		cout << "son的析构函数" << endl;
	}
};

void test01() {
	//Base b;

	//继承中的构造和析构顺序如下：
	//先构造父类，再构造子类，  析构的顺序与构造相反
	son s;
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

//继承中同名成员处理
class Base {
public:
	Base() {
		m_a = 100;
	}

	void func() {
		cout << "Base  func()调用" << endl;
	}

	void func(int a) {
		cout << "Base  func(int a)调用" << endl;
	}

	int m_a;
};

class son :public Base {
public:

	son() {
		m_a = 200;
	}

	void func() {
		cout << "son  func()调用" << endl;
	}

	int m_a;
};


//同名成员属性处理
void test01() {
	son s;
	cout << "son m_a=" << s.m_a << endl;
	
	//如果通过子类对象，访问到父类中同名成员,需要加作用域
	cout << "Base m_a=" << s.Base::m_a << endl;

}

//同名成员函数处理
void test02() {
	son s;
	s.func();//直接调用   调用的是子类中的同名成员

	//如何调用父类中同名成员函数    加作用域
	s.Base::func();


	//如果子类中出现和父类同名的成员函数，子类的同名函数会隐藏掉父类中所有同名成员函数
	//如果想访问到父类中被隐藏的同名成员函数  加作用域
	s.Base::func(100);
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

//继承中的同名静态成员处理方式

class Base
{
public:
	static int m_a;

	static void func() {
		cout << "base  static void func()" << endl;
	}

	static void func(int a) {
		cout << "base  static void func(int a)" << endl;
	}
};

int Base::m_a = 100;

class son:public Base
{
public:
	static int m_a;
	static void func() {
		cout << "son  static void func()" << endl;
	}
};

int son::m_a = 200;

//同名静态成员属性
void test01() {
	//1.通过对象访问数据
	cout << "通过对象访问" << endl;
	son s;
	cout << "son  m_a=" << s.m_a << endl;
	cout << "Base  m_a=" << s.Base::m_a<< endl;

	//2.通过类名访问数据
	cout << "通过类名访问" << endl;
	cout << "son  m_a=" << son::m_a << endl;
	//第一个::代表通过类名方式访问   第二个::代表访问父类作用域下
	cout << "Base  m_a=" << son::Base::m_a<< endl;

}
//同名静态成员函数
void test02() {
	//1.通过对象访问数据
	cout << "通过对象访问" << endl;
	son s;
	s.func();
	s.Base::func();

	//2.通过类名访问数据
	cout << "通过类名访问" << endl;
	son::func();
	son::Base::func();

	//son::func(100);
	son::Base::func(100);
	//如果子类中出现和父类同名的成员函数，子类的同名函数会隐藏掉父类中所有同名成员函数
	//如果想访问到父类中被隐藏的同名成员函数  加作用域
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

//多继承语法

class Base1 {
public:
	Base1() {
		m_a = 100;
	}
	
	int m_a;
};

class Base2 {
public:
	Base2() {
		m_a = 200;
	}

	int m_a;
};

//子类  需要继承Base1 和 Base2 
//语法：  class 子类 ：继承方式 父类1，继承方式 父类2
class son :public Base1, public Base2
{
public:
	son() {
		m_c = 300;
		m_d = 400;
	}

	int m_c;
	int m_d;
};

void test01() {
	son s;
	cout << "sizeof son= " << sizeof(s) << endl;

	//当父类中出现同名成员，需要加作用域区分
	cout << "Base1 :m_a =" << s.Base1::m_a << endl;
	cout << "Base2 :m_a =" << s.Base2::m_a << endl;

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

//菱形继承

//动物类
class animal {
public:
	int m_age;
};

//利用虚继承 解决菱形继承的问题
// 继承之前 加上关键字 virtual 变成虚继承
// animal类成为虚基类

//羊类
class sheep:virtual public animal {};

//驼类
class tuo :virtual public animal {};

//羊驼
class sheeptuo :public sheep, public tuo {};



void test01() {
	sheeptuo st;

	st.sheep::m_age = 18;
	st.tuo::m_age = 28;

	//当菱形继承时，当两个父类拥有相同数据，需要加以作用域区分
	cout << "st.sheep::m_age= " << st.sheep::m_age << endl;
	cout << "st.tuo::m_age= " << st.tuo::m_age << endl;

	//这份数据我们知道，只有一份就可以，但菱形继承导致数据有两份，资源浪费
	cout << "st.m_age" << st.m_age << endl;
}

int main() {
	test01();
	system("pause");
	return 0;
}
*/