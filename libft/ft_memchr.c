/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <svanmarc@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:51:33 by svanmarc          #+#    #+#             */
/*   Updated: 2023/02/13 16:11:49 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*recherche la 1ere occurence d'un int mais interpretee en tant que char,
dans un block memoire. comme on traite un block memoire et non pas
un string , nous devons aussi specifier a la fonction
la taille du block memoire dans lequel effectuer la recherche
*s = pointeur indiquqnt l'adresse du block memoire a utiliser
c = le code numerique de l'octet a rechercher ds le block
n = indique la taille du block mem ds lequel effectuer la recherche*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (0);
}
