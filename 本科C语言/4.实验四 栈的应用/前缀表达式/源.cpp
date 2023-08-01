#include"标头.h"
int main()
{
	cout << "输入要转换的中缀表达式，请输入“#”作为结束符,若输入括号请使用英文字符" << endl<<"y=";
	char string[20];
	int n = 0;
	for (int i = 0; i<20; i++)
	{
		cin >> string[i];
		if (string[i] == '#')
		{
			n = i + 1;
			break;
		}
	}
	cout << "输入的表达式为：" << endl;
	for (int i = 0; i<n - 1; i++)
	{
		cout << string[i];
	}
	cout << endl;
	system("pause");
	cout<<"转换为前缀表达式为："<<endl;
	change(string, n - 1);
	cout << endl;
	system("pause");
}