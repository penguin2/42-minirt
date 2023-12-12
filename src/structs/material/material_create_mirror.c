/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_create_mirror.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:29:48 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/12 17:58:56 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "material_parameter.h"

t_material	material_create_mirror(void)
{
	t_material	new;

	new.k_ambient = MATERIAL_AMBIENT_MIRROR;
	new.k_diffuse = MATERIAL_DIFFUSE_MIRROR;
	new.k_specular = MATERIAL_SPECULAR_MIRROR;
	new.k_shininess = MATERIAL_SHININESS_MIRROR;
	new.is_reflective = MATERIAL_IS_REFLECTIVE_MIRROR;
	new.k_reflect = MATERIAL_REFLECT_MIRROR;
	return (new);
}
