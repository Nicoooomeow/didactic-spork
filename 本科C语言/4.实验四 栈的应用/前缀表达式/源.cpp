#include"��ͷ.h"
int main()
{
	cout << "����Ҫת������׺���ʽ�������롰#����Ϊ������,������������ʹ��Ӣ���ַ�" << endl<<"y=";
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
	cout << "����ı��ʽΪ��" << endl;
	for (int i = 0; i<n - 1; i++)
	{
		cout << string[i];
	}
	cout << endl;
	system("pause");
	cout<<"ת��Ϊǰ׺���ʽΪ��"<<endl;
	change(string, n - 1);
	cout << endl;
	system("pause");
}