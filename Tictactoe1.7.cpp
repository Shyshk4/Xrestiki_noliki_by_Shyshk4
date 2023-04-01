#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
const int n = 3;
int inp_num(char, const char*);
int tictactoe(char);
void analysis(char[n][n], bool&);
void move(char[n][n], int&, int&, char);
void drawcheck(char[n][n], bool&);
void firstmovechoice();
void round(bool, char[n][n], int&, int&, int&, int&, char, char);
int main()
{
	firstmovechoice();
	return 0;
}
int inp_num(char msg1, const char* msg2)
{
	char num[10];
	cout << "input " << msg1 << msg2;
	fgets(num, 10, stdin);
	return atoi(num);
}
void firstmovechoice()
{
	char choice;
	do
	{
		cout << "Which player will make the move first, X/O?" << endl;
		choice = _getche();
		switch (choice)
		{
		case 'X':
			while (true)
			{
				tictactoe('X');
			}
			break;
		case 'O':
			while (true)
			{
				tictactoe('O');
			}
			break;
		default:
			break;
		}
	} while (true);
}
int tictactoe(char firstmove)
{
	system("CLS");
	cout << "Xrestiki noliki 1.7. by Shyshk4:" << endl << endl;
	bool end = false;
	char arr[n][n]{};
	int xi, xj, oi, oj;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = '#';
			cout << setw(3) << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
	system("pause");
	system("CLS");
	switch (firstmove)
	{
	case'X':
		round(end, arr, xi, xj, oi, oj, 'X', 'O');
		break;
	case'O':
		round(end, arr, oi, oj, xi, xj, 'O', 'X');
		break;
	default:
		break;
	}
	cout << endl;
	system("pause");
	system("CLS");
	return 0;
}
void analysis(char arr[n][n], bool& end)
{
	int xcount1, xcount2, ocount1, ocount2, xcount3, ocount3, xcount4, ocount4;
	for (int i = 0; i < n; i++)
	{
		xcount1 = xcount2 = ocount1 = ocount2 = xcount3 = ocount3 = xcount4 = ocount4 = 0;
		for (int k = 0; k < n - 1; k++)
		{
			if (arr[k][k] == arr[k + 1][k + 1])
			{
				switch (arr[k][k])
				{
				case 'X':
					xcount3++;
					break;
				case 'O':
					ocount3++;
					break;
				default:
					break;
				}
			}
		}
		for (int l = n - 1, r = 0; l > 0; l--, r++)
		{
			if (arr[r][l] == arr[r + 1][l - 1])
			{
				switch (arr[0][n - 1])
				{
				case 'X':
					xcount4++;
					break;
				case 'O':
					ocount4++;
					break;
				default:
					break;
				}
			}
		}
		for (int j = 0; j < n; j++)
		{
			switch (arr[i][j])
			{
			case 'X':
				xcount1++;
				break;
			case 'O':
				ocount1++;
				break;
			default:
				break;
			}
			switch (arr[j][i])
			{
			case 'X':
				xcount2++;
				break;
			case 'O':
				ocount2++;
				break;
			default:
				break;
			}
		}
		if (xcount1 == n || xcount2 == n || xcount3 == n - 1 || xcount4 == n - 1)
		{
			cout << "X win";
			end = true;
		}
		if (ocount1 == n || ocount2 == n || ocount3 == n - 1 || ocount4 == n - 1)
		{
			cout << "O win";
			end = true;
		}
		if (end == true)
		{
			break;
		}
	}
}
void move(char arr[n][n], int& I, int& J, char msg)
{
	do
	{
		do
		{
			I = inp_num(msg, " vertical:");
		} while (I <= 0 || I > n);
		do
		{
			J = inp_num(msg, " horizontal:");
		} while (J <= 0 || J > n);
	} while (arr[I - 1][J - 1] == 'X' || arr[I - 1][J - 1] == 'O');
	arr[I - 1][J - 1] = msg;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(3) << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void drawcheck(char arr[n][n], bool& sharp)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == '#')
			{
				sharp = true;
			}
		}
	}
}
void round(bool end, char arr[n][n], int& i1, int& j1, int& i2, int& j2, char msg1, char msg2)
{
	bool sharp;
	for (int t = 0; t < n * n; t++)
	{
		sharp = false;
		move(arr, i1, j1, msg1);
		analysis(arr, end);
		if (end == true)
		{
			break;
		}
		drawcheck(arr, sharp);
		if (!sharp)
		{
			cout << "Draw";
			break;
		}
		move(arr, i2, j2, msg2);
		analysis(arr, end);
		if (end == true)
		{
			break;
		}
		drawcheck(arr, sharp);
		if (!sharp)
		{
			cout << "Draw";
			break;
		}
	}
}
