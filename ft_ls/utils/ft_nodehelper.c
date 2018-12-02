/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodehelper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpas <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 16:53:52 by mpas              #+#    #+#             */
/*   Updated: 2018/10/19 16:53:56 by mpas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_ls.h"

void	node_copy(t_node *src, t_node *dst)
{
	t_node *temp;

	temp = dst;
	temp->name = src->name;
	temp->buf = src->buf;
}

t_node	*node_remove_hidden(t_node *head)
{
	t_node	*current;

	current = head;
	while (current && current->name[0] == '.')
		head = current->next;
	while (current && current->next)
	{
		if (current->next->name[0] == '.')
			current->next = current->next->next;
		current = current->next;
	}
	return (head);
}

int		node_size(t_node *head)
{
	int		i;
	t_node	*entity;

	i = 0;
	if (head)
	{
		entity = head;
		while (entity)
			(entity = entity->next) && i++;
	}
	return (i);
}

void	node_swap(t_node *one, t_node *two)
{
	t_node *temp;

	temp = (t_node *)malloc(sizeof(t_node));
	node_copy(one, temp);
	node_copy(two, one);
	node_copy(temp, two);
	free(temp);
}
