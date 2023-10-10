/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:31:35 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/10 18:34:22 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"

t_color	color_create(double red, double green ,double blue)
{
	t_color	new;

	new.red = red;
	new.green = green;
	new.blue = blue;
	return (new);
}
