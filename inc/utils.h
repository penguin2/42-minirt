/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:37:57 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/08 19:21:24 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libvec3.h"
# include "libft.h"
# include <stdbool.h>

# define NUM_QUADRATIC_EQUATION_ROOTS	(2)
# define LOWER_ROOT						(0)
# define HIGHER_ROOT					(1)

# define EPS							(1e-9)

bool	is_zero(double val);
bool	solve_quadratic_equation(
			double roots[NUM_QUADRATIC_EQUATION_ROOTS], double b, double c);
void	rotate_two_vecs_clockwise(t_vec3 *u, t_vec3 *v, double theta);

bool	is_only_value_node(const t_vla *list);

void	print_error(const char *message1);
void	print_warning(const char *message1);

#endif
