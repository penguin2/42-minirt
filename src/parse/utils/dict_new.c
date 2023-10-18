/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:20:28 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/18 20:23:04 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_dict	*dict_new(const char *key, void *value, int value_type)
{
	t_dict	*dict;

	dict = (t_dict *)ft_xcalloc(1, sizeof(t_dict));
	dict->key = ft_strdup(key);
	dict->value = value;
	dict->type = value_type;
	return (dict);
}
