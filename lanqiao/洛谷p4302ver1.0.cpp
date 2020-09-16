#include<iostream>
#pragma warning(disable:4996)
#define big 1808504320951916825
using namespace std;
long long m, n;
long long myhash[4698571 + 12345];
bool find(int x)
{
	long long pos = abs(x % big);
	//printf("Œª÷√:%lld\n", pos);
	while (myhash[pos] != big)
	{
		if (myhash[pos] == x)
		{
			return true;
		}
		else
			++pos;
	}
	myhash[pos] = x;
	return false;
}
int main(void)
{
	scanf("%lld", &n);
	while (n--)
	{
		memset(myhash, 25, sizeof(myhash));
		scanf("%lld", &m);
		for (int i = 0; i < m; ++i)
		{
			long long k;
			scanf("%lld", &k);
			if (!find(k))
				printf("%lld ", k);
		}
		printf("\n");
	}
	return 0;
}