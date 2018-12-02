/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpas <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 15:43:56 by mpas              #+#    #+#             */
/*   Updated: 2018/12/01 18:13:54 by mpas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_ls.h"

static t_node			*reading_dir(t_node *path,\
		DIR *dir, t_node *dir_list)
{
	struct stat			buf;
	struct dirent		*sd;
	char				*linkname;
	char				*tmp;

	while ((sd = readdir(dir)))
	{
		linkname = NULL;
		lstat(path->name, &buf);
		if ((buf.st_mode & S_IFLNK) != S_IFLNK || ((buf.st_mode & S_IFLNK) ==\
					S_IFLNK && g_flag_l == 0))
		{
			tmp = ft_strjoin(path->name, "/");
			tmp = ft_update(tmp, ft_strjoin(tmp, sd->d_name));
			lstat(tmp, &buf);
			if (g_flag_a == 1 || sd->d_name[0] != '.')
				dir_list = node_add(dir_list, sd->d_name, buf);
			free(tmp);
		}
	}
	return (dir_list);
}

t_node					*only_dirs_fill(t_node *path, t_node *list)
{
	char	*tmp;
	t_node	*dir_list;

	dir_list = NULL;
	while (list)
	{
		if ((list->buf.st_mode & S_IFDIR) == S_IFDIR)
		{
			tmp = ft_strjoin(path->name, "/");
			tmp = ft_update(tmp, ft_strjoin(tmp, list->name));
			if (ft_strcmp(list->name, ".") && ft_strcmp(list->name, ".."))
				dir_list = node_add(dir_list, tmp, list->buf);
			free(tmp);
		}
		list = list->next;
	}
	return (dir_list);
}

void					count_dirs(t_node *path, DIR *dir, int rec)
{
	t_node *dir_list;
	t_node *only_dirs;

	dir_list = NULL;
	dir_list = reading_dir(path, dir, dir_list);
	only_dirs = only_dirs_fill(path, dir_list);
	d_entity(path, dir_list);
	if (g_flag_recursion == 1)
		d_dirs(fl_apply(only_dirs), ++rec);
	ft_list_clean(&dir_list);
	ft_list_clean(&only_dirs);
}

void					d_dirs(t_node *path, int rec)
{
	DIR					*dir;
	int					cnt_dirs;
	struct stat			buf;

	g_entity_fill = 0;
	cnt_dirs = node_size(path);
	while (path)
	{
		dir = opendir(path->name);
		if ((cnt_dirs > 0 && ((path->buf.st_mode & S_IFDIR) == S_IFDIR ||\
			((path->buf.st_mode & S_IFLNK) == S_IFLNK && g_flag_l == 0))
			&& dir) || rec > 0)
			b_printf("\n") && b_printf("%s:\n", path->name);
		if (!dir && !stat(path->name, &buf) && ((path->buf.st_mode & S_IFDIR)
			== S_IFDIR || (((path->buf.st_mode & S_IFLNK) == S_IFLNK &&
					g_flag_l == 0))) &&
				(path->buf.st_mode & S_IFBLK) != S_IFBLK)
			b_printf("b_ls: %s: %s\n", path->name, strerror(errno));
		if (dir && ((path->buf.st_mode & S_IFDIR) == S_IFDIR ||
			((path->buf.st_mode & S_IFLNK) == S_IFLNK && g_flag_l == 0)))
			count_dirs(path, dir, rec);
		if (dir)
			closedir(dir);
		path = path->next;
	}
}
