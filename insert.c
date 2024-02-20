#include "insert.h"
void insert(void * data , int size , int width , int(*cmp)(const void * , const void *))
{
    int i , j ;
    void * k = malloc(width);


    for(i = 0 ; i < size ;i++)
    {
        if(cmp(data +i *width ,data +(i-1)*width)<0)
        {
            memcpy(k ,data + i * width ,width);
            for(j = i -1 ;j>=0 &&cmp(k,data+j*width)<0;j--)
                memcpy(data+(j+1)*width,data+j*width,width);
            memcpy(data+(j+1)*width,k,width);

        }

    }


}