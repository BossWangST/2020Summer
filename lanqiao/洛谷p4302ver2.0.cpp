#pragma warning(disable:4996)
#include<iostream>
using namespace std;
const int p = 100000;
struct Node {
	int val, next;
};
Node rec[10 + p];
int hashnum[10 + p], n, tot;
int Hash(int x)
{
	return (x % p + p) % p;
}
bool add(int x, int v)
{
	for (int i = hashnum[x]; i; i = rec[i].next)
		if (rec[i].val == v)
			return false;
	rec[++tot].val = v;
	rec[tot].next = hashnum[x];
	hashnum[x] = tot;
	return true;
}
int main(void)
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		memset(rec, 0, sizeof(rec));
		memset(hashnum, 0, sizeof(hashnum));
		scanf("%d", &n);
		tot = 0;
		while (n--)
		{
			int x;
			scanf("%d", &x);
			if (add(Hash(x), x))
				printf("%d ", x);
		}
		printf("\n");
	}
	return 0;
}