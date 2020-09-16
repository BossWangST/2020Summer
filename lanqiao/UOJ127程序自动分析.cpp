#include<iostream>
#pragma warning(disable:4996)
#include<cstdio>
#define maxN 10000005
using namespace std;
int n, m;
int fa[maxN];
int read(void)
{
	int in;
	scanf("%d", &in);
	return in;
}
int find(int x)
{
	if (fa[x] == x)
		return x;
	else
	{
		fa[x] = find(fa[x]);
		return fa[x];
	}
}
int main(void)
{
	n = read();
	while (n--)
	{
		int res = 0;
		m = read();
		for (int i = 1; i <= 2 * m; i++)
		{
			fa[i] = i;
		}
		int count = m;
		while (count--)
		{
			int  u = read(), v = read(), opt = read();
			if (opt == 1)
			{
				//cout << "find(u)=" << find(u) << endl << "find(v)=" << find(v) << endl;
				//cout << "find(u+m)=" << find(u + m) << endl << "find(v+m)=" << find(v + m) << endl;
				if (find(u + m) == find(v) || find(v + m) == find(u))
					res++;
				else
				{
					fa[find(u)] = find(v);
					fa[find(u + m)] = find(v + m);
				}
			}
			else
			{
				if (find(u) == find(v) || find(u + m) == find(v + m))
					res++;
				else
				{
					fa[find(u)] = find(v + m);
					fa[find(u + m)] = find(v);
				}
			}
		}
		//cout << "res=" << res << endl;
		if (res == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}