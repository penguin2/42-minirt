/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:10:59 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/24 17:03:40 by taekklee         ###   ########.fr       */
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

typedef struct s_camera{
	t_vec3		eye;
	t_vec3		dir;
	t_vec3		up;
	t_vec3		right;
	double		fov;
	t_viewport	viewport;
}	t_camera;

int		camera_init(t_camera *camera);
void	camera_horizontal_rotate(t_camera *camera, double theta);
void	camera_vertical_rotate(t_camera *camera, double theta);
void	camera_set_viewport(t_viewport *viewport, t_camera *camera);

#endif
