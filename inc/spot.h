/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:03:18 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/11 17:20:59 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPOT_H
# define SPOT_H

# include "libcolor.h"
# include "libvec3.h"

typedef struct s_spot{
	t_vec3	pos;
	double	brightness;
	t_color	color;
}	t_spot;

t_spot	*spot_new(t_vec3 pos, double brightness, t_color color);
void	spot_free(void *spot);

#endif
