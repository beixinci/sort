#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define N 10

int cmp(const void * a ,const void * b);
void quick(void *data ,int size , int width , int(* cmp)(const void * ,const void * ));
int main()
{
	int i , j , k , num[N];
	
	srand(time(NULL));

	for(i =0 ; i< N ;i++)
	{
		k = rand() % 100;
		for(j = 0 ; j < i ;j++)
		{
			if(num[j] == k) break;
		}
		if(i == j) num[i] = k;
		else i--;
	}

	printf("1\n");
	quick(num,N,sizeof(int),cmp);

	for(i = 0 ; i < N ; i++)
		printf("%d ", num[i]);
	printf("\n");
	
	return 0;
}

void quick(void *data ,int size , int width , int(* cmp)(const void * ,const void * ))
{
	int i = 0 , j = size - 1  ;
	void * k = malloc(width);
	memcpy(k , data,width);
	if(size < 2 ) return ;

	while(i< j)
	{
		while(i< j && cmp(data + j * width ,k)>= 0) j--;
			memcpy(data + i * width ,data + j * width , width);

		while(i< j && cmp(data + i * width ,k)<= 0) i++;
			memcpy(data + j * width ,data + i * width , width);
	}
	memcpy(data + i * width , k,width);
	quick(data , i, width , cmp);
	quick(data + (i + 1)*width , size - i - 1 , width , cmp);
}



int cmp(const void * a ,const void * b)
{
	const int * pa = a , * pb = b ;
	return * pa - *pb;
}
