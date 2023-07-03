/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:47:46 by svanmarc          #+#    #+#             */
/*   Updated: 2023/02/20 14:42:56 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*convertit un entier en une chaîne de caractères.
 * Elle utilise une fonction utilitaire ft_intlen pour calculer
 * la longueur de l'entier en chiffres, alloue ensuite la mémoire
 * nécessaire pour la chaîne de caractères de sortie,
 * remplit la chaîne de caractères en partant de la fin
 * en utilisant l'opérateur % pour extraire les chiffres
 * un par un, et ajoute le signe '-' si l'entier est négatif.
 * La fonction retourne un pointeur vers la chaîne de caractères convertie.*/

static int	ft_intlen(int n)
{
	int		len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	len = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = '0' + (n % 10) * sign;
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
