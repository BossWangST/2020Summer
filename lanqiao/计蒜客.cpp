#pragma warning(disable:4996)
#include<iostream>
//#include<vector>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	long long int num;
	scanf("%lld", &num);
	long long int* a = new long long int[num];
	for (int i = 0; i < num; i++)
	{
		//cout << "µÚ" << i + 1 << "´ÎÑ­»·" << endl;
		long long int tot, light;
		//cin >> tot >> light;
		scanf("%lld%lld", &tot, &light);
		//cout << "tot=" << tot << "light=" << light << endl;

		long long int temp;
		//cin >> temp;
		if (light > tot)
			a[i] = -1;
		else
		{

			if (light == 1)
			{
				//scanf("%d", &temp);
				scanf("%lld", &temp);
				a[i] =-1;
			}
			if (light == 3)
			{
				scanf("%lld", &temp);
                int one=temp;
				scanf("%lld", &temp);
				int two=temp;
                scanf("%lld", &temp);
                int three=temp;
                if(one==1&&two==2)
                    a[i]=1;
                if(two==tot-1&&three==tot)
                    a[i]=tot;
			}
           if (light == 2)
			{
				scanf("%lld", &temp);
                a[i] = temp;
				scanf("%lld", &temp);
                if(temp==tot)
                    a[i]=temp;
				
			}
           if(tot==2)
                a[i]=-1;
		}

	}

	for (int i = 0; i < num; i++)
		printf("%lld\n", a[i]);
	return 0;
}