#include <stddef.h>

void *ft_memset(void *s, int c, size_t n)
{
    size_t i = 0;
    unsigned char *ptr = (unsigned char *)s;

    while (i < n)
    {
        ptr[i] = (unsigned char)c;
        i++;
    }
    return s;
}