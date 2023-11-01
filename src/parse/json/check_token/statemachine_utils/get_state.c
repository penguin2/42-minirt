/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:50:55 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 19:39:02 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"

/**
* @brief Determine whether you are currently in the dict or list
*
* @param stack open_brackets stack
*
* @return value depending on the open brackets at the top of the stack
*/
int	get_state(t_vla *stack)
{
	if (stack->size == 0)
		return (END);
	else if (*(char *)stack->array[stack->size - 1] == DICT_START)
		return (IN_DICT);
	else
		return (IN_LIST);
}
