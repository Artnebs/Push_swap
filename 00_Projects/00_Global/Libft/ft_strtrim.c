#include <stdlib.h>

static int is_in_set(char c, const char *set)
{
    while (*set)
    {
        if (c == *set)
            return 1;
        set++;
    }
    return 0;
}

char *ft_strtrim(char const *s1, char const *set)
{
    size_t start = 0;
    size_t end;
    char *trimmed;

    if (!s1 || !set)
        return NULL;
    while (s1[start] && is_in_set(s1[start], set))
        start++;
    end = start;
    while (s1[end])
        end++;
    while (end > start && is_in_set(s1[end - 1], set))
        end--;
    trimmed = malloc(sizeof(char) * (end - start + 1));
    if (!trimmed)
        return NULL;
    for (size_t i = 0; start < end; i++, start++)
        trimmed[i] = s1[start];
    trimmed[end - start] = '\0';
    return trimmed;

}