/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:06:05 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/20 18:06:46 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "range.h"

t_range	range_create(double start, double end)
{
	t_range	new;

	new.start = start;
	new.end = end;
	return (new);
}
