/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:12:37 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/11/15 17:12:39 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	append_list(t_list **list, char *buf)
{
	t_list	*newnode;
	t_list	*last_node;

	last_node = find_last_node(*list);
	newnode = malloc(sizeof(t_list));
	if (newnode == NULL)
		return ;
	if (list == NULL)
		*list = newnode;
	else
		last_node->next = newnode;
	newnode->str = buf;
	newnode->next = NULL;
}

int	found_newline(t_list *list)
{
	int	i;

	if (NULL == list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str[i] && i < BUFFER_SIZE)
		{
			if (list->str[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

int	len_list(t_list *list)
{
	int	len;
	int	i;

	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
			{
				len++;
				return (len);
			}
			len++;
			i++;
		}
		list = list->next;
	}
	return (len);
}

void	copy_str(t_list *list, char *new_str)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
			{
				new_str[x++] = list->str[i];
				new_str[x] = '\0';
				return ;
			}
			new_str[x] = list->str[i];
			i++;
			x++;
		}
		list = list->next;
	}
	new_str[x] = '\0';
}

t_list	*find_last_node(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}
