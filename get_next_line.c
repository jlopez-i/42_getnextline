/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-i <jlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:19:47 by jlopez-i          #+#    #+#             */
/*   Updated: 2022/10/11 09:50:43 by jlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Funcion que leera del fd en un loop hasta 
detectar el salto de linea \n o el final de linea \0 */

static char	*ft_reader_line(char *buffer, int fd)
{
	char	*read_buffer;
	int		nbytes;

	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buffer)
		return (NULL);
	read_buffer[0] = '\0';
	nbytes = 1;
	while (nbytes > 0 && !ft_strchr_gnl(read_buffer, '\n'))
	{
		nbytes = read(fd, read_buffer, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(read_buffer);
			free(buffer);
			return (NULL);
		}
		read_buffer[nbytes] = '\0';
		buffer = ft_strjoin_gnl(buffer, read_buffer);
	}
	free(read_buffer);
	return (buffer);
}

static char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[0])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer [i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_update_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*update_buffer;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	i++;
	update_buffer = malloc(sizeof(char) * ((ft_strlen_gnl(buffer) + 1)));
	if (!update_buffer)
		return (NULL);
	while (buffer[i] != '\0')
		update_buffer[j++] = buffer[i++];
	update_buffer[j] = '\0';
	free(buffer);
	return (update_buffer);
}
/* Funcion principal que coordina y llama a las otras funciones*/

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer || (buffer && !(ft_strchr_gnl(buffer, '\n'))))
		buffer = ft_reader_line(buffer, fd);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_update_buffer(buffer);
	return (line);
}
