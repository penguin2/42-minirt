/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:50:03 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/25 22:14:00 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ppm_reader.h"
#include <stdlib.h>

void	object_free(void *object)
{
	const t_object	*obj = object;

	obj->free_ptr(obj->ptr);
	ppm_reader_free(obj->texture_map);
	ppm_reader_free(obj->bump_map);
	free(object);
}
