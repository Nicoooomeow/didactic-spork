#include <iostream>
using namespace std;
typedef int Status;
typedef struct 
{
	char *ch;   //字符
	int length; //字符串长度
}HString;
Status StrAssign(HString &A, char *chars)//生成一个值等于串常量chars的串
{
	int i=0;
	char *p = chars;
	for (i = 0; *p ; i++, p++);//求chars的长度i
	if (!i)
	{
		A.ch = 0;
		A.length = 0; 
	}
	else 
	{
		A.ch = new char[i];
		if (!A.ch)
		{
			return 0;
		}
		for (int j = 0; j < i; j++)
		{
			A.ch[j] = chars[j];
		}
		A.length = i;
	}
	return 1;
}
Status Index(HString T, HString S, int pos) //朴素模式,返回子串T在主串S中第pos个字符之后的位置。若不存在，返回-1
{
	int i = pos;
	int j = 0;
	while (i<T.length && j<S.length)
	{
		if (T.ch[i] == S.ch[j]) 
		{
			i++;
			j++;
		}
		else 
		{ 
			i = i - j + 1; 
			j = 0;
		}
	}
	if (j >= S.length)
	{
		return i - S.length;
	}
	else
	{
		return  -1;
	}
}
Status Delete(HString&S, int pos, int len)//删除函数，删除查出相同的部分
{
	int i = pos;
	while (i < S.length - len) 
	{
		S.ch[i] = S.ch[i + len];
		i++;
	}
	S.length = S.length - len;
	return 1;
}