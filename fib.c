#include <stdio.h>


const int size = 5;
const int number_to_show = 9;

void sum(unsigned char*a, unsigned char*b)
{
	unsigned int carry = 0;

	for(int i = 0; i < size; i++)
	{
		unsigned int tmp = a[i] + b[i] + carry;
		carry = tmp >> 8;
		
		a[i] = (unsigned char)tmp;
	}
}

int fib()
{
		
}

int main()
{
	unsigned char *a,*b;
	a = (unsigned char*) malloc( sizeof(char)*size));
	b = (unsigned char*) malloc( sizeof(char)*size));

	a[0] = 128;
	b[0] = 128;

	a[1] = 2;
	b[1] = 5;

	a[2] = 3;

	sum(a, b);

	for (int i = 0; i < 5; ++i)
	{
		printf("%d\n", a[i]);
	}

//	printf("%d", fib(a,b,number_to_show);

}