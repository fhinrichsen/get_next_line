/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:16:11 by fhinrich          #+#    #+#             */
/*   Updated: 2023/02/20 22:32:12 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*get_next_line(int fd);
char	*gnl_strjoin(char *s1, char *s2);
size_t	gnl_strlen(const char *s);
char	*get_current_line(char *buffer);
char	*free_current_line(char *buffer);
char	*find_nl(char *haystack);
char	*gnl_read(int fd, char *buffer);
char	*ft_strchr(const char *str, int c);
#endif