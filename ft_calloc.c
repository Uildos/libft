# include "libft.h"

void *ft_calloc(size_t e_n, size_t e_size)
{
	size_t size;
	void *space_mem;

	size = e_n*e_size;
	space_mem = malloc(size);
	if (space_mem != 0)
		ft_memset(space_mem,0,size);
	return(space_mem);
}
