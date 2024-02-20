#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define N 10

int cmp(const void * a , const void *b);
void insert(void * data , int size ,int width , int(*cmp)(const void * , const void * ));
int main()
{
	int i ,j ;

	float num[N],tmp;

	srand(time(NULL));

	for(i = 0 ; i < N ;i++)
	{
		tmp  = rand() % 100 * ((float)rand()/RAND_MAX);

		for(j = 0 ; j < i ; j++)
		{
			if(num[j] == tmp) break;
		}
		if(i == j) num[i] = tmp;
		else i--;
	}

	insert(num,N,sizeof(float),cmp);


	for(i =0 ; i < N ; i++)
		printf("%g " , num[i]);
	printf("\n");

	return 0;
}


void insert(void * data , int size ,int width , int(*cmp)(const void * , const void * ))
{
	int i , j;

	void * k = malloc(width);

	for(i = 0 ; i <size ; i++)
	{
		if(cmp(data+i*width , data+(i-1)*width)<0)
		{
			memcpy(k , data + i * width ,width);
			for(j = i - 1 ; j >= 0&& cmp(k,data+j*width)<0;j--)
				memcpy(data + (j+1)*width ,data+j*width,width);

			memcpy(data + (j+1)*width ,k,width);
		}
			
	
	}

}



int cmp(const void * a , const void *b)
{
	const float * pa = a , * pb = b;

	if(*pa > *pb) return -1;

	if(*pb< *pb) return 1;
}
