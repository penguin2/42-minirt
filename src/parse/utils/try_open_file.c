/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_open_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:27:00 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/15 15:58:58 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "message_parse.h"
#include "define.h"
#include "utils.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	try_open_file(const char *file, const char *extension, int flag)
{
	int	fd;

	if (check_extension(file, extension) == ERROR)
	{
		print_error(INVALID_FILE_EXTENSION);
		return (ERROR);
	}
	if (flag == O_WRITE)
		fd = open(file, flag, OPEN_MODE);
	else
		fd = open(file, flag);
	if (fd == -1)
	{
		perror("open");
		print_error(FILE_OPEN_FAILED);
		return (ERROR);
	}
	return (fd);
}
