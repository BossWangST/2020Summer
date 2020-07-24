#include<iostream>
#include<string>
using namespace std;
class stu {
public:
	string name;
	int comeh, comem, comes;
	int outh, outm, outs;
	string come;
	string out;
	stu() {}
	void set(string a, string b, string c)
	{
		name = a;
		come = b;
		out = c;
	}
	void convert();
};
void stu::convert()
{
	comeh = (come[0] - '0') * 10 + come[1];
	comem = (come[3] - '0') * 10 + come[4];
	comes = (come[6] - '0') * 10 + come[7];
	outh = (out[0] - '0') * 10 + out[1];
	outm = (out[3] - '0') * 10 + out[4];
	outs = (out[6] - '0') * 10 + out[7];
}
bool comecmp(stu& a, stu& b)
{
	if (a.comeh < b.comeh)
		return true;
	else
	{
		if (a.comem < b.comem)
			return true;
		else
		{
			if (a.comes < b.comes)
				return true;
			else
				return false;
		}
	}
}
bool outcmp(stu& a, stu& b)
{
	if (a.outh < b.outh)
		return true;
	else
	{
		if (a.outm < b.outm)
			return true;
		else
		{
			if (a.outs < b.outs)
				return true;
			else
				return false;
		}
	}

}
int main(void)
{
	int num;
	cin >> num;
	stu* wait = new stu[num];
	for (int i = 0; i < num; i++)
	{
		string tmp1, tmp2, tmp3;
		cin >> tmp1 >> tmp2 >> tmp3;
		wait[i].set(tmp1, tmp2, tmp3);
		wait[i].convert();
	}
	stu* max, * min;
	max = NULL; 
	min = NULL;
	for (int i = 0; i < num - 1; i++)
	{
		if (comecmp(wait[i], wait[i + 1]))
			max = &wait[i];
		else
			max = &wait[i + 1];
		if (outcmp(wait[i], wait[i + 1]))
			min = &wait[i + 1];
		else
			min = &wait[i];
	}
	cout << max->name << ' ' << min->name << endl;
	return 0;
}