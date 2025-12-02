/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:17:51 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/27 17:17:52 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

int	ft_is_newline(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *dest, char *s)
{
	int	i;
	int	dst_len;
	char	*new;

	i = 0;
	dst_len = ft_strlen(dest);

	new = malloc(dst_len  + ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	if (dest != NULL)
	{
		while (dest[i])
		{
			new[i] = dest[i];
			i++;
		}
	}
	while (*s)
	{
		new[i] = *s;
		s++;
		i++;
	}
	new[i] = '\0';
	free(dest);
	return (new);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	if (!src || !*src)
		return (NULL);
	while (src[i] && src[i] != '\n')
		i++;
	dest = malloc(i + (src[i] == '\n') + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dest[i++] = '\n';
	dest[i] = '\0';
	return (dest);
}

char	*ft_clean_stash(char *s)
{
	int	i;
	char	*str;

	i = 0;
	str = NULL;
	if (!s || !*s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	i++;
	str = ft_strjoin(str, s + i);
	free(s);
	return (str);
}