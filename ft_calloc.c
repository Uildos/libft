/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoares- <usoares-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 12:26:53 by usoares-          #+#    #+#             */
/*   Updated: 2020/05/22 12:27:02 by usoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t e_n, size_t e_size)
{
	size_t	size;
	void	*space_mem;

	size = e_n * e_size;
	space_mem = malloc(size);
	if (space_mem != 0)
		ft_memset(space_mem, 0, size);
	return (space_mem);
}
