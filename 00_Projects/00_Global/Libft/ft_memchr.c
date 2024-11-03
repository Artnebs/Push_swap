#include <stddef.h>

void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i = 0;
    unsigned char *ptr = (unsigned char *)s;
    unsigned char uc = (unsigned char)c;

    while (i < n)
    {
        if (ptr[i] == uc)
            return (void *)&ptr[i];
        i++;
    }
    return NULL;
}