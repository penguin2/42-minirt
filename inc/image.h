/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:58:19 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/17 22:03:26 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "camera.h"
# include "scene.h"

# define BITS_PER_BYTE	(8)

typedef struct s_image{
	t_scene		*scene;
	void		*ptr;
	int			width;
	int			height;
	void		*addr;
	int			byte_per_pixel;
	int			size_line;
	int			endian;
	int			local_endian;
}	t_image;

int		image_init(t_image *image, t_camera *camera);
int		image_render_scene(void *mlx, t_image *image, t_scene *scene);
void	image_write_color(
			t_image *image, unsigned char *dst, unsigned int color);

#endif
