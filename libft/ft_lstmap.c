/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:52:58 by svanmarc          #+#    #+#             */
/*   Updated: 2023/02/14 15:53:46 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*crée une nouvelle liste chainée à partir d'une liste d'origine
en appliquant 1 fct f à chaque élément.
vérifie que les arg lst, f, et del ne sont pas nuls,
crée un nouvel élément de liste out avec ft_lstnew(NULL).
vérifie que l'allocation de mémoire a réussi,
crée un pointeur elem pour parcourir la nouvelle liste.
parcourt ensuite la liste d'origine lst en appliquant
la fonction f à chaque élément et en stockant le résultat
dans l'élément correspondant de la nouvelle liste.
Si l'élément de la liste d'origine n'est pas le dernier,
un nouvel élément de liste elem->next est créé avec ft_lstnew(NULL),
et la mémoire est libérée si l'allocation de mémoire échoue.
Enfin, elem et lst sont avancés pour passer à l'élément suivant,
et la nvelle liste out est retournée à la fin de la fct.*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	t_list	*elem;

	if (!lst || !f || !del)
		return (NULL);
	out = ft_lstnew(NULL);
	if (!out)
		return (NULL);
	elem = out;
	while (lst)
	{
		elem->content = (*f)(lst->content);
		if (lst->next)
		{
			elem->next = ft_lstnew(NULL);
			if (!elem->next)
			{
				ft_lstclear(&out, del);
				return (NULL);
			}
			elem = elem->next;
		}
		lst = lst->next;
	}
	return (out);
}
