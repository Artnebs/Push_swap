#include <stddef.h>

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t dst_len = 0;
    size_t src_len = 0;
    size_t i = 0;

    while (dst[dst_len] && dst_len < dstsize)
        dst_len++;
    while (src[src_len])
        src_len++;
    if (dstsize <= dst_len)
        return (dstsize + src_len);
    while (src[i] && dst_len + i < dstsize - 1)
    {
        dst[dst_len + i] = src[i];
        i++;
    }
    dst[dst_len + i] = '\0';
    return dst_len + src_len;
}
