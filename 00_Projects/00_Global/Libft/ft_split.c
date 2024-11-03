#include <stdlib.h>
#include <unistd.h>

static int count_words(const char *s, char c)
{
    int count = 0;
    int in_word = 0;

    while (*s)
    {
        if (*s != c && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (*s == c)
            in_word = 0;
        s++;
    }
    return count; 
}

static char *allocate_word(const char *start, const char *end)
{
    int i = 0;
    int len = end - start; 
    char *word = malloc(len + 1);
    if (!word)
        return NULL;
    while (i < len)
    {
        word[i] = start[i];
        i++;
    }
    word[len] = '\0';
    return word;
}

char **ft_split(char const *s, char c)
{
    if (!s)
        return NULL;
    
    int word_count = count_words(s, c);
    char **result = malloc(sizeof(char *) * (word_count + 1));
    int i = 0;

    if (!result)
        return NULL;

    while (*s)
    {
        if (*s != c)
        {
            const char *start = s;
            while (*s && *s != c)
                s++;
            result[i] = allocate_word(start, s);
            if (!result[i])
            {
                while (i > 0)
                {
                    free(result[--i]);
                }
                free(result);
                return NULL;
            }
            i++;
        }
        else
            s++;
    }
    result[i] = NULL; 
    return result;
}