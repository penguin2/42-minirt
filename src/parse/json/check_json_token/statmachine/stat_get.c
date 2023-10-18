/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:50:55 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/18 12:02:15 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"

int	stat_get(t_vla *stack)
{
	if (stack->size == 0)
		return (END);
	else if (*(char *)stack->array[stack->size - 1] == '{')
		return (IN_DICT);
	else
		return (IN_LIST);
}
