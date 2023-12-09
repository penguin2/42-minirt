/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:51:08 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/08 20:59:35 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "object.h"
#include "light.h"
#include <stddef.h>

void	scene_free(t_scene *scene)
{
	ft_vla_free(&scene->objects, object_free);
	ft_vla_free(&scene->lights, light_free);
}
