/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:28:16 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/13 20:19:51 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"
#include "libft.h"
#include "libvec3.h"
#include "spot.h"

t_spot	*spot_new(t_vec3 pos, double brightness)
{
	t_spot	*new;

	new = ft_xcalloc(1, sizeof(t_spot));
	new->pos = pos;
	new->brightness = brightness;
	return (new);
}
