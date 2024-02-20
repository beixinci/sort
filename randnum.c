#include "randnum.h"

void* radnnum(int num,int type)
{
    // type 表示需要生成的随机数类型 1表示整数 2表示浮点数 
    //随即数默认范围在【0，10 * num】之间

    srand(time(NULL));

    if(type == 0)
    {
        int  i , j , k ;

        int *p = (int*)malloc(num*sizeof(int));

        for(i = 0 ; i < num ; i++)
        {
            k = rand() % (10 * num);

            for( j = 0 ; j < i ; j++)
            {
                if(k == p[j])  break;
            }
            if(i == j) p[i] = k;
            else i--;
        }

        return p;
    } 

     if(type == 1)
    {
        int  i , j ;
        float  k ;

        float *p = (float*)malloc(num*sizeof(float));

        for(i = 0 ; i < num ; i++)
        {
            k = (float)rand()/RAND_MAX *(10 * num);

            for( j = 0 ; j < i ; j++)
            {
                if(k == p[j])  break;
            }
            if(i == j) p[i] = k;
            else i--;
        }

        return p;
    } 


    
}