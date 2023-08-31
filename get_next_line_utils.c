/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:27:53 by ancolmen          #+#    #+#             */
/*   Updated: 2022/12/12 14:08:54 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char *)malloc((len + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		len;
	char	*str;

	str = (char *)s;
	i = 0;
	len = 0;
	while (s[len])
		len++;
	while (i <= len)
	{
		if ((char)c == s[i])
			return (str + i);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	size_t	i;
	char	*dup;

	size = 0;
	i = 0;
	while (s[size])
		size++;
	dup = (char *)malloc((size + 1) * sizeof(char));
	if (!dup)
		return (0);
	while (i < size)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	sub_len;

	i = start;
	sub_len = 0;
	while (i < ft_strlen(s) && i < (start + len))
	{
		sub_len++;
		i++;
	}	
	new = (char *)malloc((sub_len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (sub_len)
	{
		new[i] = s[start + i];
		i++;
		sub_len--;
	}
	new[i] = '\0';
	return (new);
}
