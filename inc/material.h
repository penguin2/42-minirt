/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:43:31 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/14 18:22:00 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include <stdbool.h>

# define K_AMBIENT_DEFAULT (1.0)
# define K_DIFFUSE_DEFAULT (1.0)
# define K_SPECULAR_DEFAULT (1.0)
# define K_SHININESS_DEFAULT (1.0)
# define K_REFLECT_DEFAULT (1.0)
# define IS_REFLECTIVE_DEFAULT (0)

typedef struct s_material{
	double	k_ambient;
	double	k_diffuse;
	double	k_specular;
	double	k_shininess;
	bool	is_reflective;
	double	k_reflect;
}	t_material;

t_material	material_create(void);

#endif
