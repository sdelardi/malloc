/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 08:59:53 by sdelardi          #+#    #+#             */
/*   Updated: 2017/03/02 18:29:13 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int		main(void)
{
	char 	*ptr1;
	char 	*ptr2;
	char 	*ptr3;
	char 	*ptr4;
	char 	*ptr5;
	char 	*ptr6;
	int		i;

	/*g_n = getpagesize() / 16;
	g_nn = getpagesize() * 7;
	g_m = getpagesize() / 2;
	g_mm = getpagesize() * 51;*/

	i = 0;
	ptr1 = (char *)ft_malloc(sizeof(char) * 5001);
	while (i < 5000)
	{
		ptr1[i] = 'x';
		i++;
	}
	ptr1[i] = '\0';
	i = 0;
	ptr2 = (char *)ft_malloc(sizeof(char) * 5501);
	while (i < 5500)
	{
		ptr2[i] = 'c';
		i++;
	}
	ptr2[i] = '\0';
	i = 0;
	ptr3 = (char *)ft_malloc(sizeof(char) * 5001);
	while (i < 5000)
	{
		ptr3[i] = 'v';
		i++;
	}
	ptr3[i] = '\0';
	ptr4 = (char *)ft_malloc(sizeof(char) * 15);
	ptr5 = (char *)ft_malloc(sizeof(char) * 100);
	ptr6 = (char *)ft_malloc(sizeof(char) * 2000);
	ft_show_alloc_mem();
	ft_free(ptr1);
	ptr2 = ft_realloc(ptr2, 5700);
	ft_show_alloc_mem();
	if (g_a.ltail && !g_a.ltail->next)
	{
		munmap(g_a.ltail, sizeof(t_large));
		return (0);
	}
	else if (!(g_a.ltail))
		return (0);
	else
	{
		while(g_a.ltail)
		{
			if (g_a.ltail->next == NULL)
			{
				munmap(g_a.ltail, sizeof(t_large));
				return (0);
			}
			else
			{
				g_a.ltail = g_a.ltail->next;
				munmap(g_a.ltail->prev, sizeof(t_large));
			}
		}
	}
	return (0);
}
