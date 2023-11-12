/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rt_to_rt_object.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:51:45 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/12 21:35:06 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "define.h"
#include <stdbool.h>

int	convert_rt_to_rt_object(t_vla *rt_object, int fd)
{
	convert_rt_to_object_vla(rt_object, fd);
	if (check_rt_object_format(rt_object) == ERROR)
		return (ERROR);
	sort_rt_objects(rt_object);
	grouping_same_objects(rt_object);
	return (SUCCESS);
}
