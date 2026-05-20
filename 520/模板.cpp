

#include<iostream>
using namespace std;


/*
//函数模板

//交换两个整型函数
void swapint(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//交换两个浮点型函数
void swapdouble(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}

//函数模板
template<typename T>	//声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用数据类型
void myswap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


void test01() {
	int a = 10;
	int b = 20;

	//swapint(a, b);
	//利用函数模板交换
	//两种方式使用函数模板
	//1.自动类型推导
	//myswap(a, b);
	//2.显示指定类型
	myswap<int>(a, b);

	cout << "a=" << a << "  b=" << b << endl;

	double c = 1.11;
	double d = 2.22;

	//swapdouble(c, d);
	//cout << "c=" << c << "  d=" << d << endl;

}


int main() {
	test01();
	system("pause");
	return 0;
}
*/



/*
//函数模板注意事项
template<class T>//typename可以替换成class
void myswap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//1.自动类型推导，必须推导出一致的数据类型T才可以使用
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	//myswap(a, b);	//对
	//myswap(a, c);	//错，推导不出一致的T类型
}

//2.模板必须要确定出T的数据类型，才可以使用
template<class T>
void func() {
	cout << "func调用"<< endl; 
}

void test02() {
	func<int>();//要确定T类型
}

int main() {
	test02();
	return 0;
}
*/


/*
//案例
//实现通用 对数组进行排序的函数
//规则 从大到小
//算法 选择
//测试 char 数组，int 数组
 

//交换函数模板
template<class T>
void myswap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//排序算法
template<class T>
void mysort(T arr[],int len)
{
	for (int i = 0; i < len; i++) 
	{
		int max = i;//认定最大值的下标
		for (int j = i + 1; j < len; j++)//拿后面的数和第一个比较，得到全部数的最大值下标，排在第一个，i=1时，又得到第二大数
		{
			//认定的最大值 比 遍历出的数值 小 ，说明j下标的元素才是真正的最大值
			if (arr[max] < arr[j])
			{
				max = j;//更新最大值下标
			}
		}
		if (max != i)
		{
			//交换max和i 元素
			myswap(arr[max], arr[i]);
		}
	}
}

//提供打印数组模板
template<class T>
void printarray(T arr[], int len)
{
	int i = 0;
	for (i; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


void test01() {
	//测试char 数组
	char chararr[] = "badfe";
	int num = sizeof(chararr) / sizeof(char);
	mysort(chararr,num);
	printarray(chararr, num);
}

void test02()
{
	//测试int数组
	int intarr[] = { 7,43,5,6,2 };
	int num = sizeof(intarr) / sizeof(int);
	mysort(intarr, num);
	printarray(intarr, num);
}

int main() {
	test01();
	test02();
	return 0;
}
*/



/*
//普通函数和函数模板的区别

//1.普通函数调用可以发生隐式类型转换
//2.函数模板 用自动类型推导，不可以发生隐式类型转换
//3.函数模板 用显示指定类型 ，可以发生

//普通函数
int myadd01(int a, int b)
{
	return a + b;
}

//函数模板
template<class T>
T myadd02(T a, T b)
{
	return a + b;
}

void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << myadd01(a, c) << endl;//输出109    ascii+a  发生了隐式转换

	//自动类型推导
	cout << myadd02(a, b) << endl;//不可以用c

	//显示指定类型
	cout<<myadd02<int>(a, c) << endl;
}


int main() {
	test01();
	return 0;
}

*/




/*
//普通函数和函数模板的调用规则
//1.如果函数模板和普通函数都可以调用，优先调用普通
//2.可以通过空模板参数列表 强制调用 函数模板
//3.函数模板可以发送函数重载
//4.如果函数模板可以产生更好的匹配，优先调用函数模板


template<class T>
void myprint(T a,T b)
{
	cout << "调用的模板" << endl;
}

template<class T>
void myprint(T a, T b,T c)
{
	cout << "调用的重载模板" << endl;
}

void myprint(int a, int b)
{
	cout << "调用普通函数" << endl;
}

void test01() 
{
	int a = 10;
	int b = 20;
	myprint(a, b);

	//通过空模板参数列表 强制调用 函数模板
	myprint<>(a, b);

	myprint(a, b, 100);

	//更好的匹配
	char c1 = 'a';
	char c2 = 'b';
	myprint(c1, c2);//普通函数可以发生隐式转换			但是模板更好匹配
}

int main() {
	test01();
	return 0;
}*/



/*
#include<string>
//模板的界限性
//需要用具体化方式做特殊实现

class person {
public:
	person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	//姓名
	string m_name;
	//年龄
	int m_age;

};

//对比两个数据是否相等函数
template<class T>
bool mycompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
		return false;
}

//利用具体化person的版本实现代码，具体化优先调用
template<>bool mycompare(person & p1,person & p2)
{
	if (p1.m_age == p2.m_age && p1.m_name == p2.m_name)
		return true;
	else
		return false;
}

void test01() {
	int a = 10;
	int b = 20;
	bool ret = mycompare(a, b);
	if (ret)
	{
		cout << "a==b" << endl;
	}
	else
	{
		cout << "a!=b" << endl;
	}
}

void test02() {
	person p1("tom", 10);
	person p2("tom", 10);
	bool ret = mycompare(p1, p2);
	if (ret)
	{
		cout << "p1==p2" << endl;
	}
	else
	{
		cout << "p1!=+p2" << endl;
	}
}

int main()
{
	test01();
	test02();
	return 0;
}
*/



/*
#include<string>
//类模板
template<class nametype,class agetype>
class person
{
public:
	person(nametype name, agetype age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	void showperson() {
		cout << "name" << this->m_name << endl;
		cout << "age" << this->m_age << endl;
	}

	nametype m_name;
	agetype m_age;
};

void test01() 
{
	person<string,int> p1("tom", 18);
	p1.showperson();
}

int main() {
	test01();
	return 0;
}
*/



/*
//类模板  函数模板  区别

#include<string>

template<class nametype, class agetype=int>
class person
{
public:
	person(nametype name, agetype age)
	{
		this->m_name = name;
		this->m_age = age;
	}

	void showperson() {
		cout << "name" << this->m_name << endl;
		cout << "age" << this->m_age << endl;
	}

	nametype m_name;
	agetype m_age;
};

//1.类模板没有自动类型推导使用方式
void test01()
{
	//person p("tom", 18);  错误 ，无法用自动类型推导
	person<string, int>p("tom", 18);//正确，只能用显示指定类型
}

//2.类模板在模板参数列表中可以有默认参数
void test02()
{
	person<string>p("jerry", 18);//int省略因为在template那里添加了=int

}

int main()
{
	test01();
	return 0;
}
*/




/*
//类模板中成员函数创建时机
//类模板成员函数在调用时才创建

class person1
{
public:
	void showperson1()
	{
		cout << "person1 show" << endl;
	}
};

class person2
{
public:
	void showperson2()
	{
		cout << "person2 show" << endl;
	}
};

template<class T>
class myclass
{
public:
	T obj;

	//类模板中成员函数
	void func1() {
		obj.showperson1();
	}
	void func2() {
		obj.showperson2();
	}
};


void test01()
{
	myclass<person1>m;//类型是person1，所以func1可以调用person1类中的showperson1函数
	m.func1();
	m.func2();
}

int main()
{
	test01();
	return 0;
}
*/



//





void test01()
{

}
int main() {
	test01();
	return 0;
}




















































































































































