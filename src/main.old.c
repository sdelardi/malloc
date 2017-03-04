/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 08:59:53 by sdelardi          #+#    #+#             */
/*   Updated: 2017/03/04 16:53:40 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	show_alloc_t(t_tiny *zone, size_t size)
{
	t_alloc *start;

	sort_tiny();
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

static void    malloc_malloc(void)
{
	char    *str;
	char    *str2;
	char    *str3;
	char    *str4;
	char    *str5;
	char    *str6;
	char    *str7;
	char    *str8;

	printf("malloc str de 16 octets\n");
	str = (char*)ft_malloc(sizeof(char) * 16);
	printf("malloc str2 de 1257 octets\n");
	str2 = (char*)ft_malloc(sizeof(char) * 1257);
	printf("malloc str3 de 327 octets\n");
	str3 = (char*)ft_malloc(sizeof(char) * 327);
	printf("malloc str4 de 42 octets\n");
	str4 = (char*)ft_malloc(sizeof(char) * 42);
	printf("malloc str5 de 1 octet\n");
	str5 = (char*)ft_malloc(sizeof(char) * 1);
	printf("malloc str6 de 4055 octet\n");
	str6 = (char*)ft_malloc(sizeof(char) * 4055);
	printf("malloc str7 de 0 octet\n");
	str7 = (char*)ft_malloc(sizeof(char) * 0);
	printf("malloc str8 de -2 octet\n\n");
	str8 = (char*)ft_malloc(sizeof(char) * -2);

	int i = 0;
	char *tab[1024];
	while(i < 1024)
	{
		tab[i] = ft_malloc(24);
		i++;
	}
	i= 0;
	while(i < 1024)
	{
		ft_free(tab[i]);
		i++;
	}
	printf("Allocated memory:\n");
	ft_show_alloc_mem();
}

void	show_alloc_s(t_small *zone, size_t size)
{
	t_alloc *start;

	sort_small();
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

void	ft_show_alloc_mem(void)
{
	t_large *start;
	t_tiny	*tiny;
	t_small *small;

	sort_large();
	sort_alloc();
	start = g_a.ltail;
	while (start)
	{
		printf("LARGE : %p\n", start);
		printf("%p", start->data);
		printf(" - %p", start->data + start->size);
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
	malloc_malloc();
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
