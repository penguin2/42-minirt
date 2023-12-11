/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:37:57 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/11 16:39:43 by taekklee         ###   ########.fr       */
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

# define PRINT_COLOR_RED "\e[31m "
# define PRINT_COLOR_YELLOW "\e[33m "
# define PRINT_COLOR_END "\e[m"

bool	is_zero(double val);
bool	solve_quadratic_equation(
			double roots[NUM_QUADRATIC_EQUATION_ROOTS], double b, double c);
void	rotate_two_vecs_clockwise(t_vec3 *u, t_vec3 *v, double theta);

void	print_error(const char *message1);
void	print_warning(const char *message1);
int		error_with_message_if(bool is_error, const char *err_msg);

bool	is_odd_2d(double u, double v);

int		convert_str_to_positive_int(const char *str, int *val);
void	map_3d_to_spherical(double *u, double *v, t_vec3 pos);
void	map_3d_to_cylinder(double *u, double *v, t_vec3 pos);
double	mod_double(double x);

#endif
