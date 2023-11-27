/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:03:18 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/17 01:45:25 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPOT_H
# define SPOT_H

# include "libcolor.h"
# include "libvec3.h"
# include "light.h"

typedef struct s_spot{
	t_vec3	pos;
	double	brightness;
}	t_spot;

t_spot	*spot_new(t_vec3 pos, double brightness);
t_light	*spot_light_new(t_vec3 pos, double brightness);
t_color	spot_get_color(
			const t_light *light,
			const t_hit *hit,
			const t_vla *objects);
void	spot_free(void *spot);

#endif
