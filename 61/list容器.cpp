#include<iostream>
using namespace std;
#include<list>
#include<string>


//stl中链表是一个双向循环链表
//优点：动态储存分配。不会造成内存浪费和溢出
//插入删除方便
//缺点：占用内存大，访问慢


//list容器构造函数
void printlist(const list<int>& l)
{
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


/*
void test01()
{
	//创建list容器
	list<int>l1;	//默认构造

	//添加数据
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);

	//遍历容器
	printlist(l1);

	///区间方式构造
	list<int>l2(l1.begin(), l1.end());

	printlist(l2);

	//拷贝构造
	list<int>l3(l1);
	printlist(l3);

	//n个elem
	list<int>l4(10, 1000);
	printlist(l4);

	}

int main() {
	test01();
	return 0;
}
*/


/*
//list容器赋值和交换
void test01()
{
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);

	printlist(l1);

	list<int>l2;
	l2 = l1;	//operator=赋值
	printlist(l2);

	list<int>l3;
	l3.assign(l2.begin(), l2.end());
	printlist(l3);

	list<int>l4;
	l4.assign(10, 1000);
	printlist(l4);
}

//交换
void test02()
{
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);

	list<int>l2;
	l2.assign(10, 100);

	cout << "交换前：" << endl;
	printlist(l1);
	printlist(l2);

	l1.swap(l2);

	cout << "交换后:" << endl;
	printlist(l1);
	printlist(l2);
}

int main() {
	test02();
	return 0;
}
*/


/*
//list容器的大小操作
void test01()
{
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);

	printlist(l1);

	//判断容器是否为空
	if (l1.empty())
	{
		cout << "l1为空" << endl;
	}
	else
	{
		cout << "l1不为空" << endl;
		cout << "l1的元素个数为：" << l1.size() << endl;
	}

	//重新指定大小
	l1.resize(10);//l1.resize(10,10000);默认值为0，可以指定其他
	printlist(l1);

	l1.resize(2);
	printlist(l1);

}

int main() {
	test01();
	return 0;
}
*/


/*
//list插入和删除
void test01() {
	list<int>l;

	//尾插
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);

	//头插
	l.push_front(100);
	l.push_front(200);
	l.push_front(300);

	printlist(l);

	//尾删
	l.pop_back();
	printlist(l);

	//头删
	l.pop_front();
	printlist(l);

	//insert插入
	list<int>::iterator it = l.begin();
	l.insert(++it, 1000);//先加再插入
	printlist(l);

	//删除
	it = l.begin();
	l.erase(it);
	printlist(l);

	//移除
	l.push_back(10000);
	l.push_back(10000);
	l.push_back(10000);
	printlist(l);

	l.remove(10000);//remove会删除容器中所有值为10000的元素
	printlist(l);

	//清空
	l.clear();
	printlist(l);

}
int main() {
	test01();
	return 0;
}
*/


/*
//list数据存取
void test01()
{
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);

	//l1[0]  不可以用[]访问list容器中的元素
	//l1.at(0) 也不可以用at访问list容器中的元素

	//原因：list本质是链表，不是用连续线性空间储存数据，迭代器不支持随机访问

	cout << "第一个元素为：" << l1.front() << endl;
	cout << "最后一个元素为：" << l1.back() << endl;

	//验证迭代器是不支持随机访问的
	list<int>::iterator it = l1.begin();
	it++;
	it--;//支持双向访问
	//it=it+1;不支持随机访问，因为it++和it=it+1的底层实现不一样，it++是迭代器自己重载的，而it=it+1是随机访问迭代器才支持的


}
int main()
{
	test01();
	return 0;
}
*/




/*
//list反转和排序
void test01() {
	//反转
	list<int>l1;

	l1.push_back(10);
	l1.push_back(50);
	l1.push_back(30);
	l1.push_back(20);

	cout << "反转前：" << endl;
	printlist(l1);

	//反转
	l1.reverse();
	cout << "反转后:" << endl;
	printlist(l1);

}
//排序
bool mycompare(int v1, int v2)
{
	//降序
	return v1 > v2;
}

void test02() {
	list<int>l1;
	l1.push_back(10);
	l1.push_back(30);
	l1.push_back(50);
	l1.push_back(20);

	cout << "排序前：" << endl;
	printlist(l1);

	//所有不支持随机访问迭代器的容器，不可以使用标准算法algorithm
	cout << "排序后：" << endl;
	//不支持随机访问迭代器的容器，内部会提供对应的算法

	l1.sort();//从小到大  默认
	printlist(l1);

	l1.sort(mycompare);
	printlist(l1);

}
int main() {
	test02();
	return 0;
}
*/


/*
//排序案例
//将person按照年龄排序，一样的按身高

class person
{
public:
	person(string name, int age, int height)
	{
		this->m_name = name;
		this->m_height = height;
		this->m_age = age;
	}
	string m_name;
	int m_age;
	int m_height;
};

//指定排序规则
bool comparepeson(person p1, person p2)
{
	//年龄升序
	if (p1.m_age == p2.m_age)
	{
		//身高降序
		return p1.m_height > p2.m_height;
	}
	else
	{
		return p1.m_age < p2.m_age;
	}
}

void test01()
{
	list<person>l;//创建容器

	//准备数据
	person p1("aaa", 20, 180);
	person p2("bbb", 30, 170);
	person p3("ccc", 20, 150);
	person p4("ddd", 50, 160);
	person p5("eee", 30, 150);
	person p6("fff", 70, 160);

	//插入数据
	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.push_back(p6);

	for (list<person>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << "姓名：" << it->m_name << " 年龄：" << it->m_age << " 身高：" << it->m_height << endl;
	}

	//排序
	cout << "-------------------------" << endl;
	cout << "排序后：" << endl;

		l.sort(comparepeson);

	for (list<person>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << "姓名：" << it->m_name << " 年龄：" << it->m_age << " 身高：" << it->m_height << endl;
	}

}
int main() {
	test01();
	return 0;
}
*/
