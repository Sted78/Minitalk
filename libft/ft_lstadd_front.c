/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:04:34 by svanmarc          #+#    #+#             */
/*   Updated: 2023/02/14 13:56:17 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*ajoute l'element new au debut de la liste
lst = l'adresse du pointeur vers le 1er elem de la liste
new = adresse du pointeur de l'elem a rajouter a la liste
next = adresse du maillon suivant de la liste ou NUll si maillon
suivant est le dernier.
(pointer variable)->(variable) = value;*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
