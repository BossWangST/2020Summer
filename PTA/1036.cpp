#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(void)
{
	int col;
	char a;
	cin>>col>>a;
	double temp;
	if(col%2==0)
		temp=col/2;
	else
		temp=col/2+1;
	int row=round(temp);
	//cout<<row<<endl;
	int i,j;
	for(i=0;i<row;i++)
	{
		if(i==0||i==row-1)
		{
			for(j=0;j<col;j++)
				cout<<a;
			cout<<endl;
			continue;
		}
		cout<<a;
		for(j=0;j<col-2;j++)
			cout<<" ";
		cout<<a<<endl;
	}
	return 0;
}
