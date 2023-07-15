/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:10:19 by svanmarc          #+#    #+#             */
/*   Updated: 2023/07/15 10:26:59 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_bit_verif;

void	send_bit(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (kill(pid, 0) < 0)
			handle_error("Error, can't send signal to server");
		g_bit_verif = 0;
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		while (g_bit_verif != 1)
			usleep(10);
	}
}

void	handle_char(pid_t pid, char *str)
{
	int	current_char;

	current_char = 0;
	while (str[current_char])
	{
		send_bit(pid, str[current_char]);
		current_char++;
	}
	send_bit(pid, 0);
}

void	handle_sig(int sig)
{
	if (sig == SIGUSR1)
		g_bit_verif = 1;
	else if (sig == SIGUSR2)
	{
		ft_printf("📬 delivered\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	sa;

	if (ac != 3)
		handle_error("Try this noob: ./client <pid> <string to send>\n");
	sa.sa_handler = handle_sig;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = ft_atoi(av[1]);
	if (!pid)
		handle_error("seems something weird happened with the pid");
	handle_char(pid, av[2]);
	while (1)
		sleep(1);
	return (0);
}
