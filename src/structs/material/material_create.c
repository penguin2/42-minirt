/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:34:03 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/14 18:20:10 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

t_material	material_create(void)
{
	t_material	new;

	new.k_ambient = K_AMBIENT_DEFAULT;
	new.k_diffuse = K_DIFFUSE_DEFAULT;
	new.k_specular = K_SPECULAR_DEFAULT;
	new.k_shininess = K_SHININESS_DEFAULT;
	new.k_reflect = K_REFLECT_DEFAULT;
	new.is_reflective = IS_REFLECTIVE_DEFAULT;
	return (new);
}
