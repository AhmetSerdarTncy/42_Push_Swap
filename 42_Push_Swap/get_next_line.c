/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahtuncay  <ahtuncay@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 02:09:25 by ahtuncay          #+#    #+#             */
/*   Updated: 2023/12/18 15:43:26 by ahtuncay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static int	ft_sstrchr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static inline char
	*ft_sstrjoin(char *s1, char *s2, int i, int j)
{
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	i = -1;
	j = 0;
	if (!str)
		return (NULL);
	while (++i, s1[i])
		str[i] = s1[i];
	while (s2[j++] != '\0')
		str[i - 1 + j] = s2[j - 1];
	str[i + j - 1] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}

static inline char
	*ft_new_create_buffer(char *buffer, int i, int jndex, int fd)
{
	char	*res;
	int		len;

	len = 0;
	while (buffer[len])
		len++;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i] || fd)
	{
		buffer = (free(buffer), NULL);
		return (NULL);
	}
	res = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!res)
		return (NULL);
	i++;
	while (buffer[i])
		res[jndex++] = buffer[i++];
	res[jndex] = '\0';
	free(buffer);
	buffer = NULL;
	return (res);
}

static inline char
	*ft_create_buffer(char *buffer, int buff_size, int fd, int *i)
{
	char	*tmp;

	*i = 0;
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	while ((buff_size != 0 && !ft_sstrchr(buffer)) && fd != 404)
	{
		buff_size = read(fd, tmp, BUFFER_SIZE);
		if (buff_size == -1)
		{
			tmp = (free(tmp), NULL);
			return (NULL);
		}
		tmp[buff_size] = '\0';
		buffer = ft_sstrjoin(buffer, tmp, 0, 0);
	}
	free(tmp);
	tmp = NULL;
	if (fd == 404 || buffer[0] == 0)
	{
		buffer = (free(buffer), NULL);
		return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_create_buffer(buffer, 1, fd, &i);
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		line[i] = buffer[i];
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	buffer = ft_new_create_buffer(buffer, 0, 0, fd);
	return (line);
}
