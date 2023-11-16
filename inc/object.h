/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:46:43 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/17 01:49:04 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "libcolor.h"
# include "libft.h"
# include "material.h"
# include "ray.h"
# include <stdbool.h>

typedef struct s_object	t_object;
typedef struct s_hit	t_hit;

typedef t_color			(*t_fn_obj_get_color)(const t_object*, const t_hit*);
typedef bool			(*t_fn_obj_get_dist)(const t_object*, t_ray, double*);
typedef t_vec3			(*t_fn_obj_get_normal)(const t_object*, t_ray, t_vec3);
typedef void			(*t_fn_obj_free_ptr)(void*);

typedef struct s_object{
	void				*ptr;
	bool				is_checkerboard;
	void				*bump_map;
	t_color				color;
	t_material			material;
	t_fn_obj_get_color	get_color;
	t_fn_obj_get_dist	get_dist;
	t_fn_obj_get_normal	get_normal;
	t_fn_obj_free_ptr	free_ptr;
}	t_object;

t_object		*object_new(void *ptr);
void			object_free(void *object);
const t_object	*object_get_closest(t_ray ray, t_vla *objects);

#endif
