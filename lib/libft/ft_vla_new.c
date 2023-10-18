/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vla_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:48:45 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/18 15:50:25 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vla	*ft_vla_new(void)
{
	t_vla	*vla;

	vla = (t_vla *)ft_xcalloc(1, sizeof(t_vla));
	ft_vla_init(vla);
	return (vla);
}
