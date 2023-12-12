/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartesian_system.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:47:41 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/29 19:36:08 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CARTESIAN_SYSTEM_H
# define CARTESIAN_SYSTEM_H

# include "libvec3.h"

typedef struct s_cartesian_system{
	t_vec3	axis_x;
	t_vec3	axis_y;
	t_vec3	axis_z;
}	t_cartesian_system;

t_cartesian_system	cartesian_system_create(
						t_vec3 axis_x,
						t_vec3 axis_y,
						t_vec3 axis_z);
t_vec3				cartesian_system_map_from_standard(
						const t_cartesian_system *system,
						t_vec3 standard_vec);
t_vec3				cartesian_system_map_to_standard(
						const t_cartesian_system *system,
						t_vec3 system_vec);
#endif
