/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:45:49 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/30 17:26:49 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambient.h"

t_light	*ambient_light_new(double brightness)
{
	t_light	*new_light;

	new_light = light_new(ambient_new(brightness));
	new_light->get_color = ambient_get_color;
	new_light->free_ptr = ambient_free;
	new_light->get_id = ambient_get_id;
	return (new_light);
}
