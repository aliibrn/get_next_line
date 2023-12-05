#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
#include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_hold_the_line(int fd, char *temp);
char	*ft_find_nl(char *s, int c);
char	*ft_strjoin(char *temp, char *buff);
size_t	ft_strlen(char *s);
char	*ft_get_line(char *temp);
char	*ft_update(char *temp);

#endif
