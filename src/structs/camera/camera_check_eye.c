/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_check_eye.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:46:15 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/15 20:48:45 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "define.h"
#include <math.h>

int	camera_check_eye(t_vec3 eye)
{
	if (fabs(eye.x) > CAMERA_EYE_LIMIT
		|| fabs(eye.y) > CAMERA_EYE_LIMIT
		|| fabs(eye.z) > CAMERA_EYE_LIMIT)
		return (ERROR);
	return (SUCCESS);
}
