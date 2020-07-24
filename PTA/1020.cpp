#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
struct bing{
        double num;
        double price;
};

bool cmp(struct bing a,struct bing b)
{
	if(a.price>=b.price)
		return true;
	else 
		return false;
}
int main(void)
{
	int kind;
    double need;
	cin>>kind>>need;
	struct bing a[kind];
	int i;
	for(i=0;i<kind;i++)
		cin>>a[i].num;
	for(i=0;i<kind;i++)
		cin>>a[i].price;
	for(i=0;i<kind;i++)
		a[i].price/=a[i].num;
	sort(a,a+kind,cmp);
	/*for(i=0;i<kind;i++)
		cout<<a[i].price<<endl;*/
	double count=0;
	i=0;
	while(1)
	{
		count+=a[i].num;
		if(count>=need)
			break;
		i++;
		if(i==kind)
		{
			i--;
			break;
		}
	}
	int j;
	float res=0;
	for(j=0;j<i;j++)
	{
		/*if(a[0].num>=need)
		{
			res+=a[0].price*need;
			break;
		}*/
		res+=a[j].num*a[j].price;
		need-=a[j].num;
	}
	if(i<kind)
		res+=a[j].price*need;
	if(i==kind)
		res+=a[j].price*a[j].num;
	cout.setf(ios::fixed);
	cout<<setprecision(2)<<res<<endl;

	return 0;
}	
