/*
�����ַ������ַ���Ȩֵ�������շ������������ַ�����ɵĴ�����롢���룬
�������Ӧ�ı��뼰��������
���úշ������й���n=8��Ҷ�ӽ�㣬��ӦҶ�ӽ���Ȩֵ�ֱ�Ϊ��
w={5��29��7��8��14��23��3��11}��
*/
#include"�շ�����.h"
int main()
{
	int n, i, j;
	ElemWeight T;
	HuffmanTree HT;
	HuffmanCode HC;
	cout << "����Ҷ�ӽ�����" << endl;
	cin >> n;
	CreateElemWeight(T, n);
	CreateHuffmanTree(HT, T, n);
	HuffmanCoding(HT, HC, n);

	cout << "HT����̬" << endl;
	cout << "         " << "elem    " << "weight  " << "parent   " << "lchild  " << "rchild  " << endl;
	for (i = 1; i <= 2 * n - 1; i++)
	{
		cout << "  " << i << "        " << HT[i].ch << "       " << HT[i].weight << "       " << HT[i].parent << "        " << HT[i].lchild << "       " << HT[i].rchild << endl;
	}
	cout << "HT�ĺշ��������Ϊ" << endl;
	for (j = 1; j <= n; j++)
	{
		cout << j << "  " << T.elem[j] << "   " << HC[j] << endl;
	}
	cout << endl;
}