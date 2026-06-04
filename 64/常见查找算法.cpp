#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


/*
//find
//查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end（）

//查找内置数据类型
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//查找5
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end())
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到了" << *it << endl;
	}
}

//查找自定义数据类型
class person
{
public:
	person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	//重载==
	bool operator ==(const person& p)
	{
		if ((this->m_age == p.m_age) && (this->m_name == p.m_name))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string m_name;
	int m_age;

 	
};
void test02()
{
	vector<person>v;
	//创建数据
	person p1("aaa", 10);
	person p2("bbb", 20);
	person p3("ccc", 30);

	//放入容器
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	vector<person>::iterator it = find(v.begin(), v.end(), p2);
	if (it == v.end())//计算机不知道比哪一个，所以要重载==号
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到了" << endl;
	}
}

int main()
{
	test01();
	test02();
	return 0;
}
*/




//find_if


