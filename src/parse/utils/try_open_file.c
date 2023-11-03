/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_open_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:27:00 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/03 14:51:28 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"
#include "utils.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	try_open_file(const char *file, const char *extension)
{
	int	fd;

	if (check_extension(file, extension) == ERROR)
	{
		print_error(INVALID_FILE_EXTENSION);
		return (ERROR);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (ERROR);
	}
	return (fd);
}
