/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragliga <ragliga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 12:36:10 by ragliga           #+#    #+#             */
/*   Updated: 2026/11/17 11:59:26 by ragliga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stdlib.h>
# include <unistd.h>

char	*read_join(int fd, char *rest);
char	*extract_line(char *rest);
char	*clean_rest(char *rest);
char	*get_next_line(int fd);
size_t	my_strlen(const char *s);
char	*my_strchr(const char *s, int c);
char	*my_substr(char const *s, unsigned int start, size_t len);
char	*my_strjoin(char *s1, char *s2, size_t s2_len);

#endif