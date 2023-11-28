/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:27:51 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/29 01:48:56 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define SUCCESS	(0)
# define ERROR		(-1)

# define WDW_WIDTH	(800)
# define WDW_HEIGHT	(450)

# define NAME		("miniRT")

# define PI			(3.141592653589793238)
# define DIV_PI		(0.3183098861837907)
# define DEG_TO_RAD	(0.017453292519943295)

# define BUFFER_SIZE	(100)

# define CHECKERBOARD_SIZE_PLANE		(100)
# define CHECKERBOARD_FREQUENCY_CYCLE	(6)

# ifndef MODE
#  define MODE 0
# endif

# define MODE_MANDATORY 0
# define MODE_BONUS 1
# define MODE_JSON 2
# define MODE_SCENE 3

#endif
