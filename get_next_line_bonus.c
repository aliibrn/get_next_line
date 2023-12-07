
#include "get_next_line.h"

static char	*ft_read_to_data_buf(int fd, char *databuf)
{
	char	*buf;
	int		read_bytes;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
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
	line = (char *)malloc(sizeof(char) * (i + 2));
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
	update = (char *)malloc(sizeof(char) * (ft_strlen(databuf) - i + 1));
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
	static char	*databuf[FD_SETSIZE];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_SETSIZE)
		return (0);
	databuf[fd] = ft_read_to_data_buf(fd, databuf[fd]);
	if (!databuf[fd])
		return (NULL);
	line = ft_get_line(databuf[fd]);
	databuf[fd] = ft_update_data(databuf[fd]);
	return (line);
}
