/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:06:05 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/02 01:17:28 by taekklee         ###   ########.fr       */
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
t_color	hit_get_color(
			const t_hit *hit,
			const t_vla *objects,
			const t_vla *lights);

#endif
