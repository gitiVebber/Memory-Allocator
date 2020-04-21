#include <stdio.h>
#include "MemoryAlloc.h"
#define SIZEOS sizeof(size_t)
int main() {
	/*int memory[100], i;
	for (i = 0; i<100; i++)
	memory[i] = 0;
	MemoryAllocator * m = MemoryAllocator_init(memory, 100);
	MemoryAllocator_allocate(m, 20);
	for(i=0; i<100; i++)
	printf("%d ", memory[i]);
	printf("\n");
	MemoryAllocator_allocate(m, 20);
	for(i=0; i<100; i++)
	printf("%d ", memory[i]);
	MemoryAllocator_free(m, &memory[4]);
	printf("\n");
	for(i=0; i<100; i++)
	printf("%d ", memory[i]);*/
	int size = 100;
	void * memory = calloc(sizeof(void*)*size, size);
	MemoryAllocator * m = MemoryAllocator_init(memory, size);
	void * temp1 = memory;
	int i;
	for (i = 0; i<getSize(m) / SIZEOS; i++)
	{
		printf("%d ", *((char*)temp1));
		temp1 += sizeof(size_t);
	}
	MemoryAllocator_allocate(m, 8);
	printf("\n");
	void * temp = memory;
	for (i = 0; i<getSize(m) / SIZEOS; i++)
	{
		printf("%d ", *((char*)temp));
		temp += sizeof(size_t);
	}
	MemoryAllocator_allocate(m, 20);
	printf("\n");
	temp = memory;
	for (i = 0; i<getSize(m) / SIZEOS; i++)
	{
		printf("%d ", *((char*)temp));
		temp += sizeof(size_t);
	}
	printf("\n%d \n", MemoryAllocator_free(m, &memory[0]));
	void * temp2 = memory;
	for (i = 0; i<getSize(m) / SIZEOS; i++)
	{
		printf("%d ", *((char*)temp2));
		temp2 += sizeof(size_t);
	}
	/*
	MemoryAllocator_allocate(m,20);
	printf("\n");
	temp = memory;
	for(i = 0; i<getSize(m)/SIZEOS; i++)
	{
	printf("%d ", *((char*)temp));
	temp += sizeof(size_t);
	}
	printf("\n%d \n", MemoryAllocator_free(m, &memory[0]));
	temp = memory;
	for(i = 0; i<getSize(m)/SIZEOS; i++)
	{
	printf("%d ", *((char*)temp));
	temp += sizeof(size_t);
	}
	*/


	/* printf("\n %d" ,MemoryAllocator_optimize(m));*/
	return 0;
}