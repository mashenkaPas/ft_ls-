/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpas <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 16:03:44 by mpas              #+#    #+#             */
/*   Updated: 2018/11/30 20:52:18 by mpas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_ls.h"

void	fl_init(void)
{
	g_flag_a = 0;
	g_flag_l = 0;
	g_flag_r = 0;
	g_flag_t = 0;
	g_flag_sc = 0;
	g_flag_tc = 0;
	g_flag_gc = 0;
	g_entity_fill = 0;
	g_flag_illegal = 0;
	g_flag_recursion = 0;
}
