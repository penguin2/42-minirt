/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_json_token_nest.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:16:52 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/17 17:31:04 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"
#include "parse.h"

static int	_check_json_token_nest_loop(t_vla *token, t_vla *stack)
{
	size_t	idx;
	char	*str;

	idx = 1;
	while (idx < token->size && stack->size != 0)
	{
		str = (char *)token->array[idx];
		if (*str == '{' || *str == '[')
			ft_vla_append(stack, str);
		else if (*str == '}' && *(char *)ft_vla_pop(stack) != '{')
			return (ERROR);
		else if (*str == ']' && *(char *)ft_vla_pop(stack) != '[')
			return (ERROR);
		idx++;
	}
	if (idx == token->size && stack->size == 0)
		return (SUCCESS);
	else
		return (ERROR);
}

int	check_json_token_nest(t_vla *token)
{
	t_vla	stack;
	int		success_or_error;
	char	*str;

	success_or_error = ERROR;
	ft_vla_init(&stack);
	str = (char *)token->array[0];
	if (*str == '{' || *str == '[')
		ft_vla_append(&stack, str);
	if (stack.size != 0)
		success_or_error = _check_json_token_nest_loop(token, &stack);
	ft_vla_free(&stack, NULL);
	return (success_or_error);
}
