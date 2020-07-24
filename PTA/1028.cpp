#include<iostream>
#include<cmath>
#include<string>
using namespace std;

struct date{
	string name;
	string age;
};

struct xinxi{
	string name;
	int year;
	int mon;
	int day;
};

struct xinxi *trans(struct date *p)
{
	//cout<<"&&&&&&&&&&&TRANS&&&&&&&&&&&&&&";	
	string yy,mm,dd;
	yy=(p->age).substr(0,4);
	mm=(p->age).substr(5,2);
	dd=(p->age).substr(8,2);
	struct xinxi *np=new struct xinxi;
	np->name=p->name;
	np->year=stod(yy);
	//cout<<np->year<<" ";
	np->mon=stod(mm);
	//cout<<np->mon<<" ";
	np->day=stod(dd);
	//cout<<np->day<<endl;
	return np;
}

int main(void)
{
	int max_y=2014,min_y=1814;
	int max_m=9;
	int max_d=6;
	int num;
	cin>>num;
	struct date haha[num];
	int i;
	for(i=0;i<num;i++)
	{
		//cout<<"HAHAHAHA"<<endl;
		cin>>haha[i].name>>haha[i].age;
	}
	struct xinxi *wait[num];
	for(i=0;i<num;i++)
		wait[i]=trans(&haha[i]);
	int pass=num;
	int no[num-2];
	//int max=0,min=0;
	struct xinxi max,min;
	max.year=9999;max.mon=9999;max.day=9999;
	min.year=0;min.mon=0;min.day=0;
	max.name="noname";min.name="noname";
	for(i=0;i<num;i++)
	{
		cout<<max.name<<" "<<max.year<<endl;
		cout<<min.name<<" "<<min.year<<endl;
		cout<<"&&&&&&&&&&&"<<endl;
		if(wait[i]->year>max_y||wait[i]->year<min_y)
		{
			pass--;
			continue;
		}
		if(wait[i]->year==1814)
		{
			if(wait[i]->mon<max_m)
			{
				pass--;
				continue;
			}
			if(wait[i]->mon==max_m)
			{
				if(wait[i]->day<max_d)
				{
					pass--;
					continue;
				}
			}
		}	
		if(wait[i]->year==2014)
		{
			if(wait[i]->mon>max_m)
			{
				pass--;
				continue;
			}
			if(wait[i]->mon==max_m)
			{
				if(wait[i]->day>max_d)
				{
					pass--;
					continue;
				}
			}
		}
		if(max.year>wait[i]->year)
		{
			max.name=wait[i]->name;
			max.year=wait[i]->year;
			//continue;
		}
		if(max.year==wait[i]->year)
		{
			if(max.mon>wait[i]->mon)
			{
				max.name=wait[i]->name;
				max.year=wait[i]->year;
				max.mon=wait[i]->mon;
				//continue;
			}
			if(max.mon==wait[i]->mon)
			{
				if(max.day>wait[i]->day)
				{
					max.name=wait[i]->name;
					max.year=wait[i]->year;
					max.mon=wait[i]->mon;
					max.day=wait[i]->day;
					//continue;
				}
			}
		}
		if(min.year<wait[i]->year)
		{
			min.name=wait[i]->name;
			min.year=wait[i]->year;
			//continue;
		}
		if(min.year==wait[i]->year)
		{
			if(min.mon<wait[i]->mon)
			{
				min.name=wait[i]->name;
				min.year=wait[i]->year;
				min.mon=wait[i]->mon;
				//continue;
			}
			if(min.mon==wait[i]->mon)
			{
				if(min.day<wait[i]->day)
				{
					min.name=wait[i]->name;
					min.year=wait[i]->year;
					min.mon=wait[i]->mon;
					min.day=wait[i]->day;
					//continue;
				}
			}
		}
	}
	if(max.name!="noname"&&min.name!="noname")
		cout<<pass<<" "<<max.name<<" "<<min.name<<endl;
	else
		cout<<pass<<endl;
	return 0;
}
