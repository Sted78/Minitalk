/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:24:40 by svanmarc          #+#    #+#             */
/*   Updated: 2023/02/14 14:47:40 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*libere la memoire de l'elem passe en arg en utilisant
la fct del puis avec free
la memoire de next ne dois pas etre free
lst = elem a free
del = adresse de la fct permettant de sup le contenu de l'elem
content = donnee contenue dans le maillon*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
	lst = NULL;
}
