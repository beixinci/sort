#include "bubble.h"

void bubble(void * data , int size , int width ,int(*cmp)(const void *,const void *))
{
    int i , j ;
    void * k = malloc(width);

    for(i = 0 ; i < size -1 ; i++)
    {
        for(j = 0 ; j < size -i-1 ; j++)
        {
            if(cmp(data + j * width , data +(j + 1 )*width) < 0)
            {
                memcpy(k , data + j *width, width);
                memcpy(data + j *width,data + (j+1)*width, width);
                memcpy(data + (j+1)*width , k , width);
            }

        }
    }
}


int cmp(const void *a , const void *b)
{
    const int * pa = a , *pb = b;
    return *pa - *pb;
}