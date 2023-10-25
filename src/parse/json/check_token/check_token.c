/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:47:07 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 18:41:13 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"
#include "parse.h"

/**
* @brief check json format by statmachine
*
* @param token json token
*
* @return SUCCESS or ERROR
*/
int	check_token(t_vla *token)
{
	t_vla	stack;
	int		success_or_error;
	char	*str;

	ft_vla_init(&stack);
	str = (char *)token->array[0];
	if (*str == '{')
	{
		ft_vla_append(&stack, str);
		success_or_error = state_dict_start(token, &stack, 1, IN_DICT);
	}
	else if (*str == '[')
	{
		ft_vla_append(&stack, str);
		success_or_error = state_list_start(token, &stack, 1, IN_LIST);
	}
	else
		success_or_error = ERROR;
	ft_vla_free(&stack, NULL);
	return (success_or_error);
}
