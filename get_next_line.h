/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:38:14 by claferna          #+#    #+#             */
/*   Updated: 2024/03/26 17:47:59 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
/*DEFAULT BUFFER_SIZE DECLARATION*/
# define BUFFER_SIZE 10

# include <unistd.h>	//READ LIB
# include <stddef.h>	//SIZE_T LIB
# include <stdlib.h>	//MALLOC, FREE LIB
# include <fcntl.h>		//OPEN, CLOSE LIB

/*LIST DEF*/
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

/*MAIN FUNCTION*/
char	*get_next_line(int fd);
/*UTILS FUNCIONS*/
char	*ft_get_line(t_list *list);
void	ft_clean_list(t_list **list);
void	ft_extract_line_lst(t_list *list, char *line);
void	ft_erase_elements(t_list **list, t_list *clean_node, char *buffer);
/*LST RELATED FUNCTIONS*/
int		ft_find_line(t_list *lst);
void	ft_lstnew(t_list **list, int fd);
void	ft_lstadd_line(t_list **list, char *buffer);
t_list	*ft_lstlast(t_list *list);
#endif
