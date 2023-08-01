#include<iostream>  
#include<string>  //此句顶200行代码
using namespace std;
enum elemTag
{ 
	ATOM, LIST//ATOM==0:原子，LIST==1：子表
};
typedef struct GLNode
{
	elemTag Tag; //标志是原子还是子表 0:原子 1:子表  
	union
	{
		char data; //原子结点值域  
		struct //表结点指针域  
		{
			GLNode *hp;//hp指向表头
			GLNode *tp;//tp指向表尾
		}ptr;//表结点的指针域
	}; 
}*GList;//是一种扩展的线性链表
string sever(string &str)//将非空串str分割成2部分，hstr为第一个','之前的子串，str为后面的  
{
		
	int n, i, k;
	string ch, hstr;
	n = str.length();
	for (i = 0, k = -1; i < n && (ch != "," || k != 0); i++)//搜索最外层第一个逗号  
	{
		ch = str.substr(i, 1); //从第i个位置起读1个字符 
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
		hstr = str.substr(1, i - 2);//不要左括号和逗号，i-2  
		str = "(" + str.substr(i, n - i);
	}
	else
	{
		hstr = str.substr(1, n - 2);
		str = "";
	}
	return hstr;
}
void CreateGList(GLNode *&L, string S) //创建广义表 创建采用头尾链表存储表示的广义表T
{
	string hsub;
	if (S == "()") //S为空串  
	{
		L = NULL;//创建空表
	}
	else
	{
		L = new GLNode;//建表结点
		if (S.length() == 1)//创建单原子广义表
		{
			L->Tag = ATOM;
			L->data = S[0];
		}
		else
		{
			L->Tag = LIST;
			hsub = sever(S); //从S中分离出表头串hsub  
			CreateGList(L->ptr.hp, hsub);//假设sub为脱去S最外层括号的子串，记为"s1,s2,s3,..,sn"
			if (S.empty())//每个si为非空字符串，对每个si建立一个表结点
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
int Depth(GLNode *L) //求广义表深度  
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
void Traverse(GLNode *L)//遍历广义表
{
	if (!L)
	{
		cout << "()";//如果是空表就输出"()"
	}
	else
	{
		if (L->Tag == ATOM)//如果遇到Tag=0的结点，则直接输出该结点的值
		{
			cout << L->data;
		}
		else
		{//如果tag=1，说明是一个子表，首先输出左括号
			GLNode *p = NULL;
			cout << '(';
			p = L;
			while (p)
			{
				Traverse(p->ptr.hp);
				p = p->ptr.tp;
				if (p)//然后递归调用输出数据元素，并当表尾不空的时候输出逗号
				{
					cout << ',';
				}
			}
			cout << ')';//at last输出右括号
		}
	}
}
int Length(GLNode *L) //求表长，非递归  
{
	int len = 0;//表长
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
