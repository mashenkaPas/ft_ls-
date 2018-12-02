/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpas <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 16:02:39 by mpas              #+#    #+#             */
/*   Updated: 2018/10/19 17:56:49 by mpas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_ls.h"

t_node	*fl_apply(t_node *node_list)
{
	int		rev;

	rev = 0;
	if (g_flag_r == 1)
		rev = 1;
	node_list = node_sort_by_name(node_list, rev);
	if (g_flag_t == 1 && g_flag_sc == 0)
		node_list = node_sort_by_time(node_list, rev);
	if (g_flag_sc == 1)
		node_list = node_sort_by_size(node_list, rev);
	return (node_list);
}
