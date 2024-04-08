/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:50:51 by claferna          #+#    #+#             */
/*   Updated: 2024/04/08 20:31:21 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
** DESC: The 'ft_lstnew' creates a list of lines till '\n' is found.
*/
int	ft_lstnew(t_list **list, int fd)
{
	int		read_bytes;
	char	*buffer;

	while (!ft_find_line(list[fd]))
	{
		buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return (-1);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (-1);
		}
		if (read_bytes == 0)
		{
			free(buffer);
			return (0);
		}
		buffer[read_bytes] = '\0';
		ft_lstadd_line(list, buffer, fd);
	}
	return (0);
}

/*
** DESC: The 'ft_get_line' extracts from the list the current line of the file.
*/
char	*ft_get_line(t_list *list)
{
	int		len_line;
	char	*line;

	if (!list)
		return (0);
	len_line = ft_get_len_line(list);
	line = (char *)malloc(sizeof(char) * (len_line + 1));
	if (!line)
		return (0);
	ft_extract_line_lst(list, line);
	return (line);
}

/* DESC: The 'ft_erase_elements' erases the elements of the list corresponding
to the line that has just been printed.*/
void	ft_erase_elements(t_list **list, t_list *clean_node, char *buffer)
{
	t_list	*aux;

	aux = NULL;
	if (!list)
		return ;
	while (*list != NULL)
	{
		aux = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = aux;
	}
	*list = NULL;
	if (clean_node->content[0])
		*list = clean_node;
	else
	{
		free(buffer);
		free(clean_node);
		clean_node = NULL;
	}
}

/*
** DESC: The 'ft_clean_list' cleans the list for further reads. This is to say
**       the elements that have already been printed.
*/
void	ft_clean_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	char	*next_line;
	int		i;
	int		k;

	next_line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	clean_node = (t_list *)malloc(sizeof(t_list));
	if (!next_line || !clean_node)
		return ;
	last_node = ft_lstlast(*list);
	i = 0;
	k = 0;
	while (last_node->content[i] != '\0' && last_node->content[i] != '\n')
		i++;
	if (last_node->content[i] == '\n')
		i++;
	while (last_node->content[i] != '\0')
		next_line[k++] = last_node->content[i++];
	next_line[k] = '\0';
	clean_node->content = next_line;
	clean_node->next = NULL;
	ft_erase_elements(list, clean_node, next_line);
}

/*
** DESCRIPTION: The 'get_nex_line' function is the main fuction. It gets 
**              the next line of a file, divided by \n (line break).
*/
char	*get_next_line(int fd)
{
	static t_list	*list[4096];
	char			*next_line;
	t_list			*aux;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (ft_lstnew(list, fd) == -1)
	{
		while (list[fd])
		{
			aux = (list[fd])->next;
			free((list[fd])->content);
			free(list[fd]);
			list[fd] = aux;
		}
		list[fd] = NULL;
	}
	if (!list[fd])
		return (0);
	next_line = ft_get_line(list[fd]);
	ft_clean_list(&list[fd]);
	return (next_line);
}
/*
#include <stdio.h>
int main(void)
{
	char *file = "file";
	int fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	int i = 9;
	while (i--)
	{
		char *result = get_next_line(fd);
		printf("Linea %d: %s", i, result);
		free(result);
	}
	close(fd);
	char *file2 = "file2";
	int fd2 = open(file2, O_RDONLY);
	if (fd2 == -1)
		return (0);
	int j = 4;
	while (j--)
	{
		char *result2 = get_next_line(fd);
		printf("Linea %d: %s", j, result2);
		free(result2);
	}
	close(fd2);
	//system("leaks -q a.out");
	return (0);
}*/
