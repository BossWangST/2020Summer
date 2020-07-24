#include<iostream>
using namespace std;

struct Node {
	int val;
	string loc;
	struct Node* next;
};

int main(void)
{
	int n, k;
	string first;
	cin /*>> first*/ >> n >> k;
	struct Node* wait = new struct Node[n];
	//wait[0].loc = first;
	int i;
	for (i = 0; i < n; i++)
	{
		cin /*>> wait[i].loc*/ >> wait[i].val /*>> wait[i + 1].loc*/;
		/*if (wait[i + 1].loc == "-1")
		{
			wait[i].next = NULL;
			break;
		}*/
		//wait[i].next = &wait[i + 1];
	}
	int j, m;
	int flag;
	/*for (i = 0; i < n; i++)
	{
		if (wait[i].val == k)
		{
			flag = i;
			break;
		}
	}*/
	for (i = 0; i < n; i++)
	{
		if (i > 0)
		{
			if (wait[i].val < 0)
			{
				cout << "发现" << wait[i].val << "是负数" << endl;
				for (j = i; j < n-1-i; j++)
				{
					cout << "j=" <<j<< " " << wait[j].val << endl;
					struct Node temp = wait[j];
					wait[j] = wait[j - 1];
					wait[j - 1] = temp;
				}
				cout << "&&&&&&&&&&&&&当前的情况&&&&&&&&&&&&&&&&";
				for (int m = 0; m < i; i++)
					cout << wait[m].val << endl;
				cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&";
			}
			/*if (wait[i].val > k)
			{
				k = wait[i].val;
				for (j = 0; j < abs(flag - i); j++,m++)
				{
					m = i;
					struct Node temp = wait[m];
					wait[m] = wait[m + 1];
					wait[m + 1] = temp;
				}
				flag = --m;
			}*/
		}
	}
	cout << endl;
	for (i = 0; i < n; i++)
		cout << wait[i].val << endl;
	return 0;
}
