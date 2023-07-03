/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:16:09 by svanmarc          #+#    #+#             */
/*   Updated: 2023/02/21 08:52:17 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*ajoute l'elem new a la fin de la liste
lst = adresse du pointeur vers le 1er elem de la liste
new = adresse du pointeur vers l'elem a rajouter
next = adresse du maillon suivant de la liste ou NUll si maillon
suivant est le dernier.*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*elem;

	if (lst && *lst)
	{
		elem = *lst;
		elem = ft_lstlast(*lst);
		elem->next = new;
		return ;
	}
	*lst = new;
}
