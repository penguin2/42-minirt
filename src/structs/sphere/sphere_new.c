/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:26:14 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/12 16:58:32 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sphere.h"

t_sphere	*sphere_new(t_vec3 center, double radius)
{
	t_sphere	*new;

	new = ft_xcalloc(1, sizeof(t_sphere));
	new->center = center;
	new->radius = radius;
	return (new);
}
