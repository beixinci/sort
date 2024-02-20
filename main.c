#include<stdio.h>
#include "bubble.h"
#include "select.h"
#include "quick.h"
#include "insert.h"
#include "randnum.h"

int main(int argc , char ** argv)
{
    if(atoi(argv[2]) == 0)
    {
    int *p = radnnum(atoi(argv[1]),atoi(argv[2]));

    for(int i =0 ; i < atoi(argv[1]) ;i++)

        printf("%d ",p[i]);
    printf("\n排序后为\n");
    insert(p,atoi(argv[1]),4,cmp);

    for(int i =0 ; i < atoi(argv[1]) ;i++)

        printf("%d ",p[i]);
    printf("\n");

    }



    if(atoi(argv[2]) == 1)
    {
    float *p = radnnum(atoi(argv[1]),atoi(argv[2]));
    for(int i =0 ; i < atoi(argv[1]) ;i++)

        printf("%g ",p[i]);
    printf("\n排序后为\n");

    insert(p,atoi(argv[1]),sizeof(float),cmp1);
    
    for(int i =0 ; i < atoi(argv[1]) ;i++)
        printf("%g ",p[i]);
    printf("\n");
    }
    




    return 0;
}