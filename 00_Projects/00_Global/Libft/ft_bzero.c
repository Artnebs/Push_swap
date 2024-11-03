#include <stddef.h>

void ft_bzero(void *s, size_t n)
{
    size_t i = 0;
    unsigned char *ptr = (unsigned char *)s;

    while (i < n)
    {
        ptr[i] = 0;
        i++;
    }
}