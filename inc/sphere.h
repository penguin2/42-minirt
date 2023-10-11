/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:57:02 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/11 16:17:29 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H 

# include "libvec3.h"

typedef struct s_sphere{
	t_vec3	center;
	double	radius;
}	t_sphere;

t_sphere	*sphere_new(t_vec3 center, double radius);
void		sphere_free(void *sphere);

#endif
