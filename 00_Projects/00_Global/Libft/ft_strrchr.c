#include <stddef.h>

char *ft_strrchr(const char *s, int c)
{
    int i = 0;
    char *last_occurrence = NULL;

  
    while (s[i] != '\0')
    {
        if (s[i] == (char)c)
            last_occurrence = (char *)&s[i];  // Mettre à jour la dernière occurrence trouvée
        i++;
    }


    if (c == '\0')
        return (char *)&s[i];

    return last_occurrence;  
}
