#include <stdlib.h>
#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    size_t i = 0;
    char *result;

    if (!s || !f)
        return NULL;
    result = malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (!result)
        return NULL;
    while (s[i])
    {
        result[i] = f(i, s[i]);
        i++;
    }
    result[i] = '\0';
    return result;
}