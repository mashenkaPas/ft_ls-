/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_apply_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpas <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 16:08:43 by mpas              #+#    #+#             */
/*   Updated: 2018/10/19 17:55:00 by mpas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_ls.h"

t_node	*path_apply_flag(t_node *path)
{
	int		rev;

	rev = 0;
	if (g_flag_r == 1)
		rev = 1;
	path = node_sort_by_name(path, rev);
	if (g_flag_t == 1 && g_flag_sc == 0)
		path = node_sort_by_time(path, rev);
	if (g_flag_sc == 1)
		path = node_sort_by_size(path, rev);
	return (path);
}
