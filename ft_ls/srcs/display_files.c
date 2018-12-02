/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpas <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 15:59:16 by mpas              #+#    #+#             */
/*   Updated: 2018/10/19 17:59:48 by mpas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_ls.h"

void	d_blocks(t_node *path)
{
	t_node		*block_list;
	t_node		*begin_list;

	begin_list = path;
	block_list = NULL;
	while (path)
	{
		if ((path->buf.st_mode & S_IFBLK) == S_IFBLK)
			block_list = node_add(block_list, path->name, path->buf);
		path = path->next;
	}
	ft_list_clean(&path);
	path = begin_list;
	d_entity(path, block_list);
	ft_list_clean(&block_list);
}

void	check_for_links(t_node *path, DIR *dir)
{
	if ((path->buf.st_mode & S_IFLNK) == S_IFLNK && !dir && g_flag_l == 0)
		b_printf("%s\n", path->name);
}

void	d_files(t_node *path)
{
	t_node		*file_list;
	t_node		*begin_list;
	DIR			*dir;

	file_list = NULL;
	begin_list = path;
	g_entity_fill = 1;
	while (path)
	{
		dir = opendir(path->name);
		if ((path->buf.st_mode & S_IFLNK) != S_IFLNK || ((path->buf.st_mode
		& S_IFLNK) == S_IFLNK && path->name[0] == '/' && g_flag_l == 0) ||
	((path->buf.st_mode & S_IFLNK) == S_IFLNK && g_flag_l == 0 && !dir))
			if ((path->buf.st_mode & S_IFDIR) != S_IFDIR &&
					!stat(path->name, &path->buf))
				file_list = node_add(file_list, path->name, path->buf);
		check_for_links(path, dir);
		if (dir)
			closedir(dir);
		path = path->next;
	}
	ft_list_clean(&path);
	path = begin_list;
	d_entity(path, file_list);
	ft_list_clean(&file_list);
}
