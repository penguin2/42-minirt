/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_box.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:06:46 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/11 12:42:46 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_BOX_H
# define MATERIAL_BOX_H

# include "material.h"
# include <stddef.h>

# define MATERIAL_BOX_SIZE (3)

typedef struct s_material_box{
	t_material	materials[MATERIAL_BOX_SIZE];
	size_t		next_idx;
}	t_material_box;

int	material_box_init(t_material_box *material_box);
int	material_box_swap(t_material_box *material_box, t_material *target);

#endif
