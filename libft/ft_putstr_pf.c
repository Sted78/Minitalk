/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:17:33 by svanmarc          #+#    #+#             */
/*   Updated: 2023/06/26 13:47:12 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putstr_pf(char *str)
{
	if (!str)
		return (ft_putstr_pf("(null)"));
	return (write (1, str, ft_strlen(str)));
}
