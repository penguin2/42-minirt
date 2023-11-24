/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_reader_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:00:18 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/24 21:01:14 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ppm_reader.h"
#include <stdlib.h>

void	ppm_reader_free(t_ppm_reader *ppm_reader)
{
	if (ppm_reader == NULL)
		return ;
	free(ppm_reader->data);
	free(ppm_reader);
}
