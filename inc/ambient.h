/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:05:04 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/11 17:21:41 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_H
# define AMBIENT_H

# include "libcolor.h"

typedef struct s_ambient{
	double	brightness;
	t_color	color;
}	t_ambient;

t_ambient	*ambient_new(double brightness, t_color color);
void		ambient_free(void *ambient);

#endif
