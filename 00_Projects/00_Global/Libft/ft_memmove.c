#include <stddef.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t i;
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    if (d == s)
        return dest;

    if (d < s)  // Copier de l'avant vers l'arrière si pas de chevauchement
    {
        i = 0;
        while (i < n)
        {
            d[i] = s[i];
            i++;
        }
    }
    else  // Copier de l'arrière vers l'avant en cas de chevauchement
    {
        i = n;
        while (i > 0)
        {
            i--;
            d[i] = s[i];
        }
    }

    return dest;
}
