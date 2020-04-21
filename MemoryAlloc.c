#include "MemoryAlloc.h"
#include <stdlib.h>

typedef struct MemoryAllocator
{
	void * currentPlace;
	size_t size;
	size_t current_size;
};

MemoryAllocator* MemoryAllocator_init(void* memoryPool, size_t size)
{
	MemoryAllocator * m = malloc(sizeof(MemoryAllocator));
	m->currentPlace = memoryPool;
	m->size = size - (size % sizeof(size_t));
	m->current_size = m->size;
	*((char*)m->currentPlace) = m->size;
	return m;
}

void* MemoryAllocator_allocate(MemoryAllocator* allocator, size_t size)
{
	void * temp = allocator->currentPlace;
	if (size % sizeof(size_t) != 0)
	{
		size = size + (sizeof(size_t) - size % sizeof(size_t));
	}

	size_t jump = 0;
	while (jump <= allocator->size)
	{
		if (*((char*)temp) % sizeof(size_t) == 0 && *(char*)temp >= size)
		{
			*(char*)temp = size + 1;
			jump = size + sizeof(size_t);
			temp += jump;
			*(char*)temp = allocator->current_size - size;
			allocator->current_size -= size;
			return temp;
		}
		else
		{
			jump = (*(char*)temp - 1) + (sizeof(size_t));
			temp += jump;
		}
	}
	return NULL;
}

/* Return number of still allocated blocks */
size_t MemoryAllocator_free(MemoryAllocator* allocator, void* ptr)
{
	--*((char*)ptr);
	allocator->current_size += *((char*)ptr);
	size_t j = *((char*)ptr);
	void * temp = ptr + (*(char*)ptr) + (sizeof(size_t));
	//size_t jump = (*(char*)ptr) - (sizeof(size_t));
	//temp += jump;
	if (*((char*)temp) % sizeof(size_t) == 0)
	{
		*((char*)ptr) = *((char*)ptr) + *((char*)temp);
		*((char*)temp) = 0;
	}
	return allocator->current_size;
}

/* Return the size of largest free block */
size_t MemoryAllocator_optimize(MemoryAllocator* allocator)
{
	size_t max = 0;
	void * temp = allocator->currentPlace;
	size_t jump = 0;
	while (jump <= allocator->size)
	{
		if ((*((char*)temp) && *((char*)temp) % sizeof(size_t) == 0) && *((char*)temp)>max)
		{
			max = *((char*)temp);

			jump = (*(char*)temp) - (sizeof(size_t));
			temp += jump;
		}
		else {
			jump = (*(char *)temp - 1) - (sizeof(size_t));
			temp += jump;
		}

	}
	return max;
}
size_t getSize(MemoryAllocator * m)
{
	return m->size;
}