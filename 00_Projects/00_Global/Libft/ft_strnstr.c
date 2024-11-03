#include <stddef.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i = 0;
    size_t j;

    if (*needle == '\0')
        return (char *)haystack;
    while (haystack[i] && i < len )
    {
        if (haystack[i] == needle[0])
        {
            j = 0;
            while (needle[j] && haystack[i + j] == needle[j] && (i + j) < len)
                j++;
            if (needle[j] == '\0')
                return (char *)&haystack[i];
        }
        i++;
    }
    return NULL;
}