/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_json_to_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:41:47 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 15:21:28 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "parse.h"
#include <unistd.h>
#include <stdlib.h>

static char	*_get_all_chars_in_json_file(const char *file)
{
	const int	fd = try_open_file(file, ".json");
	char		*all_chars;

	if (fd == ERROR)
		return (NULL);
	all_chars = get_all_chars_in_file(fd);
	close(fd);
	return (all_chars);
}

t_vla	*convert_json_to_token(const char *file)
{
	t_vla		*token;
	char		*all_chars;

	all_chars = _get_all_chars_in_json_file(file);
	if (all_chars == NULL)
		return (NULL);
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
