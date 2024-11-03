#include <stdlib.h>

void *ft_calloc(size_t count, size_t size)
{
    size_t total_size = count * size;
    unsigned char *ptr;
    size_t i = 0;

    ptr = (unsigned char*)malloc(total_size);
    if (!ptr)
        return NULL;
    while (i < total_size)
    {
        ptr[i] = 0;
        i++;
    }
    return (void *)ptr;
}