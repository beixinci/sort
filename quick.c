#include "quick.h"


void quick(void * data , int size ,int width ,int(*cmp)(const void* ,const void *))
{
    int i =0 , j = size -1 ;
    void * k = malloc(width);
    if(size < 2) return ;

    memcpy(k,data,width);

    while(i<j)
    {
        while(i<j && cmp(data + j *width , k)>=0) j--;
            memcpy(data+i*width,data+j*width,width);
        while(i<j && cmp(data + i *width , k)<=0) i++;
            memcpy(data+j*width ,data + i*width,width);
    }
    memcpy(data+i*width,k,width);

    quick(data,i,width,cmp);
    quick(data+(i+1)*width,size -i-1 ,width, cmp);
}
