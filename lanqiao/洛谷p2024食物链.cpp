#include<iostream>
#pragma warning(disable:4996)
using namespace std;
inline int read()
{
	/*char c = getchar();
	int n = 0;
	while (c < '0' || c > '9')
		c = getchar();
	while (c >= '0' && c <= '9')
	{
		n = (n << 1) + (n << 3) + (c & 15);
		c = getchar();
	}
	return n;*/
	int in;
	scanf("%d", &in);
	return in;
}
const int maxN = 100005;
int n, m, ans, fa[maxN * 3];
int find(int u)
{
	if (fa[u] == u)
		return u;
	else
		return fa[u] = find(fa[u]);
}
int main(void)
{
	n = read();
	//cout << n << endl;
	m = read();
	for (int i = 1; i <= n * 3; i++)
		fa[i] = i;
	while (m--)
	{
		int opt = read(), u = read(), v = read();
		if (u > n || v > n)
		{
			ans++;
			continue;
		}
		if (opt == 1)
		{
			if (find(u + n) == find(v) || find(u) == find(v + n))//��u��v�Ƿ������ȴ��ͬһ���ϣ���u��v������Ϊͬ����
				ans++;
			else
			{
				fa[find(u)] = find(v);
				fa[find(u + n)] = find(v + n);
				fa[find(u + 2 * n)] = find(v + 2 * n);
			}
		}
		else
		{
			if (find(u) == find(v) || find(u) == find(v + n))//��u��v�Ƿ�ͬһ���ϣ���ͬһ������ͬ���壬�򲻿��ܲ�ʳ��ϵ
															//��u��v+n�Ƿ�ͬһ���ϣ���ͬһ���ϵ���ͬ���壬˵����v��u����u��v
				ans++;
			else
			{
				fa[find(u + n)] = find(v);
				fa[find(u + 2 * n)] = find(v + n);
				fa[find(u)] = find(v + 2 * n);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}