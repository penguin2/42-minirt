/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 00:30:17 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/08 00:33:16 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quadric.h"

t_quadric	*quadric_new(
				t_vec3 center,
				t_vec3 coeff_quadratic,
				double coeff_z,
				double coeff_c)
{
	t_quadric	*new;

	new = ft_xcalloc(1, sizeof(t_quadric));
	new->center = center;
	new->coeff_quadratic = coeff_quadratic;
	new->coeff_z = coeff_z;
	new->coeff_c = coeff_c;
	return (new);
}
