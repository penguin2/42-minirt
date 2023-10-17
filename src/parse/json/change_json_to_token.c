/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_json_to_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:41:47 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/17 21:28:36 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "parse.h"
#include "libft.h"
#include <stddef.h>
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
	token = json_tokenizer(all_chars);
	free(all_chars);
	if (check_json_token(token) == ERROR)
	{
		ft_vla_free(token, free);
		free(token);
		return (NULL);
	}
	return (token);
}
// int main(void)
// {
// 	size_t	idx = 0;
// 	char *file = "./test.json";
// 	t_vla *token = change_json_to_token(file);
// 	if (token == NULL)
// 		printf("not json format\n");
// 	else
// 	{
// 		while (token->size > idx)
// 			printf("%s\n", (char *)token->array[idx++]);
// 	}
// 	return (0);
// }
