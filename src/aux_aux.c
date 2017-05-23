/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 09:35:33 by sdelardi          #+#    #+#             */
/*   Updated: 2017/05/23 09:40:26 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	aux_sort(t_sort **sort)
{
	t_sort	*new;

	new = *sort;
	if (g_a.sohead == NULL)
	{
		new->prev = NULL;
		g_a.sohead = new;
		g_a.sotail = new;
	}
	else
	{
		new->prev = g_a.sohead;
		g_a.sohead->next = new;
		g_a.sohead = g_a.sohead->next;
	}
}
