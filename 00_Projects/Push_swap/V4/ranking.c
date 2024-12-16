/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:43:03 by anebbou           #+#    #+#             */
/*   Updated: 2024/12/16 19:51:49 by anebbou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int*copy_array(int*arr,int size)
{
	int*i2=(int*)malloc(sizeof(int)*size);int x=0;
	if(!i2)return(NULL);
	while(x<size){i2[x]=arr[x];x++;}
	return(i2);
}

static void sort_array(int*arr,int size)
{
	int i;int j;int tmp;
	i=0;while(i<size)
	{
		j=0;while(j<size-1)
		{
			if(arr[j]>arr[j+1])
			{tmp=arr[j];arr[j]=arr[j+1];arr[j+1]=tmp;}
			j++;
		}
		i++;
	}
}

static int get_rank_from_copy(int*copy,int size,int val)
{
	int idx=0;while(idx<size){if(copy[idx]==val)return(idx);idx++;}
	return(0);
}

int*rank_array(int*arr,int size)
{
	int*copy=copy_array(arr,size);int i=0;
	if(!copy)return(NULL);
	sort_array(copy,size);
	while(i<size){arr[i]=get_rank_from_copy(copy,size,arr[i]);i++;}
	free(copy);
	return(arr);
}
