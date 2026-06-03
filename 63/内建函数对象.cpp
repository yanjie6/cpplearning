#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//STL内建了一些函数对象:	算术仿函数，关系仿函数，逻辑仿函数
#include<functional>


/*
//算术仿函数
//negate 一元仿函数 取反仿函数

//plus  二元仿函数 加法

void test01() 
{
	negate<int>n;
	cout<<n(50) << endl;
}

void test02()
{
	plus<int>p;
	cout << p(10, 10)<<endl;
}
int main()
{
	test01();
	test02();
	return 0;
}
*/


/*
//关系仿函数
//大于
void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);
	v.push_back(30);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//降序
	sort(v.begin(), v.end(), greater<int>());

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}
int main()
{
	test01();
	return 0;
}
*/



/*
//逻辑仿函数
//逻辑非 logical_not

void test01()
{
	vector<bool>v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//利用逻辑非  将容器v 搬运到 逻辑v2中， 并执行取反操作
	vector<bool>v2;
	v2.resize(v.size());

	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());


	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;


}
int main()
{
	test01();
	return 0;
}
*/