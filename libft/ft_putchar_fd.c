/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:38:18 by svanmarc          #+#    #+#             */
/*   Updated: 2023/02/14 11:23:42 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*ecrit le char c sur le descripteur de fichier donne fd*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
