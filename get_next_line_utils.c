/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-i <jlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:20:08 by jlopez-i          #+#    #+#             */
/*   Updated: 2022/10/11 09:51:41 by jlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Calcula la longitud de la string. */

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
/* Localiza la primera ocurrencia del caracter
en la string apuntada por el puntero. */

char	*ft_strchr_gnl(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
/* Reserva con malloc una nueva string,
basada en la unión de las dos strings dadas como parámetros.
Si no existe la primera string, la genero.
Es decir que hay que reservar una memoria para dos strings.
*/

char	*malloc_s1(char *s1)
{
	s1 = malloc(sizeof(char) * 1);
	if (!s1)
		return (NULL);
	s1[0] = '\0';
	return (s1);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*new;

	if (!s1)
	s1 = malloc_s1(s1);
	new = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!new || !s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new[i + j] = s2[j];
			j++;
	}
	new[i + j] = '\0';
	free(s1);
	return (new);
}
