/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:58:19 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/16 20:29:13 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "camera.h"
# include "scene.h"

typedef struct s_image{
	void		*ptr;
	t_scene		*scene;
	int			width;
	int			height;
}	t_image;

int		image_init(t_image *image, t_camera *camera);
int		image_render_scene(t_image *image, t_scene *scene);

#endif
