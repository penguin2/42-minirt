/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_chars_in_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:19:39 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/15 21:09:23 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../lib/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

char	*get_all_chars_in_file(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*all_chars;
	char	*tmp;

	tmp = NULL;
	all_chars = NULL;
	while (1)
	{
		ft_memset(&buffer, 0, BUFFER_SIZE + 1);
		if (read(fd, buffer, BUFFER_SIZE) == 0)
			break ;
		all_chars = ft_strjoin(tmp, buffer);
		if (tmp != NULL)
			free(tmp);
		tmp = all_chars;
	}
	return (all_chars);
}

/* #include <fcntl.h> */
/* #include <stdio.h> */
/* int main(void) */
/* { */
/* 	int	fd = open("./del_commentout.c", O_RDONLY); */
/* 	if (fd < 0) */
/* 	{ */
/* 		printf("ERROR\n"); */
/* 		exit(1); */
/* 	} */
/* 	char *chars = get_all_chars_in_file(fd); */

/* 	printf("%s\n", chars); */
/* 	close(fd); */
/* 	return (0); */
/* } */
