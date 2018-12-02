/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_entity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpas <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 15:54:21 by mpas              #+#    #+#             */
/*   Updated: 2018/12/01 18:14:26 by mpas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_ls.h"

void				make_a_chudo(char *str, int k)
{
	int i;

	i = 4;
	while (i < k)
		b_printf("%c", str[i++]);
	b_printf(" ");
}

static void			display_detail(t_node *entity)
{
	b_printf("%s", CWHITE);
	mode_print(entity->buf.st_mode);
	b_printf(" %i ", entity->buf.st_nlink);
	b_printf("%s\t", getpwuid(entity->buf.st_uid)->pw_name);
	b_printf("%s\t", getgrgid(entity->buf.st_gid)->gr_name);
	b_printf("%i\t", (int)entity->buf.st_size);
	if (g_flag_tc == 0)
		make_a_chudo(ctime(&entity->buf.st_mtime), 16);
	else
		make_a_chudo(ctime(&entity->buf.st_mtime), 24);
}

void				option_for_entity(t_node *path, t_node *entity)
{
	char *str;

	if (g_flag_l == 1)
		display_detail(entity);
	if (g_flag_gc == 1)
		print_with_colors(entity);
	else
		b_printf("%s", entity->name);
	str = getting_full_symlink(entity->name, path->name);
	if ((entity->buf.st_mode & S_IFLNK) == S_IFLNK && g_flag_l == 1)
		b_printf("%s%s", CWHITE, str);
	if (ft_strcmp(str, " ") != 0)
		free(str);
	b_printf("%s\n", CWHITE);
}

void				d_entity(t_node *path, t_node *entity)
{
	long long		blocks;

	if (entity == NULL || path == NULL)
		return ;
	blocks = count_blocks(entity);
	entity = fl_apply(entity);
	if ((path->buf.st_mode & S_IFDIR) == S_IFDIR
			&& g_flag_l == 1 && g_entity_fill == 0)
		b_printf("total %i\n", (int)blocks);
	while (entity)
	{
		option_for_entity(path, entity);
		entity = entity->next;
	}
}
