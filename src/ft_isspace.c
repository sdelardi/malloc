/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:43:38 by sdelardi          #+#    #+#             */
/*   Updated: 2015/12/11 15:50:33 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_isspace(int c)
{
	char ch;

	ch = (char)c;
	if (ch == ' ' || ch == '\t' || ch == '\n' ||
			ch == '\v' || ch == '\f' || ch == '\r')
		return (1);
	else
		return (0);
}
