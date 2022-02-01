#ifndef EX1_H
#define EX1_H
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
unsigned int size;
void* p0;

void* aligned_malloc(unsigned int size, unsigned int align);

void* aligned_free(void* ptr);

#endif
