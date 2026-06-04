#include<iostream>
using namespace std;
#include<algorithm>
#include<functional>
#include<numbers>
#include<vector>


/*
//for_each
//实现遍历容器

//普通函数
void print01(int val)
{
	cout << val << " ";
}
//仿函数
class print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(),print01 );//第三项只放函数名称，不需要加（）
	cout << endl;

	for_each(v.begin(), v.end(), print02());
	cout << endl;

}
int main()
{
	test01();
	return 0;
}
*/


/*
//transform
//搬运容器到另一个容器中

class Transform
{
public:
	int operator()(int v)
	{
		return v;//可以用return v+10000  之类的做运算
	}
};

class print {
public:
	void operator()(int v)
	{
		cout << v << " ";
	}
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>vTarget;//目标容器
	vTarget.resize(v.size());//目标容器 需要提前开辟空间

	transform(v.begin(), v.end(), vTarget.begin(), Transform());

	for_each(vTarget.begin(), vTarget.end(), print());
	cout << endl;

}
int main()
{
	test01();
	return 0;
}
*/