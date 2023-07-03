/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <svanmarc@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:23:08 by svanmarc          #+#    #+#             */
/*   Updated: 2023/02/13 16:57:05 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*duplique 1 string
src = adresse du string a dupliquer
alloue une nouvelle zone de memoire avec malloc afin
d'y copier la chaine initiale
on ajoute le \0 a la fin car strlen ne le prends pas en compte*/

char	*ft_strdup(const char *src)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(*src) * ft_strlen(src) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
