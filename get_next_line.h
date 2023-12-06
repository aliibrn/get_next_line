#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

# ifndef SIZE_MAX
# define SIZE_MAX 18446744073709551615UL
# endif

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *temp, char *buff);
size_t	ft_strlen(char *s);
void	ft_bzero(void *s, size_t n);
void    *ft_calloc(size_t count, size_t size);

#endif
