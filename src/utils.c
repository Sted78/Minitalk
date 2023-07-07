/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:56:26 by svanmarc          #+#    #+#             */
/*   Updated: 2023/07/07 17:23:02 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_error(const char *error_message)
{
	ft_printf("Error : %s\n", error_message);
	exit(EXIT_FAILURE);
}

char	*realloc_memory(char *dest, int size)
{
	char	*tmp;
	int		len;

	len = ft_strlen(dest);
	tmp = malloc(len + size + 1);
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, dest, (len + 1));
	free(dest);
	return (tmp);
}
