#include "select.h"

void select1(void * data , int size ,int width ,int(*cmp1)(const void * ,const void *))
{
    int i , j ,k ;
    void * tmp = malloc(width);

    for(i = 0 ; i < size - 1 ; i++)
    {
        k = i;
        for(j = i+1 ; j < size ;j++)
        {
            if(cmp1(data + k* width ,data + j *width) >= 0) k = j;
        }
        if(i != k)
        {
                memcpy(tmp , data + i *width, width);
                memcpy(data + i *width,data + k*width, width);
                memcpy(data + k*width , tmp , width);
        }
    }
}



int cmp1(const void * a ,const void * b)
{
    const float *pa = a ,*pb =b;
    if(*pa < *pb) return 1;
    if(*pa > *pb) return -1;

}

