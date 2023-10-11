/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:00:54 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/11 16:09:19 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "libvec3.h"

typedef struct s_cylinder{
	t_vec3	origin;
}	t_cylinder;

t_cylinder	*cylinder_new(t_vec3 origin, t_vec3 normal);
void		cylinder_free(void *cylinder);

#endif
