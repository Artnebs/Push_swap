#include <stddef.h>

void *ft_memcpy(void *dest, const void *src, int n)
{
    int i = 0;
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    while (i < n)
    {
        d[i] = s[i];
        i++;
    }
    return dest;
}
