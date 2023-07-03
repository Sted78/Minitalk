/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:24:49 by svanmarc          #+#    #+#             */
/*   Updated: 2023/02/13 11:50:46 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*copier un block memoire src a l'adresse de dest
(en cas de chevauchement des 2 zones memoire, preferer ft_memmove)*/

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;
	size_t			i;

	if (!dest && !src)
		return (0);
	new_dest = dest;
	new_src = (unsigned char *)src;
	i = 0;
	while (i++ < len)
		*new_dest++ = *new_src++;
	return (dest);
}
