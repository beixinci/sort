#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define N 10

int cmp(const void * a , const void * b);
void select_s(void * data , int size , int width , int(*cmp)(const void * , const void *));
int main()
{
	int i , j ;
	float k , num[N];
	
	srand(time(NULL));

	for(i = 0 ; i < N ; i++)
	{
		k = ((float)rand()/RAND_MAX) * (rand()% 100);
		for(j = 0 ; j < i ; j++)
		{
			if(num[j] == k) break;
		}
		if(i == j) num[i] = k;
		else i--;
	}

	select_s(num,10,4,cmp);

	for(int i = 0 ; i < N ;i++)
		printf("%g " , num[i]);
	printf("\n");

	return 0;
}

void select_s(void * data , int size , int width , int(*cmp)(const void * , const void *))
{
	int i , j , k ;
	void * tmp = malloc(width);

	for(i = 0 ; i < size-1 ; i++)
	{
		k = i;
		for(j = i + 1 ; j < size ; j++ ) 
		{
			if(cmp(data + k * width , data + j * width)>=0) k = j;
		}
		if(k!=i)
		{
			memcpy(tmp ,data+i*width , width);
			memcpy(data+i*width ,data+k * width,width);
			memcpy(data + k *width , tmp , width);
		}
	}
}


int cmp(const void * a , const void * b)
{
	const float * pa = a , * pb = b;
	if(*pa < *pb) return 1;
	if(*pa > *pb) return -1;
}
