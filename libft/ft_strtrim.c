/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <svanmarc@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:44:35 by svanmarc          #+#    #+#             */
/*   Updated: 2023/02/13 17:45:59 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*alloue avec malloc et return 1 copie de s1
sans les caracteres specifies dans set 
au debut et a la fin du string
s1 = chaine de caracteres a trimmer
set = set de reference de caracteres a trimmer
front = debut a 0
back = fin avec strlen(s)
incremente front jusqu'a sortir du set et fais la meme chose
dans l'autre sens avec back
alloue de la memoire pour str (back - front + 1)
*copie la sous chaine de s entre front et back dans str 
return str*/

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	front;
	size_t	back;
	char	*str;

	str = 0;
	if (s != 0 && set != 0)
	{
		front = 0;
		back = ft_strlen(s);
		while (s[front] && ft_strchr(set, s[front]))
			front++;
		while (s[back - 1] && ft_strchr(set, s[back - 1]) && back > front)
			back--;
		str = (char *)malloc(sizeof(char) * (back - front + 1));
		if (str)
			ft_strlcpy(str, &s[front], back - front + 1);
	}
	return (str);
}
