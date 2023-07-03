/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:29:33 by svanmarc          #+#    #+#             */
/*   Updated: 2023/02/20 10:55:45 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*supprime et libere la memoire de l'elem passe en parametre,
et de tous les elem qui suivent, a l'aide de del et free.
enfin, le pointeur initial dois etre mis a NULL
lst = adresse du pointeur vers 1 element
del = adresse de la fct permettant de supp le contenu de l'elem */

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*start;

	if (!lst || !del)
		return ;
	start = *lst;
	while (start)
	{
		tmp = start->next;
		del(start->content);
		free(start);
		start = tmp;
	}
	*lst = NULL;
}
