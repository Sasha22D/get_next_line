/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:17:38 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/27 17:17:40 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	int	bytes;
	char	*buffer;
	static char	*stash = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_is_newline(stash))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	if (!stash || !*stash)
		return (NULL);
	line = ft_strcpy(NULL, stash);
	stash = ft_clean_stash(stash);
	return (line);

}

// #include <stdio.h>
// #include <fcntl.h>
// int	main()
// {
// 	int	fd;
// 	fd = open("file.txt", O_RDONLY);
// 	// printf("fd = %d\n", fd);
// 	char *line;

// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line); // affiche la ligne avec le \n s'il existe
// 		// free(line);
// 	}
// 	close(fd);
// }