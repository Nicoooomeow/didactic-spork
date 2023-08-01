#include<iostream>
using namespace std;
#define MAXSIZE 100
//#define MAXRC 10
typedef int ElemType;
typedef int Status;
typedef struct
{
	int i;//非零元素的行下标
	int j;//非零元素的列下标
	ElemType e;
}Triple;
typedef struct
{
	Triple data[MAXSIZE + 1];
	int mu, nu, tu;//行数，列数，非零元个数
}RLSMatrix;
Status Init(RLSMatrix &M)//输入矩阵函数
{
	int i, j, nz;
	ElemType e;
	cout << "请输入矩阵的行数：" << endl;
	cin >> M.mu;
	cout << "请输入矩阵的列数：" << endl;
	cin >> M.nu;
	cout << "请输入矩阵的非零元素个数：" << endl;
	cin >> nz;
	M.tu = 1;
	cout << "请按任意次序输入矩阵中非零元素的行标，列标，元素值（请不要输入0元素）" << endl;
	while (M.tu <= nz)
	{
		cin >> i >> j >> e;
		if (e != 0)
		{
			M.data[M.tu].i = i;
			M.data[M.tu].j = j;
			M.data[M.tu].e = e;
			M.tu++;
		}
	}
	return 1;
}
Status Add(RLSMatrix M, RLSMatrix N, RLSMatrix &Q)//矩阵相加函数
{
	int  k = 1, p = 1, q = 1;
	if (M.mu != N.mu || M.nu != N.nu) //判断可否相加
	{
		return 0;
	}
	Q.mu = M.mu; 
	Q.nu = M.nu;
	while (p <= M.tu)//列
	{
		if (M.data[p].i < N.data[q].i)//筛选非零元素
		{
			Q.data[k].i = M.data[p].i;
			Q.data[k].j = M.data[p].j;
			Q.data[k].e = M.data[p].e;
			p++; k++;
		}
		else if (M.data[p].i > N.data[q].i)//筛选非零元素
		{
			Q.data[k].i = N.data[q].i;
			Q.data[k].j = N.data[q].j;
			Q.data[k].e = N.data[q].e;
			q++; k++;
		}
		else 
		{
			if (M.data[p].j > N.data[q].j)//筛选非零元素
			{
				Q.data[k].i = N.data[q].i;
				Q.data[k].j = N.data[q].j;
				Q.data[k].e = N.data[q].e;
				q++; k++;
			}
			else if (M.data[p].j < N.data[q].j) //筛选非零元素
			{
				Q.data[k].i = M.data[p].i;
				Q.data[k].j = M.data[p].j;
				Q.data[k].e = M.data[p].e;
				p++; k++;
			}
			else 
			{
				if (M.data[p].e + N.data[q].e != 0) //判断相加后非零元素
				{
					Q.data[k].i = M.data[p].i;
					Q.data[k].j = M.data[p].j;
					Q.data[k].e = M.data[p].e + N.data[q].e;//开始加
					k++;
				}
				q++;
				p++;
			}
		}
	}
	while (q <= N.tu)//检查遗漏元素
	{
		Q.data[k].i = N.data[q].i;
		Q.data[k].j = N.data[q].j;
		Q.data[k].e = N.data[q].e;
		q++;
		k++;
	}
	Q.tu = k - 1;
	return 1;
}
Status Traverse(RLSMatrix M)//输出函数（矩阵形式）
{
	int e;
	for (int i = 1; i <= M.mu; i++)
	{
		for (int j = 1; j <= M.nu; j++)
		{
			e = 0;
			for (int k = 1; k <= M.tu; k++) 
			{
				if (i == M.data[k].i&&j == M.data[k].j) 
				{
					e = M.data[k].e;
					break;
				}
			}
			cout << e << " ";
		}
		cout << endl;
	}
	return 1;
}