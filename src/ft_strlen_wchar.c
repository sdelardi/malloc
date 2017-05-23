/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:29:57 by sdelardi          #+#    #+#             */
/*   Updated: 2015/12/11 13:31:54 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		count_significant_bit(int value)
{
	int bit;

	bit = 31;
	while (bit >= 0)
	{
		if (value & (1 << bit))
			return (bit + 1);
		bit--;
	}
	return (0);
}

int		count_nb_octet(wchar_t letter)
{
	int nb_bit;

	nb_bit = count_significant_bit(letter);
	if (nb_bit <= 7)
		return (1);
	else if (nb_bit <= 11)
		return (2);
	else if (nb_bit <= 16)
		return (3);
	else
		return (4);
}

int		strlen_wchar(wchar_t *str)
{
	int i;
	int length;
	int nb_bit;

	i = 0;
	length = 0;
	while (str[i])
	{
		nb_bit = count_significant_bit(str[i]);
		if (nb_bit <= 7)
			length += 1;
		else if (nb_bit <= 11)
			length += 2;
		else if (nb_bit <= 16)
			length += 3;
		else
			length += 4;
		i++;
	}
	return (length);
}
