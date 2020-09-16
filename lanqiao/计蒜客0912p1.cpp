#include<iostream>
//#include<set>
#pragma warning(disable:4996)
using namespace std;
char desk[25][25];
struct Node {
	int row, col;
};
bool operator < (const Node& a,const Node& b)
{
	if (a.row < b.row)
		return true;
	return false;
	/*else if (a.row == b.row)
	{
		return a.col < b.col;
	}
	else if (a.row > b.row)
		return false;*/
}
//set<Node> black;
//set<Node> white;
//set<Node> blackres;
//set<Node> whiteres;
bool blackempty = true;
bool whiteempty = true;
//Node* temp = new Node[1000];
//int flag = 0;
int main(void)
{
	int blackcount = 0;
	int whitecount = 0;

	//char ch;
	//scanf("%c", &ch);
	//cout << ch << endl;
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			scanf("%c", &desk[i][j]);
			//cin >> desk[i][j];
			if (desk[i][j] == 'x')
			{
				blackcount++;
			}
			if (desk[i][j] == 'o')
			{
				whitecount++;
			}
		}
		getchar();
	}
	int tag = -1;
	if (blackcount == whitecount)
	{
		tag = 1;
	}
	else
		tag = 0;
	/*cout << "****************" << endl;
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
			cout << desk[i][j];
		cout << endl;
	}*/
	for(int i=0;i<25;i++)
		for(int j=0;j<25;j++)
			if (desk[i][j] == '.'&&tag)
			{
				bool out = false;
				int bla = 0;
				int nowi = i;
				int nowj = j;
				//cout << "desknow["<<i<<"][ "<<j<<"]="<< desk[i][j] << endl;
				while (nowi<24&&desk[++nowi][nowj] != '.')
				{
					if (desk[nowi][nowj] == 'o')
						break;
					//cout << "向下:" << desk[nowi][nowj] << endl;
						bla++;

						//continue;
 				}
				nowi = i;
				nowj = j;
				while (nowi>0&&desk[--nowi][nowj] != '.')
				{
					//cout << "向上:" << desk[nowi][nowj] << endl;
						if (desk[nowi][nowj] == 'o')
							break;

						bla++;

						//continue;


				}
				if (!out&&bla>=4)
				{
						cout << i << ' ' << j << endl;
						out = true;
						blackempty = false;
				}
				nowi = i;
				nowj = j;
				bla = 0;				
				while (nowj < 24 && desk[nowi][++nowj] != '.')
				{
					//cout << "向右:" << desk[nowi][nowj] << endl;
					if (desk[nowi][nowj] == 'o')
						break;

						bla++;
				}
				nowi = i;
				nowj = j;
				while (nowj >0 && desk[nowi][--nowj] != '.')
				{
					//cout << "向左:" << desk[nowi][nowj] << endl;
					if (desk[nowi][nowj] == 'o')
						break;

						bla++;
						//continue;
					

				}
				if (!out&&bla>=4)
				{
						cout << i << ' ' << j << endl;
						out = true;
						blackempty = false;
				}
				nowi = i;
				nowj = j;
				bla = 0;
				while (nowi<24&&nowj<24&&desk[++nowi][++nowj] != '.')
				{
					//cout << "向右下:" << desk[nowi][nowj] << endl;
					if (desk[nowi][nowj] == 'o')
						break;

						bla++;

						//continue;

				}
				nowi = i;
				nowj = j;
				while (nowi>0&&nowj>0&&desk[--nowi][--nowj] != '.')
				{
					//cout << "向左上:" << desk[nowi][nowj] << endl;
					if (desk[nowi][nowj] == 'o')
						break;

						bla++;

					

				}
				if (!out&&bla>=4)
				{
						cout << i << ' ' << j << endl;
						out = true;
						blackempty = false;
				}
				nowi = i;
				nowj = j;
				bla = 0;
				while (nowi > 0 && nowj < 24 && desk[--nowi][++nowj] != '.')
				{
					//cout << "向右上:" << desk[nowi][nowj] << endl;
					if (desk[nowi][nowj] == 'o')
						break;

						bla++;


				}
				nowi = i;
				nowj = j;
				while (nowi < 24 && nowj > 0 && desk[++nowi][--nowj] != '.')
				{
					if (desk[nowi][nowj] == 'o')
						break;

						bla++;

						//continue;

				}
				if (!out&&bla>=4)
				{
					//cout << "向左下:" << desk[nowi][nowj] << endl;

						cout << i << ' ' << j << endl;
						out = true;
						blackempty = false;
				}
			}
			else if (desk[i][j] == '.' && !tag)
			{
				bool out = false;
				int whi = 0;
				int nowi = i;
				int nowj = j;
				//cout << "desknow["<<i<<"][ "<<j<<"]="<< desk[i][j] << endl;
				while (nowi < 24 && desk[++nowi][nowj] != '.')
				{
					if (desk[nowi][nowj] == 'x')
						break;
					//cout << "向下:" << desk[nowi][nowj] << endl;
						whi++;
				}
				nowi = i;
				nowj = j;
				while (nowi > 0 && desk[--nowi][nowj] != '.')
				{
					if (desk[nowi][nowj] == 'x')
						break;

					//cout << "向上:" << desk[nowi][nowj] << endl;
						whi++;

						//continue;

				}
				if (!out&&whi>=4)
				{
						cout << i << ' ' << j << endl;
						out = true;
						whiteempty = false;
				}
				nowi = i;
				nowj = j;
				whi = 0;
				while (nowj < 24 && desk[nowi][++nowj] != '.')
				{
					if (desk[nowi][nowj] == 'x')
						break;

					//cout << "向右:" << desk[nowi][nowj] << endl;

						whi++;

				}
				nowi = i;
				nowj = j;
				while (nowj > 0 && desk[nowi][--nowj] != '.')
				{
					//cout << "向左:" << desk[nowi][nowj] << endl;
					if (desk[nowi][nowj] == 'x')
						break;
						whi++;

				}
				if (!out&&whi>=4)
				{
						cout << i << ' ' << j << endl;
						out = true;
						whiteempty = false;
				}
				nowi = i;
				nowj = j;
				whi = 0;				
				while (nowi < 24 && nowj < 24 && desk[++nowi][++nowj] != '.')
				{
					//cout << "向右下:" << desk[nowi][nowj] << endl;
					if (desk[nowi][nowj] == 'x')
						break;

						whi++;
				}
				nowi = i;
				nowj = j;
				while (nowi > 0 && nowj > 0 && desk[--nowi][--nowj] != '.')
				{
					//cout << "向左上:" << desk[nowi][nowj] << endl;
					if (desk[nowi][nowj] == 'x')
						break;

						whi++;

				}
				if (!out&&whi>=4)
				{
						cout << i << ' ' << j << endl;
						out = true;
						whiteempty = false;
				}
				nowi = i;
				nowj = j;
				whi = 0;
				while (nowi > 0 && nowj < 24 && desk[--nowi][++nowj] != '.')
				{
					//cout << "向右上:" << desk[nowi][nowj] << endl;
					if (desk[nowi][nowj] == 'x')
						break;

						whi++;

				}
				nowi = i;
				nowj = j;
				while (nowi < 24 && nowj > 0 && desk[++nowi][--nowj] != '.')
				{
					if (desk[nowi][nowj] == 'x')
						break;

						whi++;

				}
				if (!out&&whi>=4)
				{
					//cout << "向左下:" << desk[nowi][nowj] << endl;

						cout << i << ' ' << j << endl;
						out = true;
						whiteempty = false;
				}
			}

			if (blackempty && whiteempty)
			{
				cout << "tie" << endl;
				return 0;
			}
			//cout << "blackres size:" << blackres.size() << endl;
			/*if (tag)
			{
				set<Node>::iterator ite = blackres.begin();
				while (ite != blackres.end())
				{
					cout << ite->row << ' ' << abs(ite->col-ite->row) << endl;
					ite++;
				}
			}
			else
			{
				set<Node>::iterator ite = whiteres.begin();
				while (ite != whiteres.end())
				{
					cout << ite->row << ' ' << abs(ite->col-ite->row) << endl;
					ite++;
				}
			}*/
			return 0;
}