/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:43:31 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/01 20:08:12 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "libcolor.h"

typedef struct s_material{
	double	k_ambient;
	double	k_diffuse;
	double	k_specular;
	double	shininess;
	t_color	color;
}	t_material;

t_material	material_create(
				double k_ambient,
				double k_diffuse,
				double k_specular,
				double shininess
				);

#endif
