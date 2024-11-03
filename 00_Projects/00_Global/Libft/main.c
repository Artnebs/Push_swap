#include <stdio.h>

char *ft_strchr(const char *str, int c);


int main(void)
{
    const char *str = "Hello, World!";
    char *result;

    // Rechercher la première occurrence de 'W'
    result = ft_strchr(str, 'W');
    if (result != NULL)
        printf("Found 'W' at position: %ld\n", result - str);
    else
        printf("'W' not found\n");

    // Rechercher la première occurrence de 'z'
    result = ft_strchr(str, 'z');
    if (result != NULL)
        printf("Found 'z' at position: %ld\n", result - str);
    else
        printf("'z' not found\n");

    // Rechercher la fin de chaîne avec '\0'
    result = ft_strchr(str, '\0');
    printf("End of string is at position: %ld\n", result - str);

    return 0;
}
