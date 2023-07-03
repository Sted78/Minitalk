/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:41:15 by svanmarc          #+#    #+#             */
/*   Updated: 2023/02/14 15:34:13 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*applique f a chaque elem de lst en commencant par le 1er elem et en
se deplacant vers le dernier.
lst = adresse du pointeur vers 1 elem 
f = adresse de la fct
content = donnee contenue dans le maillon
next = adresse du maillon suivant ou NULL si celui ci est le dernier*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
