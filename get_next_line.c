/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:22:42 by ancolmen          #+#    #+#             */
/*   Updated: 2022/12/14 15:26:55 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
*GET NEXT LINE*
*checks if buffer_size, fd and nbytes are valid
*checks and initializes the static stash (if it is the first run)
*calls *read_and_stash* to start the reading
*if there is anything to read, returns NULL
*if there is something in this line, returns the line
*/
char	*get_next_line(int fd)
{
	static char	*s_stash = NULL;
	char		*line;
	ssize_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!s_stash)
		s_stash = ft_strdup("");
	n = read_and_stash(fd, &s_stash, &line);
	if (!line || n < 0)
		return (NULL);
	return (line);
}

/*
*READ AND STASH*
*reads up to buffer_size bytes, stashes them in buff[]
*this loop copies buf in s_stash until it finds an \n or n == 0,
*growing at each turn. when \n is found or n is zero, the loop stops,
*and we call *get_line*
*returns the number of bytes read
*/
ssize_t	read_and_stash(int fd, char **s_stash, char **line)
{
	char	*buf;
	char	*tmp;
	ssize_t	n;

	n = 1;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	while (!ft_strchr(*s_stash, '\n') && n)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n <= 0)
			break ;
		buf[n] = '\0';
		tmp = *s_stash;
		*s_stash = ft_strjoin(tmp, buf);
		free(tmp);
	}
	free(buf);
	buf = NULL;
	*s_stash = get_line(s_stash, line);
	return (n);
}

/*
*GET_LINE*
*If a \n is found or n == 0, it is time to return the line
*and save the rest in a new stash that will be sleeping 
*until the next call of *get_next_line*
*if after get line line is \0, means nothing is there,
*so it frees line before leaving
*/
char	*get_line(char **s_stash, char **line)
{
	char	*new_stash;
	size_t	i;

	i = 0;
	new_stash = NULL;
	while ((*(*s_stash + i) != '\n') && (*(*s_stash + i) != '\0'))
		i++;
	if (*(*s_stash + i) == '\n')
	{
		i++;
		*line = ft_substr(*s_stash, 0, i);
		new_stash = ft_strdup(*s_stash + i);
	}
	else
		*line = ft_strdup(*s_stash);
	free(*s_stash);
	*s_stash = NULL;
	if (**line == '\0')
	{
		free(*line);
		*line = NULL;
	}
	return (new_stash);
}
