/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:06:05 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/11 17:22:42 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include "libvec3.h"

typedef struct s_hit{
	t_vec3	pos;
	t_vec3	normal;
}	t_hit;

#endif
