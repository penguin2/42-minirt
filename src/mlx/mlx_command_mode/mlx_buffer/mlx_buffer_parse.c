/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_buffer_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:05:12 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/05 15:16:46 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "define.h"
#include "mlx_ptr.h"

int	_clean_up_strings(char **strings)
{
	ft_free_strings(strings);
	return (ERROR);
}

t_fn_exec_command	_select_command_function(const char *command)
{
	if (command == NULL)
		return (NULL);
	else if (ft_is_equal_str(command, "ADD"))
		return (NULL);
	else if (ft_is_equal_str(command, "DELETE"))
		return (NULL);
	else
		return (NULL);
}

int	mlx_buffer_parse(const char *buffer)
{
	int					ret;
	char				**strings;
	t_fn_exec_command	exec_command;

	strings = ft_split(buffer, COMMAND_MODE_SPACE_STR);
	exec_command = _select_command_function(strings[0]);
	if (exec_command != NULL && exec_command(strings) == ERROR)
		ret = SUCCESS;
	else
		ret = ERROR;
	ft_free_strings(strings);
	return (ret);
}
