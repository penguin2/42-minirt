/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_json_to_json_object.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:42:21 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/01 18:03:09 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "parse.h"
#include "message_parse.h"
#include "utils.h"
#include <stdlib.h>

void	*_clean_up_token(t_vla *token)
{
	print_error(NOT_JSON_FORMAT);
	ft_vla_free(token, free);
	free(token);
	return (NULL);
}

void	*_clean_up_json_object(t_vla *json_object)
{
	print_error(JSON_DICT_KEY_DUPLICATE);
	free_json_object(json_object);
	return (NULL);
}

t_vla	*convert_json_to_json_object(const char *file)
{
	t_vla	*token;
	t_vla	*json_object;

	token = convert_json_to_token(file);
	if (token == NULL)
		return (NULL);
	else if (check_token(token) == ERROR)
		return (_clean_up_token(token));
	json_object = convert_token_to_json_object(token);
	sort_json_object(json_object->array[0]);
	if (check_duplicate_dict_key(json_object->array[0]) == ERROR)
		return (_clean_up_json_object(json_object));
	return (json_object);
}
