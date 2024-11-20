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

#include "get_next_line_bonus.h"

void	list_prep(t_list **list)
{
	int		i;
	int		x;
	t_list	*last_node;
	t_list	*clean_node;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buf == NULL || clean_node == NULL)
		return ;
	last_node = find_last_node(*list);
	x = 0;
	i = 0;
	while (last_node->str[i] && last_node->str[i] != '\n')
		++i;
	while (last_node->str[i] && last_node->str[++i])
		buf[x++] = last_node->str[i];
	buf[x] = '\0';
	clean_node->str = buf;
	clean_node->next = NULL;
	dealloc(list, clean_node, buf);
}

char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	str_len = len_list(list);
	next_str = malloc(str_len + 1);
	if (next_str == NULL)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	append_list(t_list **list, char *buf, int fd)
{
	t_list	*newnode;
	t_list	*last_node;

	last_node = find_last_node(list[fd]);
	newnode = malloc(sizeof(t_list));
	if (newnode == NULL)
		return ;
	if (last_node == NULL)
		list[fd] = newnode;
	else
		last_node->next = newnode;
	newnode->str = buf;
	newnode->next = NULL;
}

void	list_add(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!found_newline(list[fd]))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		append_list(list, buf, fd);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list[4096];
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	list_add(list, fd);
	if (list[fd] == NULL)
		return (NULL);
	next_line = get_line(list[fd]);
	list_prep(&list[fd]);
	return (next_line);
}

// int	main(void)
// {
// 	int	fd1;
// 	int	fd2;
// 	int	fd3;

// 	fd1 = open("file1.txt", O_RDONLY | O_CREAT);
// 	fd2 = open("file2.txt", O_RDONLY | O_CREAT);
// 	fd3 = open("file3.txt", O_RDONLY | O_CREAT);
// 	printf("fd1 - %s", get_next_line(fd1));
// 	printf("fd2 - %s", get_next_line(fd2));
// 	printf("fd3 - %s\n", get_next_line(fd3));
// 	printf("fd1 - %s", get_next_line(fd1));
// 	printf("fd2 - %s", get_next_line(fd2));
// 	printf("fd3 - %s\n", get_next_line(fd3));
// 	printf("fd1 - %s", get_next_line(fd1));
// 	printf("fd2 - %s", get_next_line(fd2));
// 	printf("fd3 - %s\n", get_next_line(fd3));
// 	return (0);
// }
