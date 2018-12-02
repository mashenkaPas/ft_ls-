/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_with_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpas <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 16:10:14 by mpas              #+#    #+#             */
/*   Updated: 2018/10/19 16:33:04 by mpas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_ls.h"

void	print_with_colors(t_node *entity)
{
	if ((entity->buf.st_mode & S_IFBLK) == S_IFBLK)
		b_printf("%s%s%s%s%s", CBLUE, BBLUE, entity->name, BBLACK, CWHITE);
	else if ((entity->buf.st_mode & S_IFLNK) == S_IFLNK)
		b_printf("%s%s", CPINK, entity->name);
	else if ((entity->buf.st_mode & S_IXUSR) == S_IXUSR)
		b_printf("%s%s", CRED, entity->name);
	else if ((entity->buf.st_mode & S_IFDIR) == S_IFDIR)
		b_printf("%s%s", CBLUE, entity->name);
	else if ((entity->buf.st_mode & S_IFCHR) == S_IFCHR)
		b_printf("%s%s%s%s%s", CBLUE, BYELLOW, entity->name, BBLACK, CWHITE);
	else
		b_printf("%s%s", CWHITE, entity->name);
}
