/*
根据字符集（字符、权值）建立赫夫曼树，对由字符集组成的代码编码、译码，
并输出相应的编码及译码结果。
（该赫夫曼树中共有n=8个叶子结点，对应叶子结点的权值分别为：
w={5，29，7，8，14，23，3，11}）
*/
#include"赫夫曼树.h"
int main()
{
	int n, i, j;
	ElemWeight T;
	HuffmanTree HT;
	HuffmanCode HC;
	cout << "输入叶子结点个数" << endl;
	cin >> n;
	CreateElemWeight(T, n);
	CreateHuffmanTree(HT, T, n);
	HuffmanCoding(HT, HC, n);

	cout << "HT的终态" << endl;
	cout << "         " << "elem    " << "weight  " << "parent   " << "lchild  " << "rchild  " << endl;
	for (i = 1; i <= 2 * n - 1; i++)
	{
		cout << "  " << i << "        " << HT[i].ch << "       " << HT[i].weight << "       " << HT[i].parent << "        " << HT[i].lchild << "       " << HT[i].rchild << endl;
	}
	cout << "HT的赫夫曼编码表为" << endl;
	for (j = 1; j <= n; j++)
	{
		cout << j << "  " << T.elem[j] << "   " << HC[j] << endl;
	}
	cout << endl;
}