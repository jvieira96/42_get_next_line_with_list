/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:00:34 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/11/15 17:00:35 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while(!found_newline(*list))
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if(buf = NULL)
			return (NULL);
		char_read = read(fd, buf, BUFFER_SIZE);
		if(!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		append_list(list, buf);
	}

}

char *get_next_line(int fd)
{
	t_list	*list;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//creat list untill '\n'
	create_list(&list, fd);
	list = NULL;
}
