
/*友元
#include<iostream>
using namespace std;
#include<string>

class building
{
	//good全局函数是building类的好朋友，可以访问building类中的私有成员和公有成员
	friend void good(building* building);

public:
	building() {
		m_sittingroom = "客厅";
		m_bedroom = "卧室";
	}
public:
	string m_sittingroom;

private:
	string m_bedroom;
};

//全局函数
void good(building* building)
{
	cout << "好的全局函数 正在访问：" << building->m_sittingroom << endl;
	cout << "好的全局函数 正在访问：" << building->m_bedroom << endl;
}

void test01() {
	building building;
	good(&building);
}
int main() {
	test01();
	system("pause");
	return 0;
}*/


/*
#include<iostream>
using namespace std;
#include<string>
//类做友元
class Building;
class good {
	public:
		good();
		void visit();//参观函数，访问Building中的属性
		Building* building;//在good类中声明一个Building类的指针,指向good（）构造函数中创建的Building对象，以便在visit函数中访问Building对象的属性
};
class Building
{
	//good类是building类的好朋友，可以访问building类中的私有成员和公有成员
	friend class good;

public:Building();
public:
	string m_sittingroom;//客厅
private:
		string m_bedroom;//卧室
};

//类外写成员函数
Building::Building() {
	m_sittingroom = "客厅";
	m_bedroom = "卧室";
}

good::good() {
	//在good类的构造函数中创建一个Building对象
	building = new Building;
}

void good::visit() {
	cout << "好的类 正在访问：" << building->m_sittingroom << endl;
	cout << "好的类 正在访问：" << building->m_bedroom << endl;
}
void test01() {
	good g;
	g.visit();
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

class Building;
class good {
public:
	good();

	void visit();//让visit函数可以访问Building中私有成员
	void visit2();//让visit2不可以访问Building中私有成员
	
	Building* building;
};

class Building {

	friend void good::visit();
public:

	Building();//Building类的构造函数，初始化成员变量

public:

	string m_sittingroom;
	
private:

	string m_bedroom;
};

//类外写成员函数
Building::Building() {
	m_sittingroom = "客厅";
	m_bedroom = "卧室";
}

good::good() {
	building = new Building;
}

void good::visit() {
	cout << "visit 正在访问：" << building->m_sittingroom << endl;
	cout << "visit 正在访问：" << building->m_bedroom << endl;

}
void good:: visit2() {
	cout << "visit2 正在访问：" << building->m_sittingroom << endl;
	//cout << "visit2 正在访问：" << building->m_bedroom << endl;
}

void test01() {
	good g;
	g.visit();
	g.visit2();
}

int main() {
	test01();
	system("pause");
	return 0;
}

*/