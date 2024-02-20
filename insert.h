#ifndef INSERT_H
#define INSERT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insert(void * data , int size , int width , int(*cmp)(const void * , const void *));

#endif