/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:31:12 by svanmarc          #+#    #+#             */
/*   Updated: 2023/02/13 11:21:24 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*remplir 1 zone memoire, identifiee par son adresse et sa taille,
avec une valeur precise.
s = adresse du block memoire a re-initialiser.
c = valeur utilisee pour remplir.
len = nb d'oct a initialiser
return l'adresse de la memoire reinitialisee (s)*/

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (len--)
		*ptr++ = (char)c;
	return (s);
}
