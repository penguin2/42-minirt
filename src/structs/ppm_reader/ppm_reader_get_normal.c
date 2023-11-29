/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_reader_get_normal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:04:33 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/29 19:45:34 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ppm_reader.h"

static double	_convert_8bit_to_double(int x);

t_vec3	ppm_reader_get_normal(const t_ppm_reader *reader, double u, double v)
{
	const int	height = (int)(u * (reader->height - 1) + 0.5);
	const int	width = (int)(v * (reader->width - 1) + 0.5);
	const int	idx = PPM_P6_BYTES_PER_COLOR * (height * reader->width + width);

	return (vec3_unit(vec3_create(
				_convert_8bit_to_double(reader->data[idx]),
				_convert_8bit_to_double(reader->data[idx + 1]),
				_convert_8bit_to_double(reader->data[idx + 2]))));
}

static double	_convert_8bit_to_double(int x)
{
	x -= 128;
	if (x < 0)
		return ((double)x / 128);
	return ((double)x / 127);
}
