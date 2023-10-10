/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcolor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:18:36 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/10 19:19:07 by taekklee         ###   ########.fr       */
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

t_color			color_create(double red, double green, double blue);
unsigned int	color_cast(t_color color);

#endif
