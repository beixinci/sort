#ifndef SELECT_H
#define SELECT_H



#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void select1(void * data , int size ,int width ,int(*cmp)(const void * ,const void *));
int cmp1(const void * a ,const void * b);


#endif