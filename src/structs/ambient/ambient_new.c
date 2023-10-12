/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:30:47 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/12 16:31:23 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambient.h"

t_ambient	*ambient_new(double brightness, t_color color)
{
	t_ambient	*new;

	new->brightness = brightness;
	new->color = color;
	return (new);
}
