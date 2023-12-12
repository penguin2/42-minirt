/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:12:16 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/27 10:06:12 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgnl.h"
#include "stdbool.h"

char	*reader_read(
			t_reader **preader,
			size_t *read_size,
			t_fn_set_string set_string)
{
	t_string	*string;
	char		*cstring;

	if (string_init(&string, 1) == -1)
		return (NULL);
	if (set_string(*preader, string) == -1)
	{
		string_free(&string);
		return (NULL);
	}
	cstring = string_to_cstring(string);
	if (read_size != NULL)
		*read_size = string->size;
	string_free(&string);
	return (cstring);
}
