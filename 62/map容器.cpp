#include<iostream>
#include<string>
using namespace std;
#include<map>

//map所有元素都是pair
//pair第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
//所有元素都会根据元素的键值自动排序
//关联式容器，底层结构二叉树实现



//map构造和赋值
void printmap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key=" << (*it).first << "value=" << it->second << endl;
	}
	cout << endl;
}
/*
void test01()
{
	//创建map容器
	map<int, int>m;//默认构造

	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	
	printmap(m);

	//拷贝构造
	map<int, int>m2(m);
	printmap(m2);

	//赋值
	map<int, int>m3;
	m3 = m2;
	printmap(m3);

}
int main()
{
	test01();
	return 0;
}
*/




/*
//大小和交换

//大小
void test01()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));

	if (m.empty())
	{
		cout << "m为空" << endl;
	}
	else
	{
		cout << "m不为空" << endl;
		cout << "m的大小为" << m.size() << endl;
	}
}

//交换
void test02()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));

	map<int, int>m2;
	m2.insert(pair<int, int>(4, 40));
	m2.insert(pair<int, int>(5, 50));
	m2.insert(pair<int, int>(6, 60));

	cout << "交换前" << endl;
	printmap(m);
	printmap(m2);

	m.swap(m2);

	cout << "交换后" << endl;
	printmap(m);
	printmap(m2);

}

int main()
{
	test01();
	test02();
	return 0;
}
*/



/*
//map的插入和删除

void test01()
{
	map<int, int>m;

	//插入
	//第一种
	m.insert(pair<int, int>(1, 10));

	//第二种
	m.insert(make_pair(2, 20));

	//第三种
	m.insert(map<int, int>::value_type(3, 30));

	//第四种
	m[4] = 40;

	//[]不建议插入，用途 可以利用key访问到value
	printmap(m);

	//删除
	m.erase(m.begin());
	printmap(m);

	m.erase(3);//按照key删除
	printmap(m);

	//清空
	m.erase(m.begin(), m.end());
	printmap(m);

	m.clear();
	printmap(m);
}
int main()
{
	test01();
	return 0;
}
*/


/*
//map查找和统计
void test01()
{
	//查找
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));

	map<int,int>::iterator pos = m.find(3);//和之前一样，find返回的是一个迭代器，所以要创造一个迭代器接收

	if (pos != m.end())
	{
		cout << "查找到了key = " <<(*pos).first<<"value = "<<(*pos).second<< endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//统计
	int num = m.count(3);//因为不能重复，所以只有0/1
	//（）里面统计的是key
	cout << "num = " << num << endl;

}
int main()
{
	test01();
	return 0;
}
*/


/*
//map排序
class mycompare
{
public:
	bool operator()(const int& v1, const int& v2)const
	{
		//降序
		return v1 > v2;
	}
};
void test01()
{
	map<int, int,mycompare>m;//默认从小到大
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));

	for (map<int, int, mycompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key=" << it->first << "value=" << it->second << endl;
	}



}
int main()
{
	test01();
	return 0;
}*/