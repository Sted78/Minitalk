/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:17:41 by svanmarc          #+#    #+#             */
/*   Updated: 2023/02/14 11:19:46 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*applique la fct f a chaque caractere de la string transmise en arg
et en passant son index comme 1er arg.
chaque arg est transmis a f pour etre modif if needed*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = -1;
	if (s && f)
	{
		while (s[++i])
			f(i, (s + i));
	}
}
