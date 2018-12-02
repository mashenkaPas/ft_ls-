/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpas <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:45:04 by mpas              #+#    #+#             */
/*   Updated: 2018/09/19 17:34:38 by mpas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		b_printf(const char *restrict format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			ft_putchar(format[i]);
			i++;
			count++;
		}
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			count += checker(i, format, args);
		}
		if (format[i] != '\0')
			i++;
	}
	return (count);
}

int		checker(int i, const char *restrict format, va_list args)
{
	char	*string;
	int		counter;

	string = NULL;
	counter = 0;
	counter += checker_s(format[i], args);
	counter += checker_id_or_u(format[i], args);
	counter += checker_p_or_o(format[i], args);
	counter += checker_c(format[i], args);
	if (format[i] == 'x')
	{
		string = ft_itoa_base(va_arg(args, unsigned int), 16);
		ft_putstr(string);
		counter += ft_strlen(string);
	}
	if (format[i] == ' ')
		return (counter);
	return (counter);
}

int		checker_s(char ch, va_list args)
{
	char	*string;
	int		counter;
	char	*str_null;

	string = NULL;
	counter = 0;
	str_null = "(null)";
	if (ch == 's')
	{
		string = va_arg(args, char *);
		if (string != NULL)
		{
			ft_putstr(string);
			counter = ft_strlen(string);
		}
		else
		{
			ft_putstr(str_null);
			counter += 6;
		}
	}
	return (counter);
}

int		checker_id_or_u(char ch, va_list args)
{
	char	*string;
	int		counter;

	counter = 0;
	string = NULL;
	if (ch == 'd' || ch == 'i')
	{
		string = ft_itoa_base(va_arg(args, int), 10);
		ft_putstr(string);
		counter = ft_strlen(string);
	}
	if (ch == 'u')
	{
		string = ft_itoa_base(va_arg(args, unsigned int), 10);
		ft_putstr(string);
		counter = ft_strlen(string);
	}
	return (counter);
}

int		checker_p_or_o(char ch, va_list args)
{
	char	*string;
	int		counter;

	counter = 0;
	string = NULL;
	if (ch == 'p')
	{
		string = ft_itoa_base(va_arg(args, unsigned long long), 16);
		ft_putstr("0x");
		ft_putstr(string);
		counter = ft_strlen(string) + 2;
	}
	if (ch == 'o')
	{
		string = ft_itoa_base(va_arg(args, unsigned int), 8);
		ft_putstr(string);
		counter = ft_strlen(string);
	}
	return (counter);
}
