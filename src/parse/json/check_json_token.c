/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_json_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:47:07 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/17 19:44:15 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"
#include "parse.h"

int	check_json_token(t_vla *token)
{
	t_vla	stack;
	int		success_or_error;
	char	*str;

	ft_vla_init(&stack);
	str = (char *)token->array[0];
	if (*str == '{')
	{
		ft_vla_append(&stack, str);
		success_or_error = stat_dict_start(token, &stack, 1, DICT);
	}
	else if (*str == '[')
	{
		ft_vla_append(&stack, str);
		success_or_error = stat_list_start(token, &stack, 1, LIST);
	}
	else
		success_or_error = ERROR;
	ft_vla_free(&stack, NULL);
	return (success_or_error);
}
