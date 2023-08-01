#include<iostream>
using namespace std;
template<class T1, class T2, class T3>
T3 inittriplet(T1 &T, T2 v1, T2 v2, T2 v3)
{
	T = new T2[3];     //申请三元组空间
	if (!T) 
	{ 
		cout << "overflow" << endl;
		return 0; 
	}
	T[0] = v1;
	T[1] = v2;
	T[2] = v3;
	return 1;
}//构造三元组

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
}//取最大值

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
}//降序排列

template<class T1>
void traverse(T1 T)        //输出
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
T2 destory(T1 &T)        //hiahiahiahia销毁三元组

{
	delete T;
	T = NULL;
	return 1;
}
