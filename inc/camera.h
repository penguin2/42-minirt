/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:10:59 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/26 22:21:02 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "libvec3.h"

typedef struct s_viewport{
	int		width;
	int		height;
	t_vec3	upper_left;
	t_vec3	dw;
	t_vec3	dh;
}	t_viewport;

typedef enum e_camera_direction{
	CAMERA_DIRECTION_FRONT,
	CAMERA_DIRECTION_LEFT,
	CAMERA_DIRECTION_BACK,
	CAMERA_DIRECTION_RIGHT,
	CAMERA_DIRECTION_UP,
	CAMERA_DIRECTION_DOWN,
}	t_camera_direction;

typedef enum e_camera_rotation{
	CAMERA_ROTATION_UP,
	CAMERA_ROTATION_LEFT,
	CAMERA_ROTATION_DOWN,
	CAMERA_ROTATION_RIGHT,
}	t_camera_rotation;

typedef struct s_camera{
	t_vec3		eye;
	t_vec3		dir;
	t_vec3		up;
	t_vec3		right;
	double		fov;
	t_viewport	viewport;
}	t_camera;

int		camera_init(t_camera *camera);
void	camera_set_viewport(t_camera *camera, t_viewport *viewport);

int		camera_move(t_camera *camera, t_camera_direction camera_direction);
int		camera_rotate(t_camera *camera, t_camera_rotation camera_rotation);

#endif
