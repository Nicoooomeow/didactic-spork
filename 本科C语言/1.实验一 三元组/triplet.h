#include<iostream>
using namespace std;
template<class T1, class T2, class T3>
T3 inittriplet(T1 &T, T2 v1, T2 v2, T2 v3)
{
	T = new T2[3];     //������Ԫ��ռ�
	if (!T) 
	{ 
		cout << "overflow" << endl;
		return 0; 
	}
	T[0] = v1;
	T[1] = v2;
	T[2] = v3;
	return 1;
}//������Ԫ��

template<class T1, class T2>
void max(T1 T, T2 &e) {
	int i;
	e = T[0];
	for (i = 1;i < 3;i++)
	{
		if (T[i] > e)
		{
			e = T[i];
		}
	}
}//ȡ���ֵ

template<class T1, class T2>
void descending(T1 &T)
{
	for (int i = 0;i<2;i++)
	{
		T2 t;
		int j = i;
		for (int k = i + 1;k < 3;k++)
		{
			if (T[k] > T[i])
			{
				j = k;
			}
		}
		if (j != i)
		{
			t = T[i];
			T[i] = T[j];
			T[j] = t;
		}
	}
}//��������

template<class T1>
void traverse(T1 T)        //���
{
	if (!T)
	{
		cout << "the triplet is empty" << endl;
	}
	else
	{
		for (int i = 0;i < 3;i++)
		{
			cout << T[i] << " ";
		}
	}
	cout << endl;
}

template<class T1, class T2>
T2 destory(T1 &T)        //hiahiahiahia������Ԫ��

{
	delete T;
	T = NULL;
	return 1;
}
