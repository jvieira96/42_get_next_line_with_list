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

void	append_list(t_list *list,char *buf)
{
	t_list	*newnode;
	t_list	*temp;

	temp = list;
	newnode->str = buf;
	if (list->next == NULL)
	{
		list = newnode;
		newnode->next = NULL;
	}
	else
	{
		while (temp->next != '\0')
			temp = temp->next;
		temp->next = newnode;
		newnode->next = NULL;
	}
}
