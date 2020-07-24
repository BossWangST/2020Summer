#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
class stu {
public:
	string id;
	int c;
	int tot;
	int d;
	stu() {}
	void set(string hao, int de, int cai)
	{
		id = hao;
		d = de;
		c = cai;
		tot = d + c;
	}
	int separate(int L, int H)
	{
		if (d >= H && c >= H)
			return 1;
		else if (d >= H && c < H && c >= L)
			return 2;
		else if (d < H && c < H && d >= c && c >= L && d >= L)
			return 3;
		else if (d < c && d >= L && c >= L)
			return 4;
		else
			return 0;
	}
	void print()
	{
		cout << id << ' ' << d << ' ' << c << endl;
	}
};
bool cmp(const stu a, const stu b)
{
	if (a.tot > b.tot)
		return true;
	else if (a.tot == b.tot)
	{
		if (a.d > b.d)
			return true;
		else if (a.d == b.d)
			return a.id < b.id;
		else
			return false;
	}
	else
		return false;
}
int main(void)
{
	int num;
	int L, H;
	cin >> num >> L >> H;
	stu* wait = new stu[num];
	int i;
	for (int i = 0; i < num; i++)
	{
		string tmp1;
		int tmp2, tmp3;
		cin >> tmp1 >> tmp2 >> tmp3;
		wait[i].set(tmp1, tmp2, tmp3);
	}
	stu* no1 = new stu  [num]; int f1 = 0;
	stu* no2 = new stu  [num]; int f2 = 0;
	stu* no3 = new stu  [num]; int f3 = 0;
	stu* no4 = new stu  [num]; int f4 = 0;
	for (i = 0; i < num; i++)
	{
		int res;
		res = wait[i].separate(L,H);
		switch (res)
		{
		case 1:
		{
			no1[f1] = wait[i];
			f1++;
			continue;
		}
		case 2:
		{
			no2[f2] = wait[i];
			f2++;
			continue;
		}
		case 3:
		{
			no3[f3] = wait[i];
			f3++;
			continue;
		}
		case 4:
		{
			no4[f4] = wait[i];
			f4++;
			continue;
		}
		default:
			continue;
		}
	}
	sort(no1, no1 + f1, cmp);
	sort(no2, no2 + f2, cmp);
	sort(no3, no3 + f3, cmp);
	sort(no4, no4 + f4, cmp);
	cout << f1 + f2 + f3 + f4 << endl;
	for (i = 0; i < f1; i++)
		no1[i].print();
	for (i = 0; i < f2; i++)
		no2[i].print();
	for (i = 0; i < f3; i++)
		no3[i].print();
	for (i = 0; i < f4; i++)
		no4[i].print();
	return 0;
}