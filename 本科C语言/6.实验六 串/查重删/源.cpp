#include "标头.h"
int main()
{
	char a[100];
	char b[100];
	HString S;
	HString T;
	cout << "输入主串S" << endl;
	cin >> a;
	if (!StrAssign(S, a))
	{ 
		cout << "生成失败!" << endl;
	}
	cout << "输入子串T" << endl;
	cin >> b;
	if (!StrAssign(T, b))
	{
		cout << "生成失败!" << endl;
	}
	cout << "查找主串S中是否含有子串T并将重复的删除" << endl;
	system("pause");
	int n = 0;
	int x = 0;
	for (int w = 0; w >= 0; w++)
	{
		n = Index(S, T, 0);
		if (n == -1)//若无匹配，则退出循环
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
		x = w + 1;//我也不知道为什么结束循环w就为0了
	}
	cout << "删除后的主串为:" << endl;
	for (int i = 0; i < S.length; i++)
	{
		cout << S.ch[i];
	}
	cout << endl;
	cout << "子串在主串中重复了" << x << "遍" << endl;
	system("pause");
	return 0;
}
