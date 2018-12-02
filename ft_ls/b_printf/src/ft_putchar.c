/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpas <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:15:09 by mpas              #+#    #+#             */
/*   Updated: 2018/09/19 17:29:00 by mpas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		checker_c(char ch, va_list args)
{
	char	character;
	int		counter;

	counter = 0;
	if (ch == 'c')
	{
		character = va_arg(args, int);
		ft_putchar(character);
		counter++;
	}
	return (counter);
}
