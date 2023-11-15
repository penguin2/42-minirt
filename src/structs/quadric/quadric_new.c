/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 00:30:17 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/15 18:09:43 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quadric.h"

t_quadric	*quadric_new(
				t_vec3 center,
				double coeff_array[QUADRIC_COEFFICIENT_SIZE])
{
	t_quadric	*new;

	new = ft_xcalloc(1, sizeof(t_quadric));
	new->center = center;
	new->coeff_array[COEFF_A] = coeff_array[COEFF_A];
	new->coeff_array[COEFF_B] = coeff_array[COEFF_B];
	new->coeff_array[COEFF_C] = coeff_array[COEFF_C];
	new->coeff_array[COEFF_D] = coeff_array[COEFF_D];
	new->coeff_array[COEFF_E] = coeff_array[COEFF_E];
	return (new);
}
