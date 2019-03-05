#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int size = 1000;
const int numbers_to_show = 50000; 

char* sum(char *a, char *b)
{
    char *c = (char*) malloc(sizeof(char)*size);
    for(int i=0; i<size ;i++)
    {
        char s = a[i] + b[i] + c[i];
        if(s>9){
            s-=10;
            c[i+1]+= 1;
        }
        c[i] = s;
    }
    return c;
}

void pfib(char *a, int n)
{
    printf("\n[%d.]\t", n);
    int x;
    for(int i=size-1; ;i--)
        if(a[i]!=0) 
        {
            x = i;
            break;
        }
    
    for(int i=x; i>=0; i--)
	{
        printf("%c", (a[i]+48));
	}
}

void fib(char*a,char*b,int n)
{
    char *c = sum(a,b);
    //pfib(c,n);
    if(n<numbers_to_show)
        fib(b,c, ++n);
    else
        //printf("\nTheEnd!\n");
        pfib(c, n);
}

void rc()
{
	printf("reached checkpoint!\n");
}

char* initialize()
{
	char* r = (char*) malloc(sizeof(char)*size);
	for(int i=0; i<size;i++)
		r[i] = 0;
	r[0] = 1;
	return r;
}

int main()
{
    clock_t begin = clock();
    char *a,*b; 
	a = initialize();
	b = initialize();

    fib(a,b,3);
    clock_t end = clock();
    printf("\n%f\n", (float)(end-begin)/CLOCKS_PER_SEC);
    return 0;
}