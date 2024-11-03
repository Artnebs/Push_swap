#include <stdlib.h>
#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *))
{
    t_list *new_list = NULL;
    t_list *new_elem;


    while (lst != NULL)
    {

        new_elem = ft_lstnew(f(lst->content));
        if (new_elem == NULL)
        {
            
            while (new_list != NULL)
            {
                t_list *temp = new_list->next;
                free(new_list->content); 
                free(new_list);          
                new_list = temp;
            }
            return NULL;
        }

        
        ft_lstadd_back(&new_list, new_elem);

       
        lst = lst->next;
    }
    return new_list;
}
