/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smallfn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpas <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 16:54:15 by mpas              #+#    #+#             */
/*   Updated: 2018/10/19 16:54:35 by mpas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_ls.h"

void	ft_list_clean(t_node **list)
{
	t_node	*link;

	if (*list == NULL)
		return ;
	link = *list;
	if (link->next)
		ft_list_clean(&link->next);
	free(link->name);
	free(*list);
}

int		ft_str_find(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[j])
	{
		if (s1[j] == s2[i])
			++i;
		if (s2[i] == '\0')
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strcat(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	while (s1[i])
		(res[i] = s1[i]) && i++;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*str;

	i = 0;
	while (src[i])
		i++;
	if ((str = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
