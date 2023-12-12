/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_json_to_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:41:47 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/12 14:49:01 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "parse.h"
#include "message_parse.h"
#include "utils.h"
#include "libgnl.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static char	*_get_all_chars_in_json_file(const char *file)
{
	const int	fd = try_open_file(file, JSON_EXTENSION, O_READ);
	char		*all_chars;

	if (fd == ERROR)
		return (NULL);
	all_chars = get_next_line(fd, NULL, GNL_MODE_ALL);
	if (all_chars == NULL)
		print_error(JSON_FILE_IS_EMPTY);
	close(fd);
	get_next_line(fd, NULL, GNL_MODE_RESET);
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
		print_error(NO_TOKEN);
	return (token);
}
