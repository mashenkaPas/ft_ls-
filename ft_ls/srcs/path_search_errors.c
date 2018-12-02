/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_search_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpas <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 16:09:19 by mpas              #+#    #+#             */
/*   Updated: 2018/10/19 16:09:24 by mpas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_ls.h"

t_node	*path_search_errors(t_node *path)
{
	t_node	*root;
	char	*str;

	path = node_sort_by_name(path, 0);
	root = path;
	while (path)
	{
		str = delete_slash(path->name);
		if (stat(path->name, &path->buf) && stat(str, &path->buf) && \
					lstat(path->name, &path->buf))
			b_printf("b_ls: %s: No such file or directory\n", path->name);
		if (stat(path->name, &path->buf) && !stat(str, &path->buf) && \
					lstat(path->name, &path->buf))
			b_printf("b_ls: %s: Not a directory\n", path->name);
		free(str);
		path = path->next;
	}
	ft_list_clean(&path);
	return (root);
}
