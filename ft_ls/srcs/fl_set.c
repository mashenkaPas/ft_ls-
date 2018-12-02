/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpas <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 16:05:36 by mpas              #+#    #+#             */
/*   Updated: 2018/12/01 17:45:32 by mpas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_ls.h"

void	illegalfn(char *str)
{
	g_flag_illegal = 1;
	b_printf("b_ls: illegal option -- %s\n", str);
	b_printf("usage: ./b_ls [GSTaglrt] [file ...]\n");
}

void	help_me(void)
{
	g_flag_g = 1;
	g_flag_l = 1;
}

void	fl_set(char *str)
{
	while (*str != '\0' && g_flag_illegal == 0)
	{
		if (*str == 'l')
			g_flag_l = 1;
		else if (*str == 'a')
			g_flag_a = 1;
		else if (*str == 't')
			g_flag_t = 1;
		else if (*str == 'r')
			g_flag_r = 1;
		else if (*str == 'g')
			help_me();
		else if (*str == 'S')
			g_flag_sc = 1;
		else if (*str == 'T')
			g_flag_tc = 1;
		else if (*str == 'G')
			g_flag_gc = 1;
		else if (*str == 'R')
			g_flag_recursion = 1;
		else
			illegalfn(str);
		str++;
	}
}
