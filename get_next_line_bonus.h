/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:40:57 by claferna          #+#    #+#             */
/*   Updated: 2024/04/08 20:30:37 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
/*DEFAULT BUFFER_SIZE DECLARATION*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

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
int		ft_lstnew(t_list **list, int fd);
char	*ft_get_line(t_list *list);
void	ft_clean_list(t_list **list);
/*UTILS FUNCTIONS*/
void	ft_extract_line_lst(t_list *list, char *line);
void	ft_erase_elements(t_list **list, t_list *clean_node, char *next_line);
int		ft_find_line(t_list *lst);
void	ft_lstadd_line(t_list **list, char *buffer, int fd);
t_list	*ft_lstlast(t_list *list);
int		ft_get_len_line(t_list *list);
#endif
