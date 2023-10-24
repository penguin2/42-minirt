/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_matrix_mul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:17:08 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/23 16:21:16 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"

t_vec3	vec3_matrix_mul(double (*mat)[3], t_vec3 vec)
{
	t_vec3	ret;

	ret.x = mat[0][0] * vec.x + mat[0][1] * vec.y + mat[0][2] * vec.z;
	ret.y = mat[1][0] * vec.x + mat[1][1] * vec.y + mat[1][2] * vec.z;
	ret.z = mat[2][0] * vec.x + mat[2][1] * vec.y + mat[2][2] * vec.z;
	return (ret);
}
