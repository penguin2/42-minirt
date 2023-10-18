/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:28:16 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/12 16:29:47 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"
#include "libft.h"
#include "libvec3.h"
#include "spot.h"

t_spot	*spot_new(t_vec3 pos, double brightness, t_color color)
{
	t_spot	*new;

	new = ft_xcalloc(1, sizeof(t_spot));
	new->pos = pos;
	new->brightness = brightness;
	new->color = color;
	return (new);
}
