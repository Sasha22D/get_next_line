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
	static char	*stash = NULL;
	int			bytes;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stash), stash = NULL, NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = NULL;
	while (!ft_is_newline(stash))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	buffer = NULL;
	line = ft_putline(line, stash);
	ft_clean_stash(&stash);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>
// int	main()
// {
// 	int	fd;
// 	fd = open("read_error.txt", O_RDONLY);
// 	// printf("fd = %d\n", fd);
// 	char *line;

// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line); // affiche la ligne avec le \n s'il existe
// 		free(line);
// 	}
// 	close(fd);
// }

// #include <stdio.h>
// #include <fcntl.h>
//   int    main(void)
// {
//     char *line;
//     char *name = "read_error.txt";
//     int fd = open(name, O_RDONLY);
//     line = get_next_line(fd);
//     printf("%s\n", line);
//     free(line);
//     line = get_next_line(fd);
//     printf("%s\n", line);
//     free(line);
//     line = get_next_line(10);
//     printf("%s\n", line);
//     free(line);
//     close(fd);
//     fd = open(name, O_RDONLY);
//     line = get_next_line(fd);
//     printf("%s\n", line);
//     free(line);
//     return (0);
// }