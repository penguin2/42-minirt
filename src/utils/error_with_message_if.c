/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_with_message_if.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:33:17 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/24 01:51:43 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "utils.h"

int	error_with_message_if(bool is_error, const char *err_msg)
{
	if (is_error)
	{
		print_error(err_msg);
		return (ERROR);
	}
	return (SUCCESS);
}
