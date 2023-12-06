/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:13:37 by abbouram          #+#    #+#             */
/*   Updated: 2023/12/06 22:50:44 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_to_data_buf(int fd, char *databuf)
{
	char	*buf;
	int		read_bytes;

	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(databuf, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			free(databuf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		databuf = ft_strjoin(databuf, buf);
	}
	free(buf);
	return (databuf);
}

static char	*ft_get_line(char *databuf)
{
	int		i;
	char	*line;

	i = 0;
	if (!databuf[i])
		return (NULL);
	while (databuf[i] && databuf[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (databuf[i] && databuf[i] != '\n')
	{
		line[i] = databuf[i];
		i++;
	}
	if (databuf[i] == '\n')
	{
		line[i] = databuf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_update_data(char *databuf)
{
	int		i;
	int		j;
	char	*update;

	i = 0;
	while (databuf[i] && databuf[i] != '\n')
		i++;
	if (!databuf[i])
	{
		free(databuf);
		return (NULL);
	}
	update = ft_calloc((ft_strlen(databuf) - i + 1), sizeof(char));
	if (!update)
		return (NULL);
	i++;
	j = 0;
	while (databuf[i])
		update[j++] = databuf[i++];
	update[j] = '\0';
	free(databuf);
	return (update);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*databuf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	databuf = ft_read_to_data_buf(fd, databuf);
	if (!databuf)
		return (NULL);
	line = ft_get_line(databuf);
	databuf = ft_update_data(databuf);
	return (line);
}
