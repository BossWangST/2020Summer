#include<iostream>
#include<set>
using namespace std;
int a[1001][1001];
int dad[1001];
int find(int son)
{
	if (dad[son] == son)
		return son;
	return find(dad[son]);
}
void uni(int a, int b)
{
	int adad, bdad;
	adad = find(a);
	bdad = find(b);
	if (adad != bdad)
	{
		dad[bdad] = adad;
	}
}
int main(void)
{
	int len, col;
	cin >> len >> col;
	int flag = 1;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < col; j++)
		{
			a[i][j] = flag++;
			dad[a[i][j]] = a[i][j];
			//cout << a[i][j] << ' ';
		}
		//cout << endl;
	}
	int count;
	cin >> count;
	while (count--)
	{
		int x, y;
		cin >> x >> y;
		uni(x, y);
	}
	int res = 0;
	for (int i = 1; i <= len * col; i++)
	{
		if (dad[i] == i)
			res++;
	}
	cout << res << endl;
	return 0;
}