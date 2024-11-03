#include <stdlib.h>

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t i = 0;
    size_t j = 0;
    size_t len1 = 0;
    size_t len2 = 0;
    char *result;

    while (s1[len1])
        len1++;
    while (s2[len2])
        len2++;
    result = malloc(sizeof(char) * (len1 + len2 + 1));
    if (!result)
        return NULL;
    while (i < len1)
    {
        result[i] = s1[i];
        i++;
    }
    while (j < len2)
    {
        result[i + j] = s2[j];
        j++;
    }
    result[i + j] = '\0';
    return result;
}