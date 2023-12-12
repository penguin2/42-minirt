/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_reader_get_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:32:13 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/27 10:01:13 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"
#include "ppm_reader.h"

t_color	ppm_reader_get_color(const t_ppm_reader *reader, double u, double v)
{
	const int	height = (int)(u * (reader->height - 1) + 0.5);
	const int	width = (int)(v * (reader->width - 1) + 0.5);
	const int	idx = PPM_P6_BYTES_PER_COLOR * (height * reader->width + width);

	return (color_create_by_int(
			reader->data[idx],
			reader->data[idx + 1],
			reader->data[idx + 2]));
}
