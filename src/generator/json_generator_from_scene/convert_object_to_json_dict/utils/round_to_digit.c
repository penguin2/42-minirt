/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_to_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:11:09 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/15 14:45:02 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double	_create_small_number_with_digit(int digit)
{
	double	n;

	n = 1.0;
	while (0 < digit--)
		n *= 0.1;
	return (n / 2.0);
}

double	round_to_digit(double n, int limit_digit)
{
	if (n < 0)
		n -= _create_small_number_with_digit(limit_digit);
	else
		n += _create_small_number_with_digit(limit_digit);
	return (n);
}
