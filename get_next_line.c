/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:49:34 by claferna          #+#    #+#             */
/*   Updated: 2024/03/26 18:55:57 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


/*
** DESCRIPTION: Gets the next line of a file, divided by \n (line break).
*/

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;
	
	//ERROR COMPROBATIONS
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (0);
	//CREATION OF THE LIST
	ft_lstnew(&list, fd);
	if (!list)
		return (0);
	//GET THE LINE
	next_line = ft_get_line(list);
	//CLEAN LIST
	ft_clean_list(&list);
	return (next_line);
}

#include <stdio.h>

int main(void)
{
	char *file = "file";
	int fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	int i = 7;
	while (i--)
		printf("Linea %d: %s", i, get_next_line(fd));
	return (0);
}
