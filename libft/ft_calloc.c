/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <svanmarc@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 08:21:44 by svanmarc          #+#    #+#             */
/*   Updated: 2023/02/13 16:45:26 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*alloue un block de memoire en initialisant 
tous les octets a 0.
count = specifie le nbr d'elements consecutifs
a reserver ds le block
size = fixe la taille en nbr d'oct d'1 element
si count ou size sont nuls ils sont definis a 1 pour eviter
une division par 0
ensuite on verifie que count * size est > a la taille allouee
si oui -> null sinon -> malloc
si la memoire ne peut etre allouee -> null
memset pour initialiser a 0
return le pointeur sur la memoire allouee et initialisee*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*pnt;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (count > (count * size) / size)
		return (NULL);
	pnt = malloc(count * size);
	if (pnt == NULL)
		return (NULL);
	ft_memset((unsigned char *)pnt, 0, count * size);
	return (pnt);
}
