/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:37:57 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/19 23:00:36 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>

# define NUM_QUADRATIC_EQUATION_ROOTS	(2)
# define LOWER_ROOT						(0)
# define HIGHER_ROOT					(1)

# define EPS							(1e-9)

bool	solve_quadratic_equation(
			double roots[NUM_QUADRATIC_EQUATION_ROOTS], double b, double c);
bool	is_zero(double val);

#endif
