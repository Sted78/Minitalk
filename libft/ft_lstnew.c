/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:44:15 by svanmarc          #+#    #+#             */
/*   Updated: 2023/02/14 13:48:51 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*alloue de la memoire pour un nveau maillon du string
et initialise ses champs avec la valeur passee en arg.
l'arg content est un pointeur vers un objet qui sera stocke
dans le nveau maillon
si l'allocation mem reussie, initialise les champs du nouveau maillon
(pointer variable)->(variable) = value;
la variable membre content est initialisee a l'aide de la valeur
du param content
la variable next est initialisee a NULL*/

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
