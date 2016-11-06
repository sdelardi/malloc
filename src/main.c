/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 08:59:53 by sdelardi          #+#    #+#             */
/*   Updated: 2016/11/06 11:13:33 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void			ft_free(void *ptr)
{
	ptr = NULL;
}

void		*ft_realloc(void *ptrm, size_t size)
{
	ptrm = NULL;
	size = 0;
	return (NULL);
}

static void	ft_show_alloc_mem(void)
{
	t_large *start;

	start = g_a.ltail;
	while (start)
	{
		printf("LARGE : %p\n", start);
		printf("%p", start->data);
		start->data += start->size;
		printf(" - %p", start->data);
		printf(" : %zu octets\n", start->size);
		start = start->next;
	}
}

int			main(void)
{
	char 	*ptr1;
	char 	*ptr2;
	char 	*ptr3;
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
	ft_show_alloc_mem();
	munmap(ptr1, 5001);
	munmap(ptr2, 5501);
	munmap(ptr3, 5001);
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
				munmap(g_a.ltail, sizeof(t_large) + 1);
				return (0);
			}
			else
			{
				g_a.ltail = g_a.ltail->next;
				munmap(g_a.ltail->prev, sizeof(t_large) + 1);
			}
		}
	}
	return (0);
}
