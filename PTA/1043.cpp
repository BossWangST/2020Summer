#include<iostream>
#include<string>
#include<cstring>
using namespace std;

void calcu(int *count,string str)
{
	int len=str.length();
	int i;
	for(i=0;i<len;i++)
	{
		if(str[i]=='P'||str[i]=='T'||str[i]=='A'||str[i]=='e'||str[i]=='s'||str[i]=='t')
		{
			if(str[i]=='P')
			{
				count[0]++;
				continue;
			}
			if(str[i]=='A')
			{
				count[1]++;
				continue;
			}
			if(str[i]=='T')
			{
				count[2]++;
				continue;
			}
			if(str[i]=='e')
			{
				count[3]++;
				continue;
			}
			if(str[i]=='s')
			{
				count[4]++;
				continue;
			}
			if(str[i]=='t')
			{
				count[5]++;
				continue;
			}
		}
	}
}
int main(void)
{
	string in;
	cin>>in;
	int count[6];
	int i;
	for(i=0;i<6;i++)
		count[i]=0;
	calcu(count,in);
	while(1)
	{
		if(count[0]>0)
			cout<<"P";
		if(count[1]>0)
			cout<<"A";
		if(count[2]>0)
			cout<<"T";
		if(count[3]>0)
			cout<<"e";
		if(count[4]>0)
			cout<<"s";
		if(count[5]>0)
			cout<<"t";
		for(i=0;i<6;i++)
			count[i]--;
		if(count[0]<1&&count[1]<1&&count[2]<1&&count[3]<1&&count[4]<1&&count[5]<1)
			break;
	}
	return 0;
}
