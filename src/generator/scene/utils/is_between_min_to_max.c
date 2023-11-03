/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_between_min_to_max.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:10:57 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/03 19:42:20 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "utils.h"
#include <stdbool.h>

bool	is_between_min_to_max(double n, double min, double max)
{
	bool	result;

	result = ((min == UNLIMITED && max == UNLIMITED) || (min <= n && n <= max));
	if (result == false)
		print_error(OUTSIDE_THE_RANGE);
	return (result);
}
