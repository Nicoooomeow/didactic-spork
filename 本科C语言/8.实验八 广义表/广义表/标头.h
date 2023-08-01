#include<iostream>  
#include<string>  //�˾䶥200�д���
using namespace std;
enum elemTag
{ 
	ATOM, LIST//ATOM==0:ԭ�ӣ�LIST==1���ӱ�
};
typedef struct GLNode
{
	elemTag Tag; //��־��ԭ�ӻ����ӱ� 0:ԭ�� 1:�ӱ�  
	union
	{
		char data; //ԭ�ӽ��ֵ��  
		struct //����ָ����  
		{
			GLNode *hp;//hpָ���ͷ
			GLNode *tp;//tpָ���β
		}ptr;//�����ָ����
	}; 
}*GList;//��һ����չ����������
string sever(string &str)//���ǿմ�str�ָ��2���֣�hstrΪ��һ��','֮ǰ���Ӵ���strΪ�����  
{
		
	int n, i, k;
	string ch, hstr;
	n = str.length();
	for (i = 0, k = -1; i < n && (ch != "," || k != 0); i++)//����������һ������  
	{
		ch = str.substr(i, 1); //�ӵ�i��λ�����1���ַ� 
		if (ch == "(")
		{
			++k;
		}
		else if (ch == ")")
		{
			--k;
		}
	}
	if (i < n)
	{
		hstr = str.substr(1, i - 2);//��Ҫ�����źͶ��ţ�i-2  
		str = "(" + str.substr(i, n - i);
	}
	else
	{
		hstr = str.substr(1, n - 2);
		str = "";
	}
	return hstr;
}
void CreateGList(GLNode *&L, string S) //��������� ��������ͷβ����洢��ʾ�Ĺ����T
{
	string hsub;
	if (S == "()") //SΪ�մ�  
	{
		L = NULL;//�����ձ�
	}
	else
	{
		L = new GLNode;//������
		if (S.length() == 1)//������ԭ�ӹ����
		{
			L->Tag = ATOM;
			L->data = S[0];
		}
		else
		{
			L->Tag = LIST;
			hsub = sever(S); //��S�з������ͷ��hsub  
			CreateGList(L->ptr.hp, hsub);//����subΪ��ȥS��������ŵ��Ӵ�����Ϊ"s1,s2,s3,..,sn"
			if (S.empty())//ÿ��siΪ�ǿ��ַ�������ÿ��si����һ������
			{
				L->ptr.tp = NULL;
			}
			else
			{
				CreateGList(L->ptr.tp, S);
			}
		}
	}
}
int Depth(GLNode *L) //���������  
{
	if (!L)
	{
		return 1;
	}
	if (L->Tag == ATOM)
	{
		return 0;
	}
	int dep, max;
	GLNode *p;
	for (max = 0, p = L; p; p = p->ptr.tp)
	{
		dep = Depth(p->ptr.hp);
		if (dep > max)
		{
			max = dep;
		}
	}
	return 1 + max;
}
void Traverse(GLNode *L)//���������
{
	if (!L)
	{
		cout << "()";//����ǿձ�����"()"
	}
	else
	{
		if (L->Tag == ATOM)//�������Tag=0�Ľ�㣬��ֱ������ý���ֵ
		{
			cout << L->data;
		}
		else
		{//���tag=1��˵����һ���ӱ��������������
			GLNode *p = NULL;
			cout << '(';
			p = L;
			while (p)
			{
				Traverse(p->ptr.hp);
				p = p->ptr.tp;
				if (p)//Ȼ��ݹ�����������Ԫ�أ�������β���յ�ʱ���������
				{
					cout << ',';
				}
			}
			cout << ')';//at last���������
		}
	}
}
int Length(GLNode *L) //������ǵݹ�  
{
	int len = 0;//��
	if (L && L->Tag == LIST)
	{
		while (L)
		{
			L =L->ptr.tp;
			len++;
		}
		return len;
	}
	else
	{
		return 0;
	}
}
