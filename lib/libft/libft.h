/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:06:49 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/10 21:46:09 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

# define ERR_VLA_APPEND "Error: VLA allowances have been exceeded"

typedef struct s_vla
{
	void	**array;
	size_t	size;
	size_t	capacity;
}	t_vla;

size_t	ft_strlen(const char *str);

void	*ft_calloc(size_t count, size_t size);
void	*ft_xcalloc(size_t count, size_t size);

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putendl_fd(const char *s, int fd);

void	ft_vla_init(t_vla *vla);
void	ft_vla_free(t_vla *vla, void free_content(void *content));
void	ft_vla_append(t_vla *vla, void *content);

#endif
