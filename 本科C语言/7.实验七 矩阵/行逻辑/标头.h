#include<iostream>
using namespace std;
#define MAXSIZE 100
//#define MAXRC 10
typedef int ElemType;
typedef int Status;
typedef struct
{
	int i;//����Ԫ�ص����±�
	int j;//����Ԫ�ص����±�
	ElemType e;
}Triple;
typedef struct
{
	Triple data[MAXSIZE + 1];
	int mu, nu, tu;//����������������Ԫ����
}RLSMatrix;
Status Init(RLSMatrix &M)//���������
{
	int i, j, nz;
	ElemType e;
	cout << "����������������" << endl;
	cin >> M.mu;
	cout << "����������������" << endl;
	cin >> M.nu;
	cout << "���������ķ���Ԫ�ظ�����" << endl;
	cin >> nz;
	M.tu = 1;
	cout << "�밴���������������з���Ԫ�ص��б꣬�б꣬Ԫ��ֵ���벻Ҫ����0Ԫ�أ�" << endl;
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
Status Add(RLSMatrix M, RLSMatrix N, RLSMatrix &Q)//������Ӻ���
{
	int  k = 1, p = 1, q = 1;
	if (M.mu != N.mu || M.nu != N.nu) //�жϿɷ����
	{
		return 0;
	}
	Q.mu = M.mu; 
	Q.nu = M.nu;
	while (p <= M.tu)//��
	{
		if (M.data[p].i < N.data[q].i)//ɸѡ����Ԫ��
		{
			Q.data[k].i = M.data[p].i;
			Q.data[k].j = M.data[p].j;
			Q.data[k].e = M.data[p].e;
			p++; k++;
		}
		else if (M.data[p].i > N.data[q].i)//ɸѡ����Ԫ��
		{
			Q.data[k].i = N.data[q].i;
			Q.data[k].j = N.data[q].j;
			Q.data[k].e = N.data[q].e;
			q++; k++;
		}
		else 
		{
			if (M.data[p].j > N.data[q].j)//ɸѡ����Ԫ��
			{
				Q.data[k].i = N.data[q].i;
				Q.data[k].j = N.data[q].j;
				Q.data[k].e = N.data[q].e;
				q++; k++;
			}
			else if (M.data[p].j < N.data[q].j) //ɸѡ����Ԫ��
			{
				Q.data[k].i = M.data[p].i;
				Q.data[k].j = M.data[p].j;
				Q.data[k].e = M.data[p].e;
				p++; k++;
			}
			else 
			{
				if (M.data[p].e + N.data[q].e != 0) //�ж���Ӻ����Ԫ��
				{
					Q.data[k].i = M.data[p].i;
					Q.data[k].j = M.data[p].j;
					Q.data[k].e = M.data[p].e + N.data[q].e;//��ʼ��
					k++;
				}
				q++;
				p++;
			}
		}
	}
	while (q <= N.tu)//�����©Ԫ��
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
Status Traverse(RLSMatrix M)//���������������ʽ��
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