//#include<iostream>
//#include<string>
//using namespace std;
//
//
//
////引用
//void swapByRef(int& a, int& b)
//{
//	int t = a;
//	a = b;
//	b = t;
//}
//int add(int a, int b)
//{
//	return a + b;
//}
//double add(double a, double b)
//{
//	return a + b;
//}
//void print(string s = "默认消息") {
//	cout << s << endl;
//}
//inline int getmax(int a, int b)
//{
//	return a > b ? a : b;
//}
//int main()
//{
//	//测试引用
//	int x = 10, y = 20;
//	swapByRef(x, y);
//	cout << x << " " << y << endl;
//	//测试重载
//	cout << add(1, 2) << endl;
//	cout << add(1.1, 2.2) << endl;
//	//默认参数
//	print();
//	print("自定义消息");
//	//内联
//	cout << getmax(5, 9) << endl;
//	return 0;
//
//}