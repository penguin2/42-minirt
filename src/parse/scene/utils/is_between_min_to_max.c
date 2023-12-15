/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_between_min_to_max.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:10:57 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/14 17:45:35 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (min <= n && n <= max);
}
