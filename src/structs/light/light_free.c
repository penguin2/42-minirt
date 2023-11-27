/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:55:12 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/17 02:11:24 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include <stdlib.h>

void	light_free(void *_light)
{
	const t_light	*light = _light;

	light->free_ptr(light->ptr);
	free(_light);
}
