#include <unistd.h>

void ft_putnbr(int n)
{
    char digit;
    

    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
        return ; 
    }
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if (n >= 10)
    {
        ft_putnbr(n / 10);
    }
    digit = (n % 10) + '0';
    write(1, &digit, 1);

}