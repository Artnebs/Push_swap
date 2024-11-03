#include <stddef.h>

char *ft_strchr(const char *s, int c)
{
    int i = 0;


    while (s[i] != '\0')
    {
        if (s[i] == (char)c)  
            return (char *)&s[i];  // Retourner un pointeur vers l'occurrence trouvée
        i++;
    }

    
    if (c == '\0')
        return (char *)&s[i];

    return NULL; 
}
