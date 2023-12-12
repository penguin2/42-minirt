/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_ppm_reader.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:12:21 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/06 20:05:01 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "generator.h"
#include "parse.h"

void	append_ppm_reader(
			t_vla *json_obj,
			const t_ppm_reader *ppm_reader,
			const char *key)
{
	t_json_node	*new_node;

	if (ppm_reader == NULL || ppm_reader->filename == NULL)
		return ;
	new_node = json_node_new(
			ft_strdup(key),
			add_double_quotes(ppm_reader->filename),
			NODE_VALUE);
	ft_vla_append(json_obj, new_node);
}
