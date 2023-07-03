/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <svanmarc@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:31:21 by svanmarc          #+#    #+#             */
/*   Updated: 2023/02/13 16:13:21 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*permet de comparer les n 1ers caracteres de s1 et s2 et de savoir 
si s1 est < = ou > a s2.
la compâraison se fait en tenant compte des valeurs ascii
des dif caracteres.
si 2 string = return (0)
si s1 < s2 return valeur neg
si s1 > s2 return val pos
la valeur absolue indiquera la position du 1er caractere
permettant de produire le resultat*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((unsigned char)*s1 == (unsigned char)*s2 && *s1 && n-- > 1)
	{
		s1++;
		s2++;
	}
	if ((unsigned char)*s1 == (unsigned char)*s2)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
