/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:05:04 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/30 16:13:23 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_H
# define AMBIENT_H

# include "hit.h"
# include "libcolor.h"
# include "libft.h"
# include "light.h"

typedef struct s_ambient{
	double	brightness;
}	t_ambient;

t_ambient	*ambient_new(double brightness);
t_light		*ambient_light_new(double brightness);
t_color		ambient_get_color(
				const t_light *light,
				const t_hit *hit,
				const t_vla *objects);
t_light_id	ambient_get_id(void);
void		ambient_free(void *ambient);

#endif
