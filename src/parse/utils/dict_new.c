/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:20:28 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 14:36:07 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_dict	*dict_new(const char *key, void *value)
{
	t_dict	*dict;

	dict = (t_dict *)ft_xcalloc(1, sizeof(t_dict));
	dict->key = ft_strdup(key);
	dict->value = value;
	return (dict);
}
