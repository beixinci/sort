#include<stdio.h>

#include<stdlib.h>
#include<string.h>
#include<time.h>
#define N 10
int cmp(const void * a , const void  *b );
void bubble(void * data , int size , int width , int(*cmp)(const void *  , const void * ));

int main()
{
    int i , j , k , num[N];
    srand(time(NULL));

    for(i = 0 ; i < N ; i++)
    {
        k = rand() % 100;
        for(j = 0 ; j < i ; j++)
        {
            if(k == num[j]) break;
        }
        if(i == j) num[i]= k ;
        else i--;
    }

    bubble(num,N,4,cmp);

    for(int i = 0 ; i < N ; i++)
        printf("%d ",num[i]);

    printf("\n");

    return 0;
}


void bubble(void * data , int size , int width , int(*cmp)(const void *  , const void * ))
{
    int i , j;

    void * k = malloc(width);

    for(i = 0 ;i  <  size - 1 ; i++)
    {
        for(j = 0 ; j < size - i - 1 ; j++)
        {
            if(cmp(data + j * width , data + (j+1) * width) >= 0)
            {
                memcpy(k ,data + j * width, width);
                memcpy(data + j * width , data + (j +1)*width , width);
                memcpy(data + (j +1)*width ,k , width);
            }
        }

    }
}

int cmp(const void * a , const void  *b )
{
    const int * pa = a , * pb = b;

    return *pa - * pb;
}



