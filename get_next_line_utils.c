/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragliga <ragliga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 12:36:25 by ragliga           #+#    #+#             */
/*   Updated: 2026/11/17 12:00:22 by ragliga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	my_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*my_memcpy(void *dest, void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (src == (void *)0 && dest == (void *)0)
		return (dest);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*my_strjoin(char *s1, char *s2, size_t len_s2)
{
	size_t	len_s1;
	char	*new_string;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
	if (!s1)
		len_s1 = 0;
	else
		len_s1 = my_strlen(s1);
	new_string = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	i = len_s1;
	j = 0;
	my_memcpy(new_string, s1, len_s1);
	while (j < len_s2 && s2[j])
	{
		new_string[i] = s2[j];
		j++;
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

char	*my_substr(const char *s, unsigned int start, size_t len)
{
	char			*sub_string;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start > my_strlen(s))
	{
		sub_string = malloc(sizeof(char) * (1));
		if (!sub_string)
			return (NULL);
		return (sub_string[0] = '\0', sub_string);
	}
	if (len > my_strlen(s + start))
		len = my_strlen(s + start);
	i = 0;
	sub_string = malloc(sizeof(char) * (len + 1));
	if (!sub_string)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub_string[i] = s[start + i];
		i++;
	}
	sub_string[i] = '\0';
	return (sub_string);
}

char	*my_strchr(const char *s, int c)
{
	int		i;
	char	*string;
	int		len;

	if (!s)
		return (NULL);
	len = my_strlen(s);
	string = (char *)s;
	i = 0;
	while (i <= len)
	{
		if (string[i] == (char)c)
			return ((char *)&string[i]);
		i++;
	}
	return (NULL);
}
