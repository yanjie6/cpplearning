//#include<iostream>
//using namespace std;


////枚举
//enum Gender {
//	male,female,unknow
//};
//enum week {
//	mon,tue,wed,thu,fri,sat,sun
//};
//
//struct student {
//	string name;
//	int age;
//	Gender gender;
//};
//int main()
//{
//	//week today = mon;//只能选里面的选项
//	//if (today == mon)
//	//{
//	//	cout << "今天周一" << endl;
//	//}
//	//return 0;
//
//	student s;
//	s.age = 18;
//	s.gender = male;
//	s.name = "张三";
//	cout << s.age << s.gender << s.name << endl;
//
//	student a = { "李四",18,female };
//	cout << a.age << a.gender << a.name << endl;
//
//	return 0;
//}




//namespace MYSpace {
//	int a = 100;
//	void show()
//	{
//		cout << "我在MYSpace" << endl;
//	}
//}
//int main()
//{
//	cout << MYSpace::a << endl;
//	MYSpace::show();
//
//	using namespace MYSpace;
//	show();
//	return 0;
//}



//namespace studentsys {
//	//枚举
//	enum gender { male, female };
//	//结构体
//	struct stu {
//		string name;
//		int age;
//		gender gender;
//	};
//}

//int main()
//{
//	studentsys::stu s = { "小明",18,studentsys::male };
//	cout << s.name << " " << s.gender << endl;
//	return 0;
//}