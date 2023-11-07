/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_json_to_json_object.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:42:21 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/07 20:41:50 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "define.h"
#include "parse.h"
#include "message_parse.h"
#include "utils.h"
#include <unistd.h>
#include <stdlib.h>

t_vla	*convert_json_to_json_object(const char *file)
{
	t_vla	*token;

	token = convert_json_to_token(file);
	if (token == NULL)
		return (NULL);
	else if (check_token(token) == ERROR)
	{
		print_error(NOT_JSON_FORMAT);
		ft_vla_free(token, free);
		free(token);
		return (NULL);
	}
	else
		return (convert_token_to_json_object(token));
}
