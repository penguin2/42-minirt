/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:07:44 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/11 17:37:45 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "libft.h"
# include "camera.h"

typedef struct s_scene{
	t_camera	camera;
	t_vla		objects;
	t_vla		lights;
}	t_scene;

int	scene_init(t_scene *scene, int argc, char **argv);

#endif
