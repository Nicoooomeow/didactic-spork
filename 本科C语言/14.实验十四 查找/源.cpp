//����˳�����70��80
//���������۰���ң��ֿ���˳����ҷ�����ÿ���ֿ鳤��Ϊ4
#include"��ͷ.h"
int main()
{
	int i;
	int a[ksize] = { 17,8,21,19,31,33,22,25,42,37,40,52,61,78,73,55,94,88,79,85 };
	cout << "����Ԫ��Ϊ" << endl;
	for (i = 0; a[i]; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << endl;
	SSTable ST;
	InitTable(ST);
	GetTable(ST, a);
	int key;

	cout << "���ڽ���˳�����" << endl;
	cout << "����78" << endl;
	key = 78;
	i = Search_Seq(ST, key);
	if (i == 0)
	{
		cout << "�����޸�Ԫ��" << endl;
	}
	else
	{
		cout <<"��Ԫ���ڱ���λ��Ϊ"<< i << endl;
	}
	cout << endl;
	cout << "����80" << endl;
	key = 80;
	i = Search_Seq(ST, key);
	if (i == 0)
	{
		cout << "�����޸�Ԫ��" << endl;
	}
	else
	{
		cout << "��Ԫ���ڱ���λ��Ϊ" << i << endl;
	}	
	cout << endl;
	system("pause");
	cout << endl;
	cout << "���ڽ����۰����" << endl;
	order(ST);
	cout << "����78" << endl;
	key = 78;
	i = Search_Bin(ST, key);
	if (i == 0)
	{
		cout << "�����޸�Ԫ��" << endl;
	}
	else
	{
		cout << "��Ԫ���ڱ���λ��Ϊ" << i << endl;
	}
	cout << endl;
	cout << "����80" << endl;
	key = 80;
	i = Search_Bin(ST, key);
	if (i == 0)
	{
		cout << "�����޸�Ԫ��" << endl;
	}
	else
	{
		cout << "��Ԫ���ڱ���λ��Ϊ" << i << endl;
	}
	cout << endl;
	system("pause");
	cout << endl;
	indexTable ID;
	InitIndex(ST, ID);
	cout << "������Ϊ��" ;
	for (i = 0; i < ID.length; i++)
	{
		cout << ID.elem[i].key << " ";
	}
	cout << endl;
	cout << "���ڽ��зֿ����" << endl;
	cout << endl;
	cout << "����78" << endl;
	key = 78;
	i = Search_Idx(ST, ID, key);
	if (i == 0)
	{
		cout << "�����޸�Ԫ��" << endl;
	}
	else
	{
		cout << "��Ԫ���ڱ���λ��Ϊ" << i << endl;
	}
	cout << endl;
	cout << "����80" << endl;
	key = 80;
	i=Search_Idx(ST, ID, key);
	if (i == 0)
	{
		cout << "�����޸�Ԫ��" << endl;
	}
	else
	{
		cout << "��Ԫ���ڱ���λ��Ϊ" << i << endl;
	}
	system("pause");
}