/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:52:33 by claferna          #+#    #+#             */
/*   Updated: 2024/03/25 18:00:19 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* DESC: Finds the '\n' character*/
int	ft_find_line(t_list *list)
{
	int	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->content[i] && i < BUFFER_SIZE)
		{
			if (list->content[i] == '\n')
				return (1);
			i++;
		}
		list = list->next; 
	}
	return (0);
}

/* DESC: Create a list of lines*/
void	ft_lstnew(t_list **list, int fd)
{
	int		read_bytes;
	char	*buffer;

	while (!ft_find_line(*lst)) //find \n
	{
		buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if (!buffer)
			return (0);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (!read_bytes)
		{
			free(buffer);
			return (0);
		}
		buffer[read_bytes] = '\0';
		ft_lstadd_line(lst, buffer);
	}
}

/* DESC: Finds the last element of a list*/
t_list	ft_lstlast(t_list *list)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/* DESC: Add new element to a list.*/
void	ft_lstadd_line(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = (t_list *)malloc(sizeof(t_list);
	last_node = ft_lstlast(*list);
	if (!new_node)
		return (0);
	if (!last_node)
		*lst = new_node;
	else
		last_node->next = new_node;
	new_node->content = buffer;
	new_node->next = NULL;
}

/* DESC: Get length of the current line*/
int	ft_get_len_line(t_list *list)
{
	int	len;

	len = 0;
	if (!list)
		return (0);
	//Iterating through the elements till '\0' and counting
	while (list)
	{
		while (list->content[i] && list->content[i] != '\n')
		{
			if (list->content[i] == '\n')
			{
				len++;
				return(len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

/*
** DESC: Extracts all the elements of the list corresponding 
** 		 to the current line.
*/
void	ft_extract_line_lst(t_list *list, char *line)
{
	int	i;
	int	k;

	if (!list)
		return (0);
	//Asignation of the content of the list to line till '\0' found 
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (lst->content[i] == '\n')
			{
				line[k++] = '\n';
				line[k] = '\0';
				return ;
			}
			line[k++] = lst->content[i++];
		}
		list = list->next;
	}
	//null terminating '\n' not found
	line[k] = '\0';
}

/*
** DESC: Gets the current line of the file
*/
char	*ft_get_line(t_list *lst)
{
	int		len_line;
	char	*line;

	if (!lst)
		return (0);
	//Get length of the line to assign malloc
	len_line = ft_get_len_line(list);
	line = (char *)malloc(sizeof(char) * (len_line + 1));
	if (!line)
		return (0);
	//Extract line from the list
	ft_extract_line_lst(lst, line);
	return (line);
}
