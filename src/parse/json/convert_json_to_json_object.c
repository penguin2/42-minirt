/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_json_to_json_object.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:42:21 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 15:22:26 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"

t_vla	*convert_json_to_json_object(const char *file)
{
	t_vla	*token;
	t_vla	*json_object;

	token = convert_json_to_token(file);
	if (token == NULL)
		return (NULL);
	json_object = convert_token_to_json_object(token);
	return (json_object);
}
