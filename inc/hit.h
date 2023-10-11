/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:06:05 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/11 19:56:22 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include "libvec3.h"
# include "object.h"
# include "ray.h"

typedef struct s_hit{
	t_vec3		pos;
	t_vec3		normal;
	t_object	*object;
	t_ray		incoming_ray;
}	t_hit;

#endif
