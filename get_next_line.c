#include "get_next_line.h"

static char	*hold_the_line(int fd, char *hold)
{
	char	*buf;
	int		read_bytes;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	read_bytes = 1;
	while (!ft_find_nl(hold, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			free(hold);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		hold = ft_strjoin(hold, buf);
	}
	free(buf);
	return (hold);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*hold;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	hold = hold_the_line(fd, hold);
	if (!hold)
		return (NULL);
	line = ft_get_line(hold);
	hold = ft_update(hold);
	return (line);
}
int main() {
    int fd = open("test_file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("Line: %s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}

