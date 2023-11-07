/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcolor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:18:36 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/05 16:37:49 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCOLOR_H
# define LIBCOLOR_H

typedef struct s_color
{
	double	red;
	double	green;
	double	blue;
}	t_color;

t_color	color_add(t_color color1, t_color color2);
t_color	color_create(double red, double green, double blue);
int		color_cast(t_color color);
t_color	color_mul(t_color color, double scalar);
t_color	color_composite(t_color color1, t_color color2);

t_color	color_black(void);
t_color	color_white(void);

#endif
