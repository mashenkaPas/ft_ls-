/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpas <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 16:11:00 by mpas              #+#    #+#             */
/*   Updated: 2018/11/30 14:41:28 by mpas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes//b_ls.h"

t_node	*parse_args(int argc, char **argv)
{
	int			i;
	int			read;
	t_node		*path;
	struct stat buf;

	i = 0;
	read = 0;
	path = NULL;
	while (++i < argc)
	{
		if (read == 0 && argv[i][0] == '-')
			fl_set(&argv[i][1]);
		if (read || argv[i][0] != '-' || ft_strcmp(argv[i], "-") == 0)
		{
			read = 1;
			lstat(argv[i], &buf);
			path = node_add(path, argv[i], buf);
		}
	}
	if (read == 0)
	{
		lstat(".", &buf);
		path = node_add(path, ".", buf);
	}
	return (path);
}

int		main(int argc, char **argv)
{
	t_node		*path;

	path = parse_args(argc, argv);
	if (g_flag_illegal == 1)
		return (0);
	path = path_search_errors(path);
	path = path_apply_flag(path);
	d_symlink(path);
	d_blocks(path);
	d_files(path);
	d_dirs(path, 0);
	ft_list_clean(&path);
	return (0);
}
