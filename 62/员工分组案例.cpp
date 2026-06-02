#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

//招募10个员工，指派员工部门
//员工信息：姓名，工资组成； 部门：策划，美术，研发
//随机给员工分部门和工资
//通过multimap进行信息的插入 key（部门编号）value（员工）
//分部门显示员工信息

#define cehua 0
#define meishu 1
#define yanfa 2


class worker
{
public:
	string m_name;
	int m_salary;
};

void createworker(vector<worker>& v)
{
	string nameseed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		worker worker;
		worker.m_name = "员工";
		worker.m_name += nameseed[i];

		worker.m_salary = rand() % 10001 + 10000;//10000`20000

		//将员工放入容器
		v.push_back(worker);
	}
}

//员工分组
void setgroup(vector<worker>&v,multimap<int,worker>&m)
{
	for (vector<worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//产生随机部门编号
		int detid = rand() % 3;//0 1 2

		//将员工插入分组中
		//key具体编号，value是具体的员工（姓名工资）
		m.insert(make_pair(detid, *it));
	}
}

//分组显示
void showworkerbygroup(multimap<int, worker>& m)
{
	cout << "策划部门:" << endl;

	multimap<int,worker>::iterator pos = m.find(cehua);
	int count = m.count(cehua);//统计具体人数，遍历的时候全找到了就不用往后找了
	int index = 0;		//在容器里面员工已经排好了	//如：0:ABC		1:DEFG	2:HIJ	所以找完0就找1
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_name << "工资" << pos->second.m_salary << endl;
	}

	cout << "----------------------------------------" << endl;
	cout << "美术部门:" << endl;
	count = m.count(meishu);
	 index = 0;	
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_name << "工资" << pos->second.m_salary << endl;
	}

	cout << "-------------------------" << endl;
	cout << "研发部门:" << endl;
	count = m.count(yanfa);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_name << "工资" << pos->second.m_salary << endl;
	}


}


int main()
{
	//1.创建员工
	vector<worker>vworker;
	createworker(vworker);

	//2.分组
	multimap<int, worker>mworker;
	setgroup(vworker, mworker);//前面为全部员工，后面为全部部门

	//3.分组显示员工
	showworkerbygroup(mworker);

	return 0;
}


