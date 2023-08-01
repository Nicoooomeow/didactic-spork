#include<iostream>
using namespace std;
#define MAXSIZE 20
typedef int ElemType;
typedef int Status;
typedef int Triple[100][3];
/*typedef struct
{
	int hang;      //�÷���Ԫ�����±�
	int lie;      //�÷���Ԫ�����±�
	ElemType e;
}Triple;*/
class matrix  //����
{
public:
	int data[MAXSIZE][MAXSIZE];
	int mu;   //���������
	int nu;   //����
	//int tu;   //����Ԫ����
};
Status initmatrix(matrix &input) //�������
{
	cout << "����:";
	cin >> input.mu;
	cout << "����:";
	cin >> input.nu;
	cout << "�������:" << endl;
	for (int i = 0; i <input.nu; i++)//��
	{
		for (int j = 0; j <input.mu; j++)//��
		{
			cin >> input.data[i][j];
		}
	}
	return 1;
}
Status Compressmatrix(matrix A, Triple B)  //����תΪ��Ԫ��
{
	int  k = 1;
	for (int i = 0; i < A.mu; i++)//��
	{
		for (int j = 0; j < A.nu; j++)//��
		{
			
				B[k][0] = i ;
				B[k][1] = j ;
				B[k][2] = A.data[i][j];
				k++;
		}
	}
	B[0][0] = A.mu;//��������
	B[0][1] = A.nu;//��������
	B[0][2] = k - 1;//��������
	return 1;
}
Status Transpmatrix(Triple B, Triple & C)  //����Ԫ�����ת��
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
Status Traverse(Triple spm) //����Ԫ�鷽ʽ�������
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
				cout<< endl<<"�ߣߣ�" ;
			}
	}
	cout << endl;
	return 1;
}
Status Traversehahaha(Triple B,matrix input)//������ʽ���
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