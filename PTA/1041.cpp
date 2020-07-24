#include<iostream>
#include<string>
using namespace std;

struct stu{
	string id;
	int shi;
	int kao;
};

int find(struct stu head[],int a)
{
	int i=0;
	while(1)
	{
		if(head[i].shi==a)
			return i;
		i++;
	}
}
int main(void)
{
	int n;
	cin>>n;
	struct stu haha[n];
	int i;
	for(i=0;i<n;i++)
		cin>>haha[i].id>>haha[i].shi>>haha[i].kao;
	int m;
	cin>>m;
	int wait[m];
	for(i=0;i<m;i++)
		cin>>wait[i];
	for(i=0;i<m;i++)
		wait[i]=find(haha,wait[i]);
	int temp;
	for(int j=0;j<m;j++)
	{
		temp=wait[j];
		cout<<haha[temp].id<<" "<<haha[temp].kao<<endl;
	}

	return 0;

}
