/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:19:41 by fhinrich          #+#    #+#             */
/*   Updated: 2023/02/20 22:00:32 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

size_t	gnl_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*joined_str;
	size_t	index1;
	size_t	index2;

	index1 = 0;
	index2 = 0;
	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (s1 == NULL)
		return (NULL);
	joined_str = malloc((gnl_strlen(s1) + gnl_strlen(s2) + 1) * sizeof(char));
	if (!joined_str)
		return (NULL);
	while (s1[index1] != '\0')
	{
		joined_str[index1] = s1[index1];
		index1++;
	}
	while (s2[index2] != '\0')
	{
		joined_str[index1] = s2[index2];
		index1++;
		index2++;
	}
	joined_str[gnl_strlen(s1) + gnl_strlen(s2)] = '\0';
	return(joined_str);
}

char	*find_nl(char *haystack)
{
	//returns pointer to nl if it finds it in haystack otherwise NULL
	int		i;

	i = 0;
	if (!haystack)
		return (NULL);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == '\n')
			return (&haystack[i]);
		i++;
	}
	return (NULL);
}