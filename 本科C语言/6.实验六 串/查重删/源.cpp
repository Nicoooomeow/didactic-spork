#include "��ͷ.h"
int main()
{
	char a[100];
	char b[100];
	HString S;
	HString T;
	cout << "��������S" << endl;
	cin >> a;
	if (!StrAssign(S, a))
	{ 
		cout << "����ʧ��!" << endl;
	}
	cout << "�����Ӵ�T" << endl;
	cin >> b;
	if (!StrAssign(T, b))
	{
		cout << "����ʧ��!" << endl;
	}
	cout << "��������S���Ƿ����Ӵ�T�����ظ���ɾ��" << endl;
	system("pause");
	int n = 0;
	int x = 0;
	for (int w = 0; w >= 0; w++)
	{
		n = Index(S, T, 0);
		if (n == -1)//����ƥ�䣬���˳�ѭ��
		{
			break;
		}
		else
		{
			while (n != -1)
			{
				Delete(S, n, T.length);
				n = Index(T, S, n);
			}
		}
		x = w + 1;//��Ҳ��֪��Ϊʲô����ѭ��w��Ϊ0��
	}
	cout << "ɾ���������Ϊ:" << endl;
	for (int i = 0; i < S.length; i++)
	{
		cout << S.ch[i];
	}
	cout << endl;
	cout << "�Ӵ����������ظ���" << x << "��" << endl;
	system("pause");
	return 0;
}
