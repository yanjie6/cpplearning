

#include<fstream>//头文件
#include<iostream>
using namespace std;
#include<string>


/*
//文本文件  写文件

void test01() {
	//1.包含头文件fstream

	//2.创建流对象
	ofstream ofs;

	//3.指定打开方式
	ofs.open("test.txt", ios::out);

	//4.写内容
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;

	//5.关闭文件
	ofs.close();
}
int main() {
	test01();
	return 0;
}
*/


/*
//文本文件 读文件
void test01() {
	//1.包含头文件

	//2.创建流对象
	ifstream ifs;

	//3.打开文件 并且判断是否打开成功
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//4.读数据
	//四种
	//char buf[1024] = { 0 };
	//while (ifs>>buf) {
	//	cout << buf << endl;
	//}

	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)) )
	//{
	//	cout << buf << endl;
	//}

	//string buf;
	//while(getline(ifs,buf))
	//{
	//	cout << buf << endl;
	//}

	char c;
	while ((c = ifs.get()) != EOF)//EOF   end of file
	{
		cout << c;
	}

	//5.关闭文件
	ifs.close();

}


int main() {
	test01();
	return 0;
}
*/


/*
//二进制文件   写文件
class person
{
public:
	char m_name[64];//二进制写string在循环输出时会发生指针异常
	int m_age;
};


void test01() {
	//1.头文件

	//2.流对象
	ofstream ofs("person.txt", ios::out | ios::binary);

	//3.打开文件
	//ofs.open("person.txt", ios::out | ios::binary);
	
	//4.写文件
	person p = { "张三", 18 };
	ofs.write((const char *)&p,sizeof(person));

	//5.关闭文件
	ofs.close();
}

int main() {
	test01();
	return 0;
}
*/



/*
//二进制文件  读文件

class person
{
public:
	char m_name[64];
	int m_age;
};


void test01() {
	//1.头文件

	//2.流对象
	ifstream ifs;

	//3.打开文件  判断文件是否打开成功
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "打开失败" << endl;
		return;
	}

	//4.读文件
	person p;
	ifs.read((char*)&p,sizeof(person));

	cout << "姓名：" << p.m_name << endl << "年龄：" << p.m_age << endl;

	//5.关闭文件
	ifs.close();
}

int main() {
	test01();
	return 0;
}
*/

