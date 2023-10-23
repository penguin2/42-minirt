/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:50:55 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/23 21:11:29 by rikeda           ###   ########.fr       */
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
int	get_stat(t_vla *stack)
{
	if (stack->size == 0)
		return (END);
	else if (*(char *)stack->array[stack->size - 1] == '{')
		return (IN_DICT);
	else
		return (IN_LIST);
}
