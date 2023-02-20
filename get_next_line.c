/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:19:49 by fhinrich          #+#    #+#             */
/*   Updated: 2023/02/20 22:57:02 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char	*get_next_line(int fd)
{
	char		*current_line;
	static char	*buffer;
	printf("test");
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = gnl_read(fd, buffer);
	if (!buffer)
		return (NULL);
	current_line = get_current_line(buffer);
	buffer = free_current_line(buffer);
	return (current_line);
}

char	*gnl_read(int fd, char *buffer)
{
	int		read_bytes;
	char	*temp_buffer;

	read_bytes = 1;
	while (!strchr(buffer, '\n') && read_bytes >= 1)
	{
		printf("test while");
		temp_buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
		read_bytes = read(fd, temp_buffer, BUFFER_SIZE);
		if (read_bytes == -1)
				return (free(temp_buffer), NULL);
		if (read_bytes == 0)
			break ;
		if(!temp_buffer)
			return NULL;
		temp_buffer[read_bytes] = '\0';
		printf("%s\n", temp_buffer);
		buffer = gnl_strjoin(buffer, temp_buffer);
		free(temp_buffer);

	}
	return (buffer);
}

char	*get_current_line(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*current_line;

	j = 0;
	if (buffer == NULL)
		return (NULL);
	if (strchr(buffer, '\n') == NULL)
		return (buffer);
	i = ((strchr(buffer, '\n') - (buffer)));
	current_line = malloc((i + 2) * sizeof(char));
	if (!current_line)
		return (NULL);
	while (j < i)
	{
		current_line[j] = buffer[j];
		j++;
	}
	current_line[j] = '\n';
	current_line[j + 1] = '\0';
	return (current_line);
}

char	*free_current_line(char *buffer)
{
	char	*string_after_nl;
	size_t	index;
	size_t	index_next_line;

	index = 0;
	index_next_line = 0;
	while (buffer[index] != '\n' && buffer[index] != '\0')
		index++;
	string_after_nl = malloc((gnl_strlen(buffer) - index + 1) * sizeof(char));
	if (!string_after_nl)
		return (NULL);
	index++;
	while (buffer[index] != '\0')
	{
		string_after_nl[index_next_line++] = buffer[index++];
	}
	string_after_nl[index_next_line] = '\0';
	if (buffer != NULL)
		free(buffer);
	return (string_after_nl);
}

char	*ft_strchr(const char *str, int c)
{
	char	*buffer;

	buffer = (char *)str;
	if (c != '\0')
	{
		while (*buffer != ((char) c) && *buffer != '\0')
			buffer++;
	}
	else
	{
		while (*buffer)
			buffer++;
		return (buffer);
	}
	if (*buffer == ((char) c))
		return (buffer);
	return (NULL);
}