/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:49:34 by claferna          #+#    #+#             */
/*   Updated: 2024/03/25 16:51:42 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	//TODO
}

int main(void)
{
	char *file = "file";
	int fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	get_next_line(fd);
	return (0);
}
