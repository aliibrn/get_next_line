/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:21:59 by abbouram          #+#    #+#             */
/*   Updated: 2023/12/06 22:48:27 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (0);
}

char	*ft_strjoin(char *databuf, char *buf)
{
	char	*c;
	size_t	i;
	size_t	p;

	if (!databuf)
	{
		databuf = (char *)malloc(1 * sizeof(char));
		databuf[0] = '\0';
	}
	if (!databuf || !buf)
		return (NULL);
	c = malloc (sizeof(char) * (ft_strlen(databuf) + ft_strlen(buf) + 1));
	if (!c)
		return (NULL);
	i = 0;
	while (databuf[i++] != '\0')
		c[i] = databuf[i];
	p = 0;
	while (buf[p] != '\0')
		c[i++] = buf[p++];
	c[i] = '\0';
	return (c);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	unsigned int	i;

	i = 0;
	ptr = (unsigned char *)s;
	if (n == 0)
		return ;
	while (i != n)
	{
		ptr[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size && (count > (SIZE_MAX / size)))
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}
