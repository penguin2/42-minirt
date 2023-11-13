/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:30:47 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/13 20:19:05 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambient.h"
#include "libft.h"

t_ambient	*ambient_new(double brightness)
{
	t_ambient	*new;

	new = ft_xcalloc(1, sizeof(t_ambient));
	new->brightness = brightness;
	return (new);
}
