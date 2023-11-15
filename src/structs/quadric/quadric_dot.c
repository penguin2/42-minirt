/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 02:00:25 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/15 18:05:04 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quadric.h"

double	quadric_dot(const double coeff_array[QUADRIC_COEFFICIENT_SIZE],
					t_vec3 vec1,
					t_vec3 vec2)
{
	return (coeff_array[COEFF_A] * vec1.x * vec2.x
		+ coeff_array[COEFF_B] * vec1.y * vec2.y
		+ coeff_array[COEFF_C] * vec1.z * vec2.z);
}
