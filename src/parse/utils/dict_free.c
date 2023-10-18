/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:23:25 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/18 20:25:48 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdlib.h>

void	dict_free(t_dict *dict, void (free_value)(void *))
{
	if (dict->key != NULL)
		free(dict->key);
	if (dict->value != NULL)
		free_value(dict->value);
	free(dict);
}
