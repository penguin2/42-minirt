/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_json_to_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:41:47 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/15 23:38:19 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	_try_open_json_file(const char *json_file)
{
	int	fd;

	if (check_extension(json_file, ".json") == ERROR)
		return (ERROR);
	fd = open(json_file, O_RDONLY);
	if (fd == -1)
	{
		perror("check_json_format");
		return (ERROR);
	}
	return (fd);
}

t_vla	*change_json_to_token(const char *file)
{
	int		fd;
	char	*all_chars;
	t_vla	*token;

	fd = _try_open_json_file(file);
	if (fd == ERROR)
		return (NULL);
	all_chars = get_all_chars_in_file(fd);
	close(fd);
	free(all_chars);
	token = json_tokenizer(all_chars);
	if (check_json_token(token))
	{
		ft_vla_free(token, free);
		free(token);
		return (NULL);
	}
	return (token);
}
