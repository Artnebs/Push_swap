void ft_bzero(void *s, int n)
{
    int i = 0;
    unsigned char *ptr = (unsigned char *)s;

    while (i < n)
    {
        ptr[i] = 0;
        i++;
    }
}