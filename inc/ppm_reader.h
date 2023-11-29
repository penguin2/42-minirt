/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_reader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:05:21 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/29 19:35:39 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PPM_READER_H
# define PPM_READER_H

# include "libcolor.h"
# include "libvec3.h"

# define PPM_P6_COMMENT_STR ("#")
# define PPM_P6_FORMAT_STR ("P6")
# define PPM_P6_SPACE_STR (" ")
# define PPM_P6_MAX_COLOR_VALUE_STR ("255")
# define PPM_P6_BYTES_PER_COLOR (3)

typedef struct s_ppm_reader{
	unsigned char	*data;
	int				width;
	int				height;
}	t_ppm_reader;

t_ppm_reader	*ppm_reader_new(const char *filename);
void			ppm_reader_free(t_ppm_reader *ppm_reader);
char			*ppm_reader_get_next_line(int fd);
int				ppm_reader_check_header(t_ppm_reader *new, int fd);

t_color			ppm_reader_get_color(
					const t_ppm_reader *reader, double u, double v);
t_vec3			ppm_reader_get_normal(
					const t_ppm_reader *reader, double u, double v);

#endif
