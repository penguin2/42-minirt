/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:59:52 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/11 16:09:32 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "libvec3.h"

typedef struct s_plane{
	t_vec3	origin;
	t_vec3	normal;
}	t_plane;

t_plane	*plane_new(t_vec3 origin, t_vec3 normal);
void	plane_free(void *plane);

#endif
