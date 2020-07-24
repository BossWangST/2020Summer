#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(void)
{
	string wait;
	cin >> wait;
	int len = wait.length();
	int* num = new int[len];
	for (int i = 0; i < len; i++)
	{
		num[i] = wait[i] - '0';
	}
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += num[i];
	}
	stringstream ss;
	ss << sum;
	string res;
	ss >> res;
	string eng[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	int reslen = res.length();
	for (int i = 0; i < reslen; i++)
	{
		int temp = res[i] - '0';
		cout << eng[temp];
		if (i != reslen - 1)
			cout << ' ';
	}
	return 0;
}