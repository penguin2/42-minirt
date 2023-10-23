/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_json_to_json_object.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:42:21 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/23 16:20:34 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"

t_vla	*convert_json_to_json_object(const char *file)
{
	t_vla	*token;
	t_vla	*json_object;

	token = convert_json_to_token(file);
	if (token == NULL)
		return (NULL);
	json_object = convert_token_to_json_object(token);
	return (json_object);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main(int argc, char **argv)
// {
// 	t_vla		*json_object;

// 	if (argc != 3) {
// 		printf("argc != 3\n");
// 		return (EXIT_FAILURE);
// 	}
// 	json_object = convert_json_to_json_object(argv[1]);
// 	if (json_object == NULL) {
// 		return (atoi(argv[2]) == 0);
// 	}
// 	else {
// 		json_generator(json_object, 1);
// 		return (atoi(argv[2]) == 1);
// 	}
// }
