/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 08:59:53 by sdelardi          #+#    #+#             */
/*   Updated: 2016/11/15 13:58:51 by sdelardi         ###   ########.fr       */
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

static void show_alloc_t(t_tiny *zone, size_t size)
{
	t_alloc *start;

	start = g_a.atail;
	while (start)
	{
		if (start->data >= zone->data && start->data <= zone->data + size)
		{
			printf("%p", start->data);
			printf(" - %p", start->data + start->size);
			printf(" : %zu octets\n", start->size);
		}
		start = start->next;
	}
}

static void show_alloc_s(t_small *zone, size_t size)
{
	t_alloc *start;

	start = g_a.atail;
	while (start)
	{
		if (start->data >= zone->data && start->data <= zone->data + size)
		{
			printf("%p", start->data);
			printf(" - %p", start->data + start->size);
			printf(" : %zu octets\n", start->size);
		}
		start = start->next;
	}
}

static void	ft_show_alloc_mem(void)
{
	t_large *start;
	t_tiny	*tiny;
	t_small *small;

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
	tiny = g_a.ttail;
	while (tiny)
	{
		printf("TINY : %p\n", tiny);
		show_alloc_t(tiny, tiny->size);
		tiny = tiny->next;
	}
	small = g_a.stail;
	while (small)
	{
		printf("SMALL : %p\n", small);
		show_alloc_s(small, small->size);
		small = small->next;
	}
}

int			main(void)
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
