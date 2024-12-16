/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:37:18 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/16 20:37:19 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // for debug prints

static int	is_valid_integer(const char *str)
{
	int i;
	long num;
	int sign;

	if (!str || !*str)
		return (0);
	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	num = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > 2147483647L) || (sign == -1 && -num < -2147483648L))
			return (0);
		i++;
	}
	if (str[i])
		return (0);
	return (1);
}

static int	has_duplicates(int *arr,int size)
{
	int i;int j;
	i=0;while(i<size)
	{
		j=i+1;while(j<size)
		{
			if(arr[i]==arr[j])return(1);
			j++;
		}
		i++;
	}
	return(0);
}

static int	count_numbers_in_args(int ac,char **av)
{
	int i;int total;char**vals;int k;
	total=0;i=1;
	while(i<ac)
	{
		vals=ft_split(av[i],' ');
		if(!vals)
		{
			fprintf(stderr, "DEBUG: ft_split returned NULL for av[%d]: '%s'\n", i, av[i]);
			return(-1);
		}
		k=0;while(vals[k])k++;
		total+=k;
		ft_free_split(vals);
		i++;
	}
	return(total);
}

static int	fill_int_array(int ac,char **av,int*arr)
{
	int i;int idx;char**vals;int k;
	idx=0;i=1;
	while(i<ac)
	{
		vals=ft_split(av[i],' ');
		if(!vals)
		{
			fprintf(stderr, "DEBUG: ft_split returned NULL in fill_int_array for av[%d]: '%s'\n", i, av[i]);
			return(0);
		}
		k=0;while(vals[k])
		{
			if(!is_valid_integer(vals[k]))
			{
				fprintf(stderr, "DEBUG: is_valid_integer failed for '%s'\n", vals[k]);
				ft_free_split(vals);return(0);
			}
			arr[idx++]=ft_atoi(vals[k]);
			k++;
		}
		ft_free_split(vals);
		i++;
	}
	return(1);
}

int *parse_arguments(int ac,char **av,int *count)
{
	int total;int *arr;
	total=count_numbers_in_args(ac,av);
	if(total<=0)
	{
		if(total==-1)
		{
			ft_putstr_fd("Error\n",2);
			fprintf(stderr, "DEBUG: count_numbers_in_args returned -1, likely ft_split failed\n");
		}
		return(NULL);
	}
	arr=(int*)malloc(sizeof(int)*total);
	if(!arr)
	{
		ft_putstr_fd("Error\n",2);
		fprintf(stderr, "DEBUG: malloc failed for arr\n");
		return(NULL);
	}
	if(!fill_int_array(ac,av,arr))
	{
		free(arr);ft_putstr_fd("Error\n",2);
		fprintf(stderr, "DEBUG: fill_int_array returned 0, either ft_split failed or is_valid_integer failed\n");
		return(NULL);
	}
	if(has_duplicates(arr,total))
	{
		free(arr);ft_putstr_fd("Error\n",2);
		fprintf(stderr, "DEBUG: has_duplicates returned 1\n");
		return(NULL);
	}
	*count=total;
	return(arr);
}
