//leetcode72 编辑距离
#include<iostream>
#include<math.h>
#include<algorithm>
#define maxN 10005
int dp[maxN][maxN];
using namespace std;
int main(void)
{
	for(int i=0;i<9;i++)
	{
		getchar();
	}
	char ch='\0';
	string word1,word2;
	while(ch!='"')
	{
		ch=getchar();
		word1+=ch;
	}
	word1[word1.length()-1]='\0';
	cout<<word1<<endl;
	ch='\0';
	for(int i=0;i<11;i++)
		getchar();
	while(ch!='"')
	{
		ch=getchar();
		word2+=ch;
	}
	word2[word2.length()-1]='\0';
	cout<<word2<<endl;
	//int dp[100005][100005];
	for(int i=1;i<=word1.length();i++)
		dp[i][0]=dp[i-1][0]+1;
	for(int i=0;i<=word2.length();i++)
		dp[0][i]=dp[0][i-1]+1;
	for(int i=1;i<=word1.length();i++)
		for(int j=1;j<=word2.length();j++)
			if(word1[i]==word2[j])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
	printf("%d",dp[word1.length()][word2.length()]);
	return 0;
}