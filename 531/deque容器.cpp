//双端数组，可以对头端进行插入删除操作
//迭代器支持随机访问

#include<iostream>
using namespace std;
#include<deque>


/*
//deque的构造函数
void printdeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		//*it = 100;	可以在函数内修改d的数据 所以可以加const使传入的数据不可修改
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printdeque(d1);

	deque<int>d2(d1.begin(), d1.end());
	printdeque(d2);

	deque<int>d3(10, 100);
	printdeque(d3);

	deque<int>d4(d3);
		printdeque(d4);
}
int main()
{
	test01();
	return 0;
}
*/


/*
//deque赋值操作
void printdeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
		cout << endl;
	}
}
void test01()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printdeque(d1);

	//= 赋值
	deque<int>d2;
	d2 = d1;
	printdeque(d2);

	//assign
	deque<int>d3;
	d3.assign(d1.begin(), d1.end());
	printdeque(d3);

	deque<int>d4;
	d4.assign(10, 100);
	printdeque(d4);

}
int main() {
	test01();
	return 0;
}*/



//deque大小操作
void printdeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
/*
void test01()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printdeque(d1);

	if (d1.empty())
	{
		cout << "d1空" << endl;
	}
	else
	{
		cout << "不空" << endl;
		cout << "d1的大小为:" << d1.size() << endl;
		//deque没有容量概念
	}
	//重新指定大小
//	d1.resize(15);
	//printdeque(d1);
	d1.resize(15, 1);
	printdeque(d1);

	d1.resize(5);
	printdeque(d1);
}
int main()
{
	test01();
	return 0;
}
*/


/*
//deque的插入和删除
void test01()
{
	deque<int>d1;

	//尾插
	d1.push_back(10);
	d1.push_back(20);

	//头插
	d1.push_front(100);
	d1.push_front(200);

	printdeque(d1);//200 100 10 20

	//尾删
	d1.pop_back();
	printdeque(d1);

	//头删
	d1.pop_front();
	printdeque(d1);

}

void test02()
{
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);

	printdeque(d1);//200 100 10 20

	//insert插入（迭代器）
	d1.insert(d1.begin(), 1000);
	printdeque(d1);

	d1.insert(d1.begin(), 2, 10000);
	printdeque(d1);//10000 10000 1000 200 100 10 20

	//按照区间插入
	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	d1.insert(d1.begin(), d2.begin(), d2.end());
	printdeque(d1);//1 2 3 10000 10000 1000 200 100 10 20
}

void test03() {
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);

	//删除
	//d1.erase(d1.begin());
	deque<int>::iterator it = d1.begin();
	it++;
	d1.erase(it);
	printdeque(d1);//200 10 20

	//按照区间删除
	//d1.erase(d1.begin(), d1.end());
	d1.clear();
	printdeque(d1);


}
int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}
*/


/*
//deque数据存取

void test01()
{
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);

	//通过[]方式访问
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1[i] << " ";
	}
	cout << endl;

	//通过at访问
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1.at(i) << " ";
	}
	cout << endl;

	cout << "第一个为" << d1.front() << endl;

	cout << "最后一个" << d1.back() << endl;
}
int main()
{
	test01();
	return 0;
}
*/


/*
#include<algorithm>
//deque排序
void test01()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(40);
	d.push_back(30);

	printdeque(d);

	//排序	默认规则：从小到大
	//对于可以随机访问的迭代器，都可以用sort直接排序
	//如vector
	sort(d.begin(), d.end());
	cout << "排序后：" << endl;
	printdeque(d);

}
int main() {
	test01();
	return 0;
}
*/





/*
有5名选手，ABCDE，10个评委分别对每一名选手打分，去除最高分，去除最低分，取平均分
*/
/*
#include<vector>
//选手类

class person
{
public:
	person(string name, int score)
	{
		this->m_name = name;
		this->m_score = score;
	}
	string m_name;
	int m_score;
};


void createperson(vector<person>& v)
{
	string nameseed = "ABCDE";
	for(int i=0;i<5;i++)
	{ 
		string name = "选手";
		name += nameseed[i];

		int score = 0;

		person p(name, score);//创建一个人,并且初始化了

		v.push_back(p);//将人放到容器中
	
	}
}

#include<deque>
#include<algorithm>
//打分函数
void setscore(vector<person>& v)
{
	//因为每个人都被打10次分，所以不用int i=0那个东西
	for (vector<person>::iterator it=v.begin();it!=v.end();it++)
	{
		//将评委的分数 放入deque容器中
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;//60~100
			d.push_back(score);
		}

		//排序
		sort(d.begin(), d.end());//然后直接去除头尾

		//去除最高分最低分
		d.pop_back();
		d.pop_front();

		//取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;//累加每个评委分数
		}
		int avg = sum / d.size();

		//将平均分赋值给选手
		it->m_score = avg;

	}
}

//显示分数
void showscore(vector<person>& v)
{
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it).m_name << " 分数：" << (*it).m_score << endl;
	}
}
#include<ctime>
int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));

	//1.创建5名选手
	vector<person>v;//存放选手的容器
	createperson(v);//打印选手

	//测试
	//for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
	//{
		//cout << (*it).m_name << " " << (*it).m_score <<endl;//*it指的是person这个人，但是人包含了两个信息，要分别打印
	//}

	//2.给5名选手打分
	setscore(v);

	//3。显示最后得分
	showscore(v);

	system("pause");
	return 0;

}
十分重要
*/