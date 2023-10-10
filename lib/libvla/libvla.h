#ifndef LIBVLA_H
# define LIBVLA_H

#include <stddef.h>

typedef struct s_vla
{
	void	**array;
	size_t	size;
	size_t	capacity;
}	t_vla;

void	vla_init(t_vla *vla);
void	vla_free(t_vla *vla, void free_content(void *content));
void	vla_append(t_vla *vla, void *content);

#endif
