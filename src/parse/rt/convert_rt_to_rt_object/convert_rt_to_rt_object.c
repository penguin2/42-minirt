/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rt_to_rt_object.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:51:45 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/09 16:51:59 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "define.h"
#include <stdbool.h>

int	convert_rt_to_rt_object(t_vla *rt_object, int fd)
{
	(void)fd;
	convert_rt_to_object_vla(rt_object, fd);
	if (check_rt_object_format(rt_object) == ERROR)
		return (ERROR);
	sort_rt_objects(rt_object);
	sort_rt_object_options(rt_object);
	if (check_rt_object_option_format(rt_object) == ERROR)
		return (ERROR);
	grouping_same_objects(rt_object);
	return (SUCCESS);
}
