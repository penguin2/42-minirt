/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_json_to_json_object.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:42:21 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 15:43:34 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "define.h"
#include "parse.h"
#include <unistd.h>
#include <stdlib.h>

t_vla	*convert_json_to_json_object(const char *file)
{
	t_vla	*token;

	token = convert_json_to_token(file);
	if (token == NULL)
	{
		ft_putendl_fd(NO_TOKEN, STDERR_FILENO);
		return (NULL);
	}
	else if (check_token(token) == ERROR)
	{
		ft_putendl_fd(NOT_JSON_FORMAT, STDERR_FILENO);
		ft_vla_free(token, free);
		free(token);
		return (NULL);	
	}
	else
		return (convert_token_to_json_object(token));
}
