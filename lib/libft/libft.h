/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:06:49 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/28 23:10:46 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdbool.h>

# define ERR_VLA_APPEND "Error: VLA allowances have been exceeded"

# define SPACE_CHARSETS "\t\n\r\v\f "
# define NUMBER_CHARSETS "0123456789"

typedef struct s_vla
{
	void	**array;
	size_t	size;
	size_t	capacity;
}	t_vla;

int			ft_isdigit(int c);
bool		ft_is_equal_str(const char *s1, const char *s2);
bool		ft_is_equal_str_n(const char *s1, const char *s2, size_t n);

size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
char		*ft_strcat(char *dst, const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strstr(const char *text, const char *pattern);
char		*ft_strrstr(const char *text, const char *pattern);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_strcmp(const char *s1, const char *s2);

size_t		ft_count_digit(long long int n);
int			ft_atoi(const char *nptr);
double		ft_atof(const char *str);
char		*ft_lltoa(long long int n);
char		*ft_ftoa(double number, size_t limit);

char		**ft_split(const char *str, const char *delimiter);
char		**ft_split_keeping_delimiters(const char *str, const char *set);
const char	*ft_skip_charsets(const char *str, const char *charsets);
const char	*ft_skip_non_charsets(const char *str, const char *charsets);
void		ft_free_strings(void *ptr);
size_t		ft_strings_len(char **strings);

void		*ft_calloc(size_t count, size_t size);
void		*ft_xcalloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_strndup(const char *str, size_t n);

void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putendl_fd(const char *s, int fd);

void		ft_vla_init(t_vla *vla);
t_vla		*ft_vla_new(void);
void		ft_vla_free(t_vla *vla, void free_content(void *content));
void		ft_vla_append(t_vla *vla, void *content);
void		*ft_vla_pop(t_vla *vla, size_t idx);

void		ft_sort(void **array, size_t size,
				bool (*cmp)(const void *, const void *));

#endif
