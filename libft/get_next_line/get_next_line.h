/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 01:49:37 by ahocine           #+#    #+#             */
/*   Updated: 2021/07/01 01:49:42 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft.h"

int		ft_init(ssize_t *lu, char **line, char **reste, char *buf);
void	ft_free_eof(ssize_t lu, char **line, char **reste);
void	*ft_calloc(size_t number, size_t len);
void	*ft_memset(void *dest, int c, size_t len);
void	ft_strcat(char *dest, char *src);
char	*get_next_line(int fd);
char	*ft_reste(char *buf);
void	ft_line(char **line);
int		ft_search_end(char *str);

#endif
