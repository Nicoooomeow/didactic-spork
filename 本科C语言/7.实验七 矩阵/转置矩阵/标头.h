#include<iostream>
using namespace std;
#define MAXSIZE 20
typedef int ElemType;
typedef int Status;
typedef int Triple[100][3];
/*typedef struct
{
	int hang;      //该非零元的行下标
	int lie;      //该非零元的列下标
	ElemType e;
}Triple;*/
class matrix  //矩阵
{
public:
	int data[MAXSIZE][MAXSIZE];
	int mu;   //矩阵的行数
	int nu;   //列数
	//int tu;   //非零元个数
};
Status initmatrix(matrix &input) //输入矩阵
{
	cout << "行数:";
	cin >> input.mu;
	cout << "列数:";
	cin >> input.nu;
	cout << "输入矩阵:" << endl;
	for (int i = 0; i <input.nu; i++)//行
	{
		for (int j = 0; j <input.mu; j++)//列
		{
			cin >> input.data[i][j];
		}
	}
	return 1;
}
Status Compressmatrix(matrix A, Triple B)  //矩阵转为三元组
{
	int  k = 1;
	for (int i = 0; i < A.mu; i++)//行
	{
		for (int j = 0; j < A.nu; j++)//列
		{
			
				B[k][0] = i ;
				B[k][1] = j ;
				B[k][2] = A.data[i][j];
				k++;
		}
	}
	B[0][0] = A.mu;//用作计数
	B[0][1] = A.nu;//用作计数
	B[0][2] = k - 1;//用作计数
	return 1;
}
Status Transpmatrix(Triple B, Triple & C)  //将三元组矩阵转置
{
	int i, j, t, m, n;
	int x[100];
	int y[100];
	m = B[0][0];
	n = B[0][1];
	t = B[0][2];
	C[0][0] = n;
	C[0][1] = m;
	C[0][2] = t;
	if (t>0)
	{
		for (i = 0; i < n; i++)
		{
			x[i] = 0;
		}
		for (i = 1; i <= t; i++)
		{
			x[B[i][1]] = x[B[i][1]] + 1;
		}
		y[0] = 1;
		for (i = 1; i < n; i++)
		{
			y[i] = y[i - 1] + x[i - 1];
		}
		for (i = 1; i <= t; i++)
		{
			j = y[B[i][1]];
			C[j][0] = B[i][1];
			C[j][1] = B[i][0];
			C[j][2] = B[i][2];
			y[B[i][1]] = j + 1;
		}
	}
	return 1;
}
Status Traverse(Triple spm) //按三元组方式输出函数
{
	for (int x = 0; x <= spm[0][2]; x++)
	{
		if (spm[x][2] == 0)
		{
			continue;
		}
		for (int y = 0; y <= 2; y++)
		{
			static int z = 0;
			if (0 == z % 3)
			{
				cout << endl;
			}
			z++;
			if ((y == 0 || y == 1)&&x!=0)
			{
				cout << spm[x][y] + 1 << ' ';
				continue;
			}
			
			cout << spm[x][y] << ' ';
			
		}
		if (x == 0)
			{
				cout<< endl<<"＿＿＿" ;
			}
	}
	cout << endl;
	return 1;
}
Status Traversehahaha(Triple B,matrix input)//按矩阵方式输出
{
	int z = 0;
	for (int x = 1; x <=input.mu*input.nu; x++)
	{
		if (z == input.nu)
		{
			cout << endl;
			z = 0;
		}
		z++;
		cout << B[x][2] << ' ';
	}
	cout << endl;
	return 1;
}