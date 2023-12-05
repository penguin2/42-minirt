/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_helper_init_key_press_cmd_mode.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:53:59 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/05 17:44:20 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_command_mode.h"
#include "mlx_hook_helper.h"
#include <X11/keysym.h>

static t_hook	*_mlx_set_helper_init_input_a_to_w(t_hook *hooks_kp_cmd)
{
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_a, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_b, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_c, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_d, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_e, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_f, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_g, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_h, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_i, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_j, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_k, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_l, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_m, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_n, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_o, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_p, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_q, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_r, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_s, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_t, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_u, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_v, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_w, hook_fn_input_alphabet);
	return (hooks_kp_cmd);
}

static t_hook	*_mlx_set_helper_init_input_alphabet(t_hook *hooks_kp_cmd)
{
	hooks_kp_cmd = _mlx_set_helper_init_input_a_to_w(hooks_kp_cmd);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_x, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_y, hook_fn_input_alphabet);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_z, hook_fn_input_alphabet);
	return (hooks_kp_cmd);
}

static t_hook	*_mlx_set_helper_init_input_digit(t_hook *hooks_kp_cmd)
{
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_1, hook_fn_input_digit);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_2, hook_fn_input_digit);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_3, hook_fn_input_digit);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_4, hook_fn_input_digit);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_5, hook_fn_input_digit);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_6, hook_fn_input_digit);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_7, hook_fn_input_digit);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_8, hook_fn_input_digit);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_9, hook_fn_input_digit);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_0, hook_fn_input_digit);
	return (hooks_kp_cmd);
}

static t_hook	*_mlx_set_helper_init_input_sp_char(t_hook *hooks_kp_cmd)
{
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_space, hook_fn_input_sp_char);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_comma, hook_fn_input_sp_char);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_period, hook_fn_input_sp_char);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_minus, hook_fn_input_sp_char);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_slash, hook_fn_input_sp_char);
	return (hooks_kp_cmd);
}

void	mlx_hook_helper_init_key_press_cmd_mode(t_hook *hooks_kp_cmd)
{
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_Shift_L, hook_fn_set_shift_on);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_Shift_R, hook_fn_set_shift_on);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_Escape, hook_fn_exit_cmd_mode);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_BackSpace, hook_fn_delete);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_Delete, hook_fn_delete);
	mlx_hook_helper_set_hook(hooks_kp_cmd++, XK_Return, hook_fn_return);
	hooks_kp_cmd = _mlx_set_helper_init_input_alphabet(hooks_kp_cmd);
	hooks_kp_cmd = _mlx_set_helper_init_input_digit(hooks_kp_cmd);
	hooks_kp_cmd = _mlx_set_helper_init_input_sp_char(hooks_kp_cmd);
}
