int ft_atoi(const char *str)
{
    int i = 0;
    int result = 0;
    int signe = 1;

    while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            signe *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * signe);
}