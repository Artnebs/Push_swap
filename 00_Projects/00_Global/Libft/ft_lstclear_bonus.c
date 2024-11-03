#include <stdlib.h>
#include "libft.h"

void ft_lstclear(t_list **lst)
{
    t_list *temp;

    if (lst == NULL)
        return ;

    while (*lst != NULL)
    {
        temp = (*lst)->next;
        free((*lst)->content);
        free(*lst);
        *lst = temp;
    }
    *lst = NULL;
}