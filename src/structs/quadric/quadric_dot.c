/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 02:00:25 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/08 02:45:03 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quadric.h"

double	quadric_dot(t_vec3 coeff, t_vec3 vec1, t_vec3 vec2)
{
	return (coeff.x * vec1.x * vec2.x
		+ coeff.y * vec1.y * vec2.y
		+ coeff.z * vec1.z * vec2.z);
}
