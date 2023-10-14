/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_json_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:41:47 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/14 18:54:25 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "get_next_line.h"
#include <unistd.h>

int	check_json_format(int fd)
{
	char	*line;

	line = get_next_line(fd);
	return (SUCCESS);
}
