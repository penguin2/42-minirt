/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:55:12 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/12 16:56:47 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include <stdlib.h>

void	light_free(void *light)
{
	const t_light	*lgt = light;

	lgt->free_ptr(lgt->ptr);
	free(light);
}
