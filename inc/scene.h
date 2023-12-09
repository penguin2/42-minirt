/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:07:44 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/08 20:59:33 by rikeda           ###   ########.fr       */
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

int		scene_init(t_scene *scene, int argc, char **argv);
void	scene_free(t_scene *scene);

#endif
