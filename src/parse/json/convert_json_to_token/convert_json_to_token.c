/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_json_to_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:41:47 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/23 16:08:54 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "parse.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

static int	_try_open_json_file(const char *json_file)
{
	int	fd;

	if (check_extension(json_file, ".json") == ERROR)
	{
		ft_putendl_fd(NOT_JSON_EXTENSITON, STDERR_FILENO);
		return (ERROR);
	}
	fd = open(json_file, O_RDONLY);
	if (fd == -1)
	{
		perror("check_json_format");
		return (ERROR);
	}
	return (fd);
}

t_vla	*convert_json_to_token(const char *file)
{
	t_vla		*token;
	char		*all_chars;
	const int	fd = _try_open_json_file(file);

	if (fd == ERROR)
		return (NULL);
	all_chars = get_all_chars_in_file(fd);
	close(fd);
	token = tokenize(all_chars);
	free(all_chars);
	if (token == NULL)
		ft_putendl_fd(NO_TOKEN, STDERR_FILENO);
	else if (check_token(token) == ERROR)
	{
		ft_putendl_fd(NOT_JSON_FORMAT, STDERR_FILENO);
		ft_vla_free(token, free);
		free(token);
		token = NULL;
	}
	return (token);
}
