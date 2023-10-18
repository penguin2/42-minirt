/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:58:19 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/18 02:25:13 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "camera.h"
# include "scene.h"

# define BITS_PER_BYTE	(8)

typedef struct s_image{
	t_scene		*scene;
	int			width;
	int			height;
	int			local_endian;
	void		*ptr;
	void		*addr;
	int			byte_per_pixel;
	int			size_line;
	int			endian;
}	t_image;

int		image_init(t_image *image, t_camera *camera);
void	image_render_scene(void *mlx, t_image *image, t_scene *scene);
void	image_write_color(
			void *mlx, t_image *image, unsigned char *dst, int color);

#endif
