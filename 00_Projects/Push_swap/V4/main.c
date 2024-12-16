#include "push_swap.h"

static int	is_empty(int ac)
{
	if(ac<2)return(1);
	return(0);
}

int	main(int ac,char **av)
{
	int *arr;int total;int i;
	t_stack *a; t_stack *b;
	if(is_empty(ac))return(0);
	arr=parse_arguments(ac,av,&total);
	if(!arr)return(1);
	arr=rank_array(arr,total);
	if(!arr){ft_putstr_fd("Error\n",2);return(1);}
	a=init_stack();
	if(!a){free(arr);ft_putstr_fd("Error\n",2);return(1);}
	i=0;while(i<total){if(!push_bottom(a,arr[i])){free(arr);free_stack(a);ft_putstr_fd("Error\n",2);return(1);}i++;}
	free(arr);
	if(is_sorted(a)){free_stack(a);return(0);}
	b=init_stack();
	if(!b){free_stack(a);ft_putstr_fd("Error\n",2);return(1);}
	push_swap(a,b);
	free_stack(a);free_stack(b);
	return(0);
}
