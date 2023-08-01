#include"triplet.h"
typedef int * inttriplet;
typedef float * floattriplet;
using namespace std;
int main()
{
	inttriplet A;
	floattriplet B;
	int intmaxvalue;
	float floatmaxvalue;
	int label1 = inittriplet<inttriplet,int,int>(A, 12, 5, 34);
	int label2 = inittriplet<floattriplet,float,int>(B, 12.5, 1.2, 124.6);
	max(A, intmaxvalue);
	cout << "the max of triplet A is:" << intmaxvalue << endl;
	max(B, floatmaxvalue);
	cout << "the max of triplet B is:" << floatmaxvalue << endl;
	descending<inttriplet, int>(A);
	traverse(A);
	descending<floattriplet, float>(B);
	traverse(B);
	
	int lololo = destory<inttriplet, int>(A);
	if (lololo)cout << "A is successfully destoried" << endl;

	int lululu = destory<floattriplet, float>(B);
	if (lululu)cout << "B is successfully destoried" << endl;
	return 1;

}

