/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_between_min_to_max.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:10:57 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/20 21:45:36 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "message_parse.h"
#include "utils.h"
#include <stdbool.h>

/**
* @brief Check if the value is between the lower limit and the upper limit.
*
* @param n Value to be checked.
* @param min Lower limit of value.
* @param max Upper limit of value.
*
* @return True if the value is between the lower and upper limits,
*		  false otherwise.
*/
bool	is_between_min_to_max(double n, double min, double max)
{
	bool	result;

	result = (min <= n && n <= max);
	if (result == false)
		print_error(OUTSIDE_THE_RANGE);
	return (result);
}
