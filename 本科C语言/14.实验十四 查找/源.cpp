//索引顺序查找70和80
//索引表用折半查找，分块用顺序查找方法，每个分块长度为4
#include"标头.h"
int main()
{
	int i;
	int a[ksize] = { 17,8,21,19,31,33,22,25,42,37,40,52,61,78,73,55,94,88,79,85 };
	cout << "表中元素为" << endl;
	for (i = 0; a[i]; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << endl;
	SSTable ST;
	InitTable(ST);
	GetTable(ST, a);
	int key;

	cout << "现在进行顺序查找" << endl;
	cout << "查找78" << endl;
	key = 78;
	i = Search_Seq(ST, key);
	if (i == 0)
	{
		cout << "表中无该元素" << endl;
	}
	else
	{
		cout <<"该元素在表中位置为"<< i << endl;
	}
	cout << endl;
	cout << "查找80" << endl;
	key = 80;
	i = Search_Seq(ST, key);
	if (i == 0)
	{
		cout << "表中无该元素" << endl;
	}
	else
	{
		cout << "该元素在表中位置为" << i << endl;
	}	
	cout << endl;
	system("pause");
	cout << endl;
	cout << "现在进行折半查找" << endl;
	order(ST);
	cout << "查找78" << endl;
	key = 78;
	i = Search_Bin(ST, key);
	if (i == 0)
	{
		cout << "表中无该元素" << endl;
	}
	else
	{
		cout << "该元素在表中位置为" << i << endl;
	}
	cout << endl;
	cout << "查找80" << endl;
	key = 80;
	i = Search_Bin(ST, key);
	if (i == 0)
	{
		cout << "表中无该元素" << endl;
	}
	else
	{
		cout << "该元素在表中位置为" << i << endl;
	}
	cout << endl;
	system("pause");
	cout << endl;
	indexTable ID;
	InitIndex(ST, ID);
	cout << "索引表为：" ;
	for (i = 0; i < ID.length; i++)
	{
		cout << ID.elem[i].key << " ";
	}
	cout << endl;
	cout << "现在进行分块查找" << endl;
	cout << endl;
	cout << "查找78" << endl;
	key = 78;
	i = Search_Idx(ST, ID, key);
	if (i == 0)
	{
		cout << "表中无该元素" << endl;
	}
	else
	{
		cout << "该元素在表中位置为" << i << endl;
	}
	cout << endl;
	cout << "查找80" << endl;
	key = 80;
	i=Search_Idx(ST, ID, key);
	if (i == 0)
	{
		cout << "表中无该元素" << endl;
	}
	else
	{
		cout << "该元素在表中位置为" << i << endl;
	}
	system("pause");
}