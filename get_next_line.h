/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:16:38 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/27 17:17:28 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

# include <unistd.h>
# include <stdlib.h>

int	ft_is_newline(const char *s);
int	ft_strlen(const char *s);
char	*ft_strjoin(char *dest, char *s);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_clean_stash(char *s);
char	*get_next_line(int fd);

#endif
