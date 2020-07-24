#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(void)
{
	int a, b;
	cin >> a >> b;
	int res = a + b;
	stringstream ss;
	ss << res;
	string str;
	ss >> str;
	//cout << str << endl;
	int len;
	if (str[0] == '-')
	{
		len = str.length() - 1;
		if (len > 3 && len < 7)
		{
			for (int i = 0; i < len+1; i++)
			{
				if (i != len - 2)
					cout << str[i];
				else
				{
					cout << ',' << str[i];
				}
			}
		}
		else if (len == 7)
		{
			for (int i = 0; i < len + 1; i++)
			{
				if (i != len - 2&&i!=len-5)
					cout << str[i];
				else
				{
					cout << ',' << str[i];
				}
			}

		}
		else
		{
			cout << str;
		}

	}
	else
	{
		len = str.length();
		if (len > 3 && len < 7)
		{
			for (int i = 0; i < len; i++)
			{
				if (i != len - 3)
					cout << str[i];
				else
				{
					cout << ',' << str[i];
				}
			}
		}
		else if (len == 7)
		{
			for (int i = 0; i < len + 1; i++)
			{
				if (i != len - 3 && i != len - 6)
					cout << str[i];
				else
				{
					cout << ',' << str[i];
				}
			}

		}
		else
			cout << str;


	}
	return 0;
}