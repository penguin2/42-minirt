/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot_light_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:47:36 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/17 01:48:26 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spot.h"

t_light	*spot_light_new(t_vec3 pos, double brightness)
{
	t_light	*new_light;

	new_light = light_new(spot_new(pos, brightness));
	new_light->get_color = spot_get_color;
	new_light->free_ptr = spot_free;
	return (new_light);
}
