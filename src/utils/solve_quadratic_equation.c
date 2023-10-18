/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic_equation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:48:35 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/18 20:54:14 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <math.h>

/**
 * @brief solves the following quadratic equation: x^2 + 2bx + c = 0
 *
 * @param roots roots of the equation if exist (roots[0] < roots[1])
 * @param b coefficient of the equation
 * @param c coefficient of the equation
 * @return true if roots of the equation exist, otherwise false
 */
bool	solve_quadratic_equation(
			double roots[NUM_QUADRATIC_EQUATION_ROOTS], double b, double c)
{
	const double	discriminant = b * b - c;
	double			sqrt_d;

	if (discriminant < 0)
		return (false);
	sqrt_d = sqrt(discriminant);
	roots[LOWER_ROOT] = -b - sqrt_d;
	roots[HIGHER_ROOT] = -b + sqrt_d;
	return (true);
}
