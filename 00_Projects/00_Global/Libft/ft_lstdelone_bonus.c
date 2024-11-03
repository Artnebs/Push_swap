#include <stdlib.h>
#include "libft.h"

void ft_lstdelone(t_list *lst)
{
    if (lst != NULL)
    {
        free(lst->content);
        free(lst);
    }
}