/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_type.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:53:57 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/18 11:00:40 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FN_TYPE_H
# define FN_TYPE_H

# include "libvec3.h"
# include "ray.h"
# include <stdbool.h>

typedef struct s_object	t_object;
typedef bool			(*t_fn_get_dist)(const t_object*, t_ray, double*);
typedef t_vec3			(*t_fn_get_normal)(const t_object*, t_ray, t_vec3);
typedef void			(*t_fn_free_ptr)(void *);

#endif
