/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:49:35 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/14 16:42:26 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_count_digit(long long int n)
{
	size_t	counter;

	if (-10 < n && n < 10)
		return (1);
	n /= 10;
	if (n < 0)
		n = -n;
	counter = 1;
	while (0 < n)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}
