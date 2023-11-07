/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:43:23 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/05 17:08:54 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "hit.h"
# include "libcolor.h"
# include "libft.h"

typedef struct s_light	t_light;

typedef t_color			(*t_fn_get_color)(
							const t_light* light,
							const t_hit* hit,
							const t_vla* objects);
typedef void			(*t_fn_free_light)(void *light_ptr);

typedef struct s_light{
	void			*ptr;
	t_fn_get_color	get_color;
	t_fn_free_light	free_light;
}	t_light;

t_light	*light_new(
			void *ptr,
			t_fn_get_color get_color,
			t_fn_free_light free_light);
void	light_free(void *light);

#endif
