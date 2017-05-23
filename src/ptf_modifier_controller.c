/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_modifier_controller.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:53:31 by sdelardi          #+#    #+#             */
/*   Updated: 2015/12/11 16:11:25 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int	modifier_precedence(char *modifier)
{
	if (ft_strcmp(modifier, "ll") == 0)
		return (4);
	else if (ft_strcmp(modifier, "l") == 0 || ft_strcmp(modifier, "j") == 0
			|| ft_strcmp(modifier, "z") == 0)
		return (3);
	else if (ft_strcmp(modifier, "h") == 0)
		return (2);
	else
		return (1);
}

void		ptf_modifier_controller(t_printf *ptr, char *modif)
{
	int ptr_mod;
	int new_mod;

	if (ptr->modifier == NULL)
		ptr->modifier = ft_strdup(modif);
	ptr_mod = modifier_precedence(ptr->modifier);
	new_mod = modifier_precedence(modif);
	if (new_mod > ptr_mod)
	{
		ft_strdel(&ptr->modifier);
		ptr->modifier = ft_strdup(modif);
	}
	ft_strdel(&modif);
}
