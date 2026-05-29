
#include<iostream>
using namespace std;

#include<string>


/*
//string的构造函数
// 
// 原型
//string();			创建一个空的字符串 例如：string str；
// string（const char *s);		使用字符串s初始化
// string（const string &str）；	拷贝
// string(int n,char c);		使用n个字符c 初始化

void test01()
{
	string si;//默认构造

	const char* str = "hello world";
	string s2(str);

	cout << "s2= " << s2 << endl;

	string s3(s2);

	cout << "s3= " << s3 << endl;

	string s4(10, 'a');
	cout << "s4= " << s4 << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}
*/



/*
//string的赋值操作
// 
// string &operator=(const char *s);		char*类型字符串  赋值给当前的字符串
// string &operator=(const string &s);		把字符串s 赋给当前
// string &operator=(char c);				字符赋给当前
// 
// string &assign(const char *s);			把字符串s 赋给当前
// string &assign(const char *s,int n);		把字符串s的前n个字符 赋给当前
// string &assign(const string &s);			把把字符串s 赋给当前
// string &assign(int n,char c)				用n个字符c赋给当前字符串
//

void test01()
{
	string str1;
	str1 = "hello world";
	cout << "str1= " << str1 << endl;

	string str2;
	str2 = str1;
	cout << "str2= " << str2 << endl;

	string str3;
	str3 = 'a';
	cout << "str3= " << str3 << endl;

	string str4;
	str4.assign("hello");
	cout << "str4= " << str4 << endl;

	string str5;
	str5.assign("hello", 4);
	cout << "str5= " << str5 << endl;

	string str6;
	str6.assign(str5);
	cout << "str6= " << str6 << endl;

	string str7;
	str7.assign(4, 'a');
	cout << "str7= " << str7 << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}
*/



/*
//string字符串拼接
//string& operator+=(const char* str);				//重载+=操作符
//string& operator+=(const char c);					// 重载 += 操作符
//stning & operatort = (const string & str);		// 重载 += 操作符
//string & append(const char* s);					// 把字符串S连接到当前字符串结尾
//string & append(const char* s, int n);			// 把字符串s的前n个字符连接到当前字符串结尾
//string & append(const string & s);				// 同operator += (const string & str)
//string & append(const string & 5,int pos,int n);	//字符串s中从pos开始的n个字符连接到字符串结尾     pos从哪个字符开始   n 截取几个

void test01()
{
	string str1 = "我";
	str1 += "爱玩游戏";
	cout << "str1=" << str1 << endl;

	str1 += ':';
	cout << "str1=" << str1 << endl;

	string str2 = "lol dnf";
	str1 += str2;
	cout << "str1=" << str1 << endl;

	string str3 = "I";
	str3.append("love");
	cout << "sr3=" << str3 << endl;

	str3.append("game abcde", 4);
	cout << "str3=" << str3 << endl;

	//str3.append(str2);
	str3.append(str2, 0, 3);//只截取lol
	cout << "str3=" << str3 << endl;


	}

int main()
{
	test01();
	system("pause");
	return 0;
}
*/



/*
//string查找和替换
#include<string>
//1.查找
void test01()
{
	string str1 = "abcdefgde";

	int pos = str1.find("de");

	if (pos == -1)
	{
		cout << "未找到字符串" << endl;
	}
	else
	{
		cout << "找到了  pos= " << pos << endl;
	}

	//rfind
	//区别
	//find从左往右找		rfind 从右往左找
	pos = str1.rfind("de");
	cout << "pos= " << pos << endl;

}

//替换
void test02()
{
	string str1 = "abcdefg";

	str1.replace(1, 3, "1111");//从1号位置起 3个字符 替换为1111  a1111efg

	cout <<"str1= " << str1 << endl;
}
int main()
{
	test01();
	test02();
	return 0;
}
*/


/*
//string字符串的比较
void test01()
{
	string str1 = "hello";
	string str2 = "hello";

	if (str1.compare(str2) == 0)
	{
		cout << "str1等于str2" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1大于str2" << endl;
	}
	else
	{
		cout << "str1小于str2" << endl;
	}
}

int main()
{
	test01();
	return 0;
}
*/


/*
//string 字符存取
void test01()
{
	string str = "hello";
	//cout << "str = " <<str<< endl;

	//1.通过[]访问单个字符
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;

	//2。通过at方式访问单个字符
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;

	//修改单个字符
	str[0] = 'x';
	cout << "str= " << str << endl;

	str.at(1) = 'x';
	cout << "Str = " << str << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
*/


/*
//string插入和删除
void test01()
{
	string str = "hello";

	//插入
	str.insert(1, "111");;
	cout << "str= " << str << endl;

	//删除
	str.erase(1, 3);
	cout << "str= " << str << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
*/


/*
//string求子串
void test01()
{
	string str = "abcdef";

	string substr = str.substr(1, 3);

	cout << "substr=" << substr << endl;
}

//实用操作
void test02()
{
	string email = "zhangsan@sia.com";

	//从邮件地址中1 获取 用户名信息
	int pos=email.find("@");
	
	string usrname = email.substr(0, pos);

	cout << usrname << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
*/
