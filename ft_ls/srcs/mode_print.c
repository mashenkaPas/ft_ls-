/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpas <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 16:07:46 by mpas              #+#    #+#             */
/*   Updated: 2018/11/30 14:41:05 by mpas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_ls.h"

void	apply_mode(mode_t *mode, char *c)
{
	if ((*mode & S_IFDIR) == S_IFDIR)
		*c = 'd';
	if ((*mode & S_IFCHR) == S_IFCHR)
		*c = 'c';
	if ((*mode & S_IFIFO) == S_IFIFO)
		*c = 'p';
	if ((*mode & S_IFBLK) == S_IFBLK)
		*c = 'b';
	if ((*mode & S_IFREG) == S_IFREG)
		*c = '-';
	if ((*mode & S_IFLNK) == S_IFLNK)
		*c = 'l';
}

void	mode_print(mode_t mode)
{
	size_t		i;
	char		c;
	static char temp[10];
	static char buf[] = "rwxrwxrwx";

	i = 0;
	while (i < 9)
	{
		temp[i] = (mode & (1 << (8 - i))) ? buf[i] : '-';
		i++;
	}
	temp[i] = '\0';
	apply_mode(&mode, &c);
	if (mode & S_ISUID)
		temp[2] = (mode & S_IXUSR) ? 's' : 'S';
	if (mode & S_ISGID)
		temp[5] = (mode & S_IXGRP) ? 's' : 'S';
	if (mode & S_ISVTX)
		temp[8] = (mode & S_IXOTH) ? 't' : 'T';
	b_printf("%c%s", c, temp);
}
