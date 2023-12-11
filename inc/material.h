/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:43:31 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/11 13:57:44 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include <stdbool.h>

# define MATERIAL_AMBIENT_DEFAULT (0.1)
# define MATERIAL_DIFFUSE_DEFAULT (0.5)
# define MATERIAL_SPECULAR_DEFAULT (0.5)
# define MATERIAL_SHININESS_DEFAULT (8.0)
# define MATERIAL_IS_REFLECTIVE_DEFAULT (0)
# define MATERIAL_REFLECT_DEFAULT (0.0)

# define MATERIAL_AMBIENT_METAL (0.2)
# define MATERIAL_DIFFUSE_METAL (0.8)
# define MATERIAL_SPECULAR_METAL (0.8)
# define MATERIAL_SHININESS_METAL (16.0)
# define MATERIAL_IS_REFLECTIVE_METAL (0)
# define MATERIAL_REFLECT_METAL (0.0)

# define MATERIAL_AMBIENT_PLASTIC (0.2)
# define MATERIAL_DIFFUSE_PLASTIC (0.8)
# define MATERIAL_SPECULAR_PLASTIC (0.1)
# define MATERIAL_SHININESS_PLASTIC (2.0)
# define MATERIAL_IS_REFLECTIVE_PLASTIC (0)
# define MATERIAL_REFLECT_PLASTIC (0.0)

# define MATERIAL_AMBIENT_GLASS (0.2)
# define MATERIAL_DIFFUSE_GLASS (0.3)
# define MATERIAL_SPECULAR_GLASS (0.8)
# define MATERIAL_SHININESS_GLASS (16.0)
# define MATERIAL_IS_REFLECTIVE_GLASS (1)
# define MATERIAL_REFLECT_GLASS (0.7)

typedef struct s_material{
	double	k_ambient;
	double	k_diffuse;
	double	k_specular;
	double	k_shininess;
	bool	is_reflective;
	double	k_reflect;
}	t_material;

t_material	material_create(void);
t_material	material_create_metal(void);
t_material	material_create_glass(void);
t_material	material_create_plastic(void);

#endif
