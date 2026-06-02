#include<iostream>
#include<set>
using namespace std;

//set是关联式容器，底层结构用二叉树实现，set容器中元素不允许重复，且元素会自动排序


void printset(set<int>& s)
{
		for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
		cout << endl;
}

/*
//set容器的构造和赋值
void test01()
{
	set<int>s1;

	//插入数据只有insert方式
	s1.insert(10);
	s1.insert(20);
	s1.insert(50);
	s1.insert(30);
	s1.insert(40);

	//遍历容器
	//set容器中元素自动排序,不允许重复
	printset(s1);

	//拷贝构造
	set<int>s2(s1);
	printset(s2);

	//赋值操作
	set<int>s3;
	s3 = s2;
	printset(s3);
}
int main()
{
		test01();
		return 0;
}*/


/*
//set容器的大小和交换

//大小
void test01()
{
	set<int>s1;

	//插入数据
	s1.insert(10);
	s1.insert(20);
	s1.insert(50);

	printset(s1);

	//判断是否为空
	if(s1.empty())
			{
		cout << "s1为空" << endl;
	}
	else
	{
		cout << "s1不为空" << endl;
		cout << "s1的大小为：" << s1.size() << endl;
	}

}

//交换
void test02()
{
	set<int>s1;
	set<int>s2;

	s1.insert(10);
	s1.insert(20);
	s1.insert(50);

	s2.insert(100);
	s2.insert(200);
	s2.insert(500);

	cout << "交换前：" << endl;
	printset(s1);
	printset(s2);

	s1.swap(s2);
	
	cout << "交换后：" << endl;
	printset(s1);
	printset(s2);
}
int main()
{
	test01();
	return 0;
}
*/


/*
//set容器的插入和删除

void test01()
{
	set<int>s1;
	//插入数据
	s1.insert(10);
	s1.insert(20);
	s1.insert(50);
	s1.insert(30);
	s1.insert(40);

	printset(s1);
	
	//删除
	s1.erase(s1.begin());
	printset(s1);
	
	s1.erase(30);
	printset(s1);
	
	//清空
	s1.clear();
	printset(s1);
}
int main()
{
	test01();
	return 0;
}
*/



/*
//set容器的查找和统计

void test01()
{
	set<int>s1;
	//插入数据
	s1.insert(10);
	s1.insert(20);
	s1.insert(50);
	s1.insert(30);
	s1.insert(40);
	printset(s1);
	//查找
	set<int>::iterator pos = s1.find(30);
	if (pos != s1.end())//为什么是end？因为find如果没有找到元素会返回end迭代器
	{
		cout << "找到了元素：" << *pos << endl;
	}
	else
	{
		cout << "没有找到元素" << endl;
	}
}

//统计
void test02()
{
		set<int>s1;
	//插入数据
	s1.insert(10);
	s1.insert(20);
	s1.insert(50);
	s1.insert(30);
	s1.insert(40);
	printset(s1);

	//统计30的个数，set容器中元素不允许重复，所以要么是0，要么是1
	int num = s1.count(30);
	cout << "元素30的个数为：" << num << endl;

	num = s1.count(100);
	cout << "元素100的个数为：" << num << endl;
}
int main()
{
	test01();
	test02();
	return 0;
}

*/


/*
//set和multiset的区别
//set容器中元素不允许重复，multiset容器中元素允许重复
void test01()
{
	set<int>s1;
	pair<set<int>::iterator,bool> ret=s1.insert(10);

	if(ret.second)
	{
		cout << "1插入成功" << endl;
	}
	else
	{
		cout << "1插入失败" << endl;
	}

	ret = s1.insert(10);

	if(ret.second)
	{
		cout << "2插入成功" << endl;
	}
	else
	{
		cout << "2插入失败" << endl;
	}


	multiset<int>ms;
	//允许插入重复值
	ms.insert(10);
	ms.insert(10);

	for(multiset<int>::iterator it=ms.begin();it!=ms.end();it++)
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
//pair对组的创建
void test01()
{
	//第一种方式
	pair<string, int>p("tom", 20);

	cout << "姓名：" << p.first << "年龄：" << p.second << endl;

	//第二种方式
	pair<string, int>p2 = make_pair("jerry", 30);
	cout << "姓名：" << p2.first << "年龄：" << p2.second << endl;
}
int main()
{
	test01();
	return 0;
}*/



/*
//set容器排序
//利用仿函数
//即重载()运算符

class mycompare
{
	public:
		bool operator()(const int &v1,const int &v2)//第一个()表示要重载()运算符，第二个()表示要传入两个参数
			const//const表示该函数不会修改成员变量,但是我不明白为什么要在这个位置加
		{
		return (v1 > v2);//从大到小排序
	}
};
void test01()
{
	set<int>s1;

	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//指定排序规则为从大到小
	set<int,mycompare>s2;
	s2.insert(10);
	s2.insert(20);
	s2.insert(30);

	for(set<int>::iterator it=s2.begin();it!=s2.end();it++)
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
//set容器排序，存放自定义数据类型
class person
{
public:
	person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};

class cpmpareperson
{
public:
	bool operator()(const person& p1, const person& p2)
		const 
	{
		//按照年龄降序
		return p1.m_age > p2.m_age;

	}

};
void test01()
{
	//自定义数据类型，都会指定排序规则
	// 在定义的时候放类型后面
	//同样使用仿函数
	set<person,cpmpareperson>s;
	
	//创建对象
	person p1("hhhh", 20);
	person p2("hssss", 23);
	person p3("aaaaa", 24);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);

	for (set<person>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名：" << it->m_name << "年龄:" << it->m_age << endl;
	}
}
int main()
{
	test01();
	return 0;
}
*/