#ifndef BUBBLE_H
#define BUBBLE_H



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void bubble(void * data , int size , int width ,int(*cmp)(const void *,const void *));
int cmp(const void *a , const void *b);



#endif