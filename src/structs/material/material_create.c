/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:34:03 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/11 13:39:03 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

t_material	material_create(void)
{
	t_material	new;

	new.k_ambient = MATERIAL_AMBIENT_DEFAULT;
	new.k_diffuse = MATERIAL_DIFFUSE_DEFAULT;
	new.k_specular = MATERIAL_SPECULAR_DEFAULT;
	new.k_shininess = MATERIAL_SHININESS_DEFAULT;
	new.is_reflective = MATERIAL_IS_REFLECTIVE_DEFAULT;
	new.k_reflect = MATERIAL_REFLECT_DEFAULT;
	return (new);
}
