#include<iostream>
#include<string>
using namespace std;
int main(void)
{
	string a1, a2, b1, b2;
	cin >> a1 >> a2 >> b1 >> b2;
	int len1, len2;
	if (a1.length() <= a2.length())
		len1 = a1.length();
	else
		len1 = a2.length();
	if (b1.length() <= b2.length())
		len2 = b1.length();
	else
		len2 = b2.length();
	int i;
	char res[2];
	int j = 0;
	for (i = 0; i < len1; i++)
	{
		if (a1[i] == a2[i])
		{
			if (a1[i] >= 65 && a1[i] <= 71)
			{
				res[j] = a1[i];
				j++;
				break;
			}
		}
	}
	i++;
	bool isnum=false;
	for (i; i < len1; i++)
	{
		if (a1[i] == a2[i])
		{
			if ((a1[i] >= 65 && a1[i] <= 78))
			{
				res[j] = a1[i];
				//j++;
				isnum = false;
				break;
			}
			else if ((a1[i] - '0' >= 0 && a1[i] - '0' <= 9))
			{
				res[j] = a1[i];
				//j++;
				isnum = true;
				break;
			}
		}

	}
	int sec=0;
	for (i = 0; i < len2; i++)
	{
		if (b1[i] == b2[i])
		{
			if ((b1[i] >= 65 && b1[i] <= 90) || (b1[i] >= 97 && b1[i] <= 122))
			{
				sec= i;
				break;
			}
		}
	}
	//for (int k = 0; k < 3; k++)
	//	cout << res[k] << endl;
	string week[8] = { "haha","MON","TUE","WED","THU","FRI","SAT","SUN" };
	int day = res[0] - 64;
	cout << week[day] << ' ';
	if (isnum)
	{
		if (res[1] - '0' < 10)
		{
			cout << '0' << res[1] << ':';
		}
		else
			cout << res[1] << ':';
	}
	else
	{
		int tmp = res[1];
		cout << tmp - 55 << ':';
	}
	if (sec< 10)
	{
		cout << '0' << sec;
	}
	else
	{
		cout << sec;
	}
	return 0;


}
//test of diff