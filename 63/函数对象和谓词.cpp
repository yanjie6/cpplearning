#include<iostream>
using namespace std;
#include<string>

//函数对象(仿函数）

//重载函数调用操作符的类，其对象成为函数对象
//函数对象重载()叫做仿函数
//可以作为参数传递

/*
class add
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

//1.使用时可以像普通函数一样调用，可以有参数，可以有返回值
void test01()
{
	add myadd;
	cout << myadd(10, 10) << endl;
}

//2.函数对象超出普通函数概念，可以有自己的状态
class myprint
{
public:
	myprint()
	{
		this->count = 0;
	}

	void operator()(string test)
	{
		cout << test << endl;
		count++;
	}

	int count;//内部自己状态
};

void test02()
{
	myprint myprint;//构造是才会调用一次默认构造，下面的调用不会进行默认构造
	myprint("hello world");
	myprint("hello world");
	myprint("hello world");
	
	cout << "调用次数" << myprint.count << endl;

}

//3.函数对象可以作为参数传递
void doprint(myprint& p, string test)
{
	p(test);
}
void test03()
{
	myprint print;
	doprint(print, "hello");
}



int main()
{
	test01();
	test02();
	test03();
	return 0;
}
*/



#include<vector>
#include<algorithm>
//谓词
//返回bool类型的仿函数称为谓词
//operator（）接受一个参数，叫做一元谓词
//				接受两个参数，叫做二元谓词


/*
//一元谓词
class greaterfive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//查找容器中，有没有大于5的数
	vector<int>::iterator it = find_if(v.begin(), v.end(), greaterfive());//第三个参数用的是匿名函数对象，此题方便，也可以创建然后放进去
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了大于5数字为" << *it << endl;//因为是找到了之后就立即break，所以只会返回第一个符合条件的数
	}

}

int main() {
	test01();
	return 0;
}
*/


/*
//二元谓词
class mycompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(20);
	v.push_back(50);

	sort(v.begin(), v.end());

	for (vector<int>::iterator it = v.begin();it!=v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//使用函数对象 改变算法策略，变为降序
	sort(v.begin(), v.end(), mycompare());

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
}*/