#include <stdlib.h>

static int count_digits(int n)
{
    int count = (n <= 0) ? 1 : 0;
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

char *ft_itoa(int n)
{
    int len = count_digits(n);
    int sign = (n < 0) ? -1 : 1;
    char *str = (char *)malloc((len + 1) * sizeof(char));
    if (!str)
        return NULL;

    str[len] = '\0';
    while (len > 0)
    {
        len--;
        str[len] = '0' + sign * (n % 10);
        n /= 10;
    }

    if (sign == -1)
        str[0] = '-';

    return str;
}
