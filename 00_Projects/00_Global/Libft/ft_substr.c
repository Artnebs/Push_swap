#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t i = 0;
    size_t s_len = 0;
    char *sub;
    
    while(s[s_len])
        s_len++;
    if (start >= s_len)
    {
        sub = malloc(1);
        if (sub)
            sub[0] = '\0';
        return sub;
    }
    if(len > s_len - start)
        len = s_len - start;
    sub = malloc((len + 1) * sizeof(char));
    if (!sub)
        return NULL;
    while (i < len && s[start + i])
    {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = '\0';
    return sub;
}