/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_input_alphabet.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:47:52 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/09 13:38:20 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "mlx_command_mode.h"
#include <X11/keysym.h>
#include <stdbool.h>

static int	_to_upper_with_shift(int c, bool is_shift_pressed)
{
	if (is_shift_pressed)
		return (c - ('a' - 'A'));
	else
		return (c);
}

static int	_hook_fn_input_a_to_j(t_mlx_ptr *mlx_ptr, int keycode)
{
	const bool	is_shift = mlx_ptr->is_shift_pressed;

	if (keycode == XK_a)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('a', is_shift));
	else if (keycode == XK_b)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('b', is_shift));
	else if (keycode == XK_c)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('c', is_shift));
	else if (keycode == XK_d)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('d', is_shift));
	else if (keycode == XK_e)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('e', is_shift));
	else if (keycode == XK_f)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('f', is_shift));
	else if (keycode == XK_g)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('g', is_shift));
	else if (keycode == XK_h)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('h', is_shift));
	else if (keycode == XK_i)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('i', is_shift));
	else if (keycode == XK_j)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('j', is_shift));
	else
		return (ERROR);
	return (SUCCESS);
}

static int	_hook_fn_input_k_to_t(t_mlx_ptr *mlx_ptr, int keycode)
{
	const bool	is_shift = mlx_ptr->is_shift_pressed;

	if (keycode == XK_k)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('k', is_shift));
	else if (keycode == XK_l)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('l', is_shift));
	else if (keycode == XK_m)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('m', is_shift));
	else if (keycode == XK_n)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('n', is_shift));
	else if (keycode == XK_o)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('o', is_shift));
	else if (keycode == XK_p)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('p', is_shift));
	else if (keycode == XK_q)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('q', is_shift));
	else if (keycode == XK_r)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('r', is_shift));
	else if (keycode == XK_s)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('s', is_shift));
	else if (keycode == XK_t)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('t', is_shift));
	else
		return (ERROR);
	return (SUCCESS);
}

static int	_hook_fn_input_u_to_z(t_mlx_ptr *mlx_ptr, int keycode)
{
	const bool	is_shift = mlx_ptr->is_shift_pressed;

	if (keycode == XK_u)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('u', is_shift));
	else if (keycode == XK_v)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('v', is_shift));
	else if (keycode == XK_w)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('w', is_shift));
	else if (keycode == XK_x)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('x', is_shift));
	else if (keycode == XK_y)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('y', is_shift));
	else if (keycode == XK_z)
		mlx_buffer_write(mlx_ptr->buffer, _to_upper_with_shift('z', is_shift));
	else
		return (ERROR);
	return (SUCCESS);
}

void	hook_fn_input_alphabet(t_mlx_ptr *mlx_ptr, int keycode)
{
	if (_hook_fn_input_a_to_j(mlx_ptr, keycode) == SUCCESS
		|| _hook_fn_input_k_to_t(mlx_ptr, keycode) == SUCCESS
		|| _hook_fn_input_u_to_z(mlx_ptr, keycode) == SUCCESS)
		mlx_putcmd(mlx_ptr, mlx_ptr->buffer, COLOR_YELLOW, SUCCESS);
}
