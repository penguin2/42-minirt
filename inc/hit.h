/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:06:05 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/18 11:19:02 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include "libcolor.h"
# include "libft.h"
# include "libvec3.h"
# include "object.h"
# include "ray.h"

typedef struct s_hit{
	t_vec3			pos;
	t_vec3			normal;
	const t_object	*object;
	t_ray			incoming_ray;
}	t_hit;

t_hit	*hit_new(t_ray incoming_ray, t_vla *objects);
void	hit_free(void *hit);
t_color	hit_get_color(t_hit *hit, t_vla *objects, t_vla *lights);

#endif
