/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpas <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:29:26 by mpas              #+#    #+#             */
/*   Updated: 2018/09/18 20:42:51 by mpas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*itoa_base_helper(char *tab, long long value, int base, int sign)
{
	unsigned long long	tmp;
	int					size;
	char				*str;

	size = 0;
	tmp = (unsigned long long)value;
	while (tmp /= base)
		size++;
	size = size + sign + 1;
	str = (char *)malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	if (sign == 1)
		str[0] = '-';
	while (size > sign)
	{
		str[size - 1] = tab[(value % base)];
		size--;
		value = value / base;
	}
	return (str);
}

char	*ft_itoa_base(long long value, int base)
{
	char	*str;
	char	*basetab;
	int		sign;

	sign = 0;
	basetab = "0123456789abcdef";
	if (value < 0 && base == 10)
		sign = 1;
	value = (value < 0) ? -value : value;
	str = itoa_base_helper(basetab, value, base, sign);
	return (str);
}
