
//多态是c++面向对象三大特性之一
//多态 分类
//静态多态：函数重载 和 运算符重载属于静态多态，复用函数名
//动态多态：派生类和虚函数实现运行时多态

//静态 和动态多态的区别
//静态多态的函数地址早绑定  编译阶段确定函数地址
//动态多态的函数地址晚绑定  运行阶段确定函数地址



/*
#include<iostream>
using namespace std;

//动物类
class animal {
public:
	//虚函数

	virtual void speak() {
		cout << "动物在说话" << endl;
	}
};

//猫类
class cat :public animal
{
public:
	void speak() {
		cout << "小猫在说话" << endl;
	}
};

//狗类
class dog :public animal
{
public:
	void speak() {
		cout << "小狗在说话" << endl;
	}
};

//执行说话函数
//地址早绑定  在编译阶段确定函数地址
//如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定


//动态多态满足条件
//1.有继承关系
//2.子类重写父类的虚函数
//							重写：函数返回值类型 函数名 参数列表  完全相同
//当重写   子类中的虚函数表 内部 会替换成 子类的虚函数地址（原本因为继承内部是父类的地址）
//vfptr   虚函数指针

//动态多态使用
//父类的指针或者引用 指向子类对象   例如56行

void dospeak(animal& animal) //animal &animal=cat;
{
	animal.speak();

}

void test01() {
	cat cat;
	dospeak(cat);

	dog dog;
	dospeak(dog);
}

void test02() {
	cout << "sizeof animal = " << sizeof(animal) << endl;//不加virtual 为1   加了为 4 or 8
}
int main() {
	//test01();
	test02();
	system("pause");
	return 0;
}
*/


/*
//eg  分别用普通写法和多态技术  ，设计实现两个操作数进行运算的计算器类
#include<iostream>
using namespace std;
#include<string>

//普通写法
class calculator
{
public:
	int getresult(string oper) {
		if (oper == "+")
			return m_num1 + m_num2;
		else if (oper == "-")
			return m_num1 - m_num2;
		else if (oper == "*")
			return m_num1 * m_num2;
		//如果想扩展新的功能，需求修改源码
		//在真实开发中 提倡 开闭原则
		//开闭原则：对扩展进行开放 ，对修改进行关闭
	}

	int m_num1;
	int m_num2;
};


void test01() {
	//创建计算器对象
	calculator c;
	c.m_num1 = 10;
	c.m_num2 = 10;

	cout << c.m_num1 << "+" << c.m_num2 << "=" << c.getresult("+") << endl;
	cout << c.m_num1 << "-" << c.m_num2 << "=" << c.getresult("-") << endl;
	cout << c.m_num1 << "*" << c.m_num2 << "=" << c.getresult("*") << endl;
}

//利用多态实现计算器
//好处：
//1.组织结构清晰
//2.可读性强
//3.对于前期和后期扩展以及维护性高

//实现计算器抽象类
class abstractcalculator 
{
public:
	virtual int getresult() {
		return 0;
	}
	int m_num1;
	int m_num2;
};

//加法计算器类
class addcalculator :public abstractcalculator {
public:
	int getresult() {
		return m_num1 + m_num2;
	}
};

//减法
class subcalculator :public abstractcalculator {
public:
	int getresult() {
		return m_num1 - m_num2;
	}
};

//乘法
class mulcalculator :public abstractcalculator {
public:
	int getresult() {
		return m_num1 * m_num2;
	}
};

void test02() {
	//多态使用条件
	//父类指针或者引用指向子类对象

	//加法运算
	abstractcalculator* abc = new addcalculator;//为什么要创建在堆区
	abc->m_num1 = 10;
	abc->m_num2 = 10;
	cout << abc->m_num1 << "+" << abc->m_num2 << "=" << abc->getresult() << endl;
	//用完记得销毁
	delete abc;//是将堆区的数据释放了

	//减法
	abc = new subcalculator;
	abc->m_num1 = 10;
	abc->m_num2 = 10;
	cout << abc->m_num1 << "-" << abc->m_num2 << "=" << abc->getresult() << endl;
	delete abc;

	//乘法
	abc = new mulcalculator;
	abc->m_num1 = 10;
	abc->m_num2 = 10;
	cout << abc->m_num1 << "*" << abc->m_num2 << "=" << abc->getresult() << endl;
	delete abc;
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

//纯虚函数和抽象类
class Base
{
public:
	//纯虚函数
	//只要有一个纯虚函数，这个类称为抽象类
	//抽象类特点：
	//1.无法实例化对象
	//2.抽象类的子类，必须重写父类中的纯虚函数，否则也属于抽象类
	virtual void func() = 0;
};

class son :public Base
{
public:

	virtual void func() {
		cout << "func调用" << endl;
	};
};

void test01() {
	//Base b;		//抽象类无法实例化对象
	//new Base;		//抽象类无法实例化对象

	//son s;		//子类必须重写父类中的纯虚函数，否则无法实例化对象
	
	Base* base = new son;
	base->func();
}

int main() {
	test01();
	system("pause");
	return 0;
}
*/


/*
//eg   制作饮品

#include<iostream>
using namespace std;

class abstructdrinking {
public:
	//煮水
	virtual void boil() = 0;

	//冲泡
	virtual void brew() = 0;

	//倒入杯子
	virtual void pourincup() = 0;

	//加入辅料
	virtual void putsomething() = 0;

	//制作饮品
	void makedrink() {
		boil();
		brew();
		pourincup();
		putsomething();
	}
};

//制作咖啡
class coffee :public abstructdrinking {
public:
	//煮水
	virtual void boil() {
		cout << "煮水" << endl;
	}

	//冲泡
	virtual void brew() {
		cout << "冲泡咖啡" << endl;
	}

	//倒入杯子
	virtual void pourincup() {
		cout << "倒入杯中" << endl;
	}

	//加入辅料
	virtual void putsomething() {
		cout << "加入牛奶" << endl;
	}

	//制作饮品
	void makedrink() {
		boil();
		brew();
		pourincup();
		putsomething();
	}
};


//制作茶
class tea :public abstructdrinking {
public:
	//煮水
	virtual void boil() {
		cout << "煮水" << endl;
	}

	//冲泡
	virtual void brew() {
		cout << "冲泡茶叶" << endl;
	}

	//倒入杯子
	virtual void pourincup() {
		cout << "倒入杯中" << endl;
	}

	//加入辅料
	virtual void putsomething() {
		cout << "加入枸杞" << endl;
	}

	//制作饮品
	void makedrink() {
		boil();
		brew();
		pourincup();
		putsomething();
	}
};

//制作函数
void dowork(abstructdrinking*abs) {
	abs->makedrink();
	delete abs;
}

void test01() {
	//制作咖啡
	dowork(new coffee);

	//制作茶
	dowork(new tea);
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

//虚析构 和 纯虚析构

class animal
{
public:
	//纯虚函数
	virtual void speak() = 0;

	animal() {
		cout << "animal构造函数调用" << endl;
	}

	//利用虚析构可以解决 父类指针释放子类对象时不干净的问题
	//virtual ~animal() {
	//	cout << "animal析构函数调用" << endl;
	//}

	//纯虚析构		需要声明  也需要实现
	virtual ~animal() = 0;

};
animal::~animal() {
	cout << "animal纯虚析构函数调用" << endl;
}

class cat :public animal
{
public:
	cat(string name)
	{
		cout << "cat构造函数调用" << endl;
		m_name=new string(name);
	}

	virtual void speak() {
		cout <<* m_name<<"小猫在说话" << endl;
	}

	~cat() {
		if (m_name != NULL)
		{
			cout << "cat析构函数调用" << endl;
			delete m_name;
			m_name = NULL;
		}
	}

	string* m_name;
};

void test01() {
	animal* animal = new cat("tom");
	animal->speak();
	//父类指针在析构时候 不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄露
	delete animal;
}

int main() {
	test01();
	system("pause");
	return 0;
}
*/


/*
//eg   电脑组装
#include<iostream>
using namespace std;


//抽象不同零件类
//抽象cpu类
class cpu {
public:
	//抽象的计算函数
	virtual void calculate() = 0;
};

//抽象显卡类
class videocard {
public:
	//抽象的计算函数
	virtual void display() = 0;
};

//抽象内存条类
class memory {
public:
	//抽象的计算函数
	virtual void storage() = 0;
};

//电脑类
class  computer
{
public:
	computer(cpu* cpu, videocard* vc, memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}

	//提供工作函数
	void work() {
		//让零件工作起来，调用接口
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}

	//提供析构函数  释放3个电脑零件
	~computer() {
		if (m_cpu != NULL) {
			delete m_cpu;
			m_cpu = NULL;
		}
		if(m_vc!=NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL)
		{
			delete m_mem ;
			m_mem = NULL;
		}
	}
private:
	cpu* m_cpu;//cpu的零件指针
	videocard*m_vc;
	memory* m_mem;

};


//具体厂商
//intel
class intelcpu :public cpu
{
public:
	virtual void calculate()
	{
		cout << "intel的cpu开始计算" << endl;
	}
};

class intelvideocard :public videocard
{
public:
	virtual void display()
	{
		cout << "intel的显卡开始显示" << endl;
	}
};

class intelmemory :public memory
{
public:
	virtual void storage()
	{
		cout << "intel的内存条开始存储" << endl;
	}
};

//lenovo
class lenovocpu :public cpu
{
public:
	virtual void calculate()
	{
		cout << "lenovo的cpu开始计算" << endl;
	}
};

class lenovovideocard :public videocard
{
public:
	virtual void display()
	{
		cout << "lenovo的显卡开始显示" << endl;
	}
};

class lenovomemory :public memory
{
public:
	virtual void storage()
	{
		cout << "lenovo的内存条开始存储" << endl;
	}
};


void test01() {
	//第一台电脑零件
	cpu*Intelcpu = new intelcpu;
	videocard* Intelvideocard = new intelvideocard;
	memory* Intelmem = new intelmemory;
	
	//创建第一台电脑
	//computer c1(Intelcpu, Intelvideocard, Intelmem);
	//c1.work();//视频例子是创建在堆区
	computer* computer1 = new computer(Intelcpu, Intelvideocard, Intelmem);
	computer1->work();
	delete computer1;

	cout << "-----------------------------" << endl;

	//第二
	//不同创建方式
	computer* computer2 = new computer( new lenovocpu, new intelvideocard, new lenovomemory);
	computer2->work();
	delete computer2;

	cout << "-----------------------------" << endl;
}



int main() {
	test01();
	system("pause");
	return 0;
}

*/













