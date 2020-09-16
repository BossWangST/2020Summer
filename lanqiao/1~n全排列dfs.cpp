#include<iostream>
using namespace std;
bool vis[15] = { 0 };
int a[5][5];
int res = 0;
bool check(int x, int y, int i)
{
	for (int k = -1; k <= 0; k++)
	{
		for (int j = -1; j <= 1; j++)
		{
			int newx = x + k;
			int newy = y + j;
			if (newx < 0 || newy < 0 || newx>2 || newy>3)
				continue;
			if (abs(a[newx][newy] - i) == 1)
				return false;
		}
	}
	return true;
}
void dfs(int x, int y)
{
	if (x == 2 && y == 3)
	{
		res++;
		return;
	}
	if (x < 0 || y < 0 || x>2 || y>3)
	{
		return;
	}
	for(int i=0;i<10;i++)
	{
		if(!vis[i]&&check(x,y,i))
		{
			vis[i]=true;
			a[x][y]=i;
			if(y!=3)
				dfs(x,y+1);
			else
				dfs(x+1,0);
			vis[i]=false;
			a[x][y]=99999;
		}
	}
}
//vjudge.net/article/438
int main(void)
{
	//memset(vis,0,sizeof(vis));
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
			a[i][j]=99999;
	}
	dfs(0,1);
	cout<<res<<endl;
}