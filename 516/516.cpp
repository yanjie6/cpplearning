//#include<iostream>
//using namespace std;
//
////初始化列表
//class person {
//public:
//	////传统初始化操作
//	//person(int a, int b, int c)
//	//{
//	//	m_a = a;
//	//	m_b = b;
//	//	m_c = c;
//	//}
//
//	//初始化列表初始化属性
//	person(int a,int b,int c) :m_a(a), m_b(b), m_c(c)
//	{
//	}
//
//	int m_a;
//	int m_b;
//	int m_c;
//};
//
//
//void test01()
//{
//		person p(30,20,10);
//	cout << "a = " << p.m_a << endl;
//	cout << "b = " << p.m_b << endl;
//	cout << "c = " << p.m_c << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//}


//
//#include<iostream>
//#include<string>
//using namespace std;
//
////类对象作为类成员
//
////手机类
//class phone
//{
//public:
//	phone(string pname)
//	{
//		cout << "phone的构造函数调用" << endl;
//		m_pname = pname;
//	}
//	//手机品牌名称
//	string m_pname;
//
//	~phone() {
//		cout << "phone的析构函数调用" << endl;
//	}
//};
//
////人 类
//class person
//{
//public:
//	person(string name, string pname):m_name(name),m_phone(pname)
//	{
//		cout << "person的构造函数调用" << endl;
//	}
//
//	//姓名
//	string m_name;
//	//手机
//	phone m_phone;
//
//	~person() {
//		cout << "person析构函数调用" << endl;
//	}
//
//};
////当其他类对象作为本类成员，构造时候先构造类对象，再构造自身
////析构的顺序与构造相反
//
//void test01() {
//	person p("aa", "iphone");
//	cout << p.m_name << "手机"<< p.m_phone.m_pname << endl;
//}
//
//int main()
//{
//	test01();
//
//	system("pause");
//		return 0;
//}
//
