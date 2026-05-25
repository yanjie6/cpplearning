
#include<iostream>
using namespace std;


/*
#include<vector>
#include<algorithm>
//vector容器存放内置数据类型

void myprint(int val) {
	cout << val << endl;
}
void test01()
{
	//创建了一个vector容器，数组
	vector<int> v;

	//向容器中插入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	////通过迭代器访问容器中的数据
	//vector<int>::iterator itBegin = v.begin();//起始迭代器  指向容器中第一个元素
	//vector<int>::iterator itEnd = v.end();//结束迭代器   指向容器中最后一个元素的下一个位置

	////第一种遍历方式
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	//第二种遍历方式
	//for (vector<int>::iterator it = v.begin(); it != v.end();it++)
	//{
	//	cout << *it << endl;
	//}

	//第三种遍历方式		利用STL提供遍历算法
	for_each(v.begin(), v.end(), myprint);


}
int main()
{
	test01();
	system("pause");
	return 0;
}
*/



/*
#include<vector>
#include<string>
//vector容器中存放自定义数据类型
class person
{
public:
	person(string name, int age)
	{
		this->m_age = age;
		this->m_name = name;
	}

	string m_name;
	int m_age;
};


void test01() {
	vector<person> v;

	person p1("zan", 18);
	person p2("han", 28);
	person p3("zsan", 38);
	person p4("zngsan", 48);
	person p5("zngsan", 58);

	//向容器中添加数据
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//遍历容器中的数据
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名:  " << (*it).m_name << "年龄： " << it->m_age << endl;
	}
}

//存放自定义数据类型 指针
void test02()
{
	vector<person*> v;

	person p1("zan", 18);
	person p2("han", 28);
	person p3("zsan", 38);
	person p4("zngsan", 48);
	person p5("zngsan", 58);

	//向容器中添加数据
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	//遍历容器
	for (vector<person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名:  " << (**it).m_name << "年龄： " << (*it)->m_age << endl;
	}
}


int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
*/



/*
//vector容器嵌套容器
#include<vector>
#include<string>

void test01()
{
	vector<vector<int>>v;
	//创建小容器
	vector<int>v1;
	vector<int>v2;

	//向小容器中添加数据
	for (int i = 0; i < 2; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
	}

	//将小容器插入到大容器中
	v.push_back(v1);
	v.push_back(v2);

	//通过大容器，遍历所有数据
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		//(*it) ---- 容器 vector<int>
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << "  ";
		}
		cout<< endl;
	}
}

int main() {
	test01();
	return 0;
}
*/


