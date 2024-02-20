#ifndef QUICK_H
#define QUICK_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void quick(void * data , int size ,int width ,int(*cmp)(const void* ,const void *));

#endif