/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:10:19 by svanmarc          #+#    #+#             */
/*   Updated: 2023/07/19 13:58:02 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_bit_verif;

void	send_bit(char c, pid_t pid)
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

void	handle_bit(char *str, pid_t pid)
{
	int	current_char;

	current_char = 0;
	while (str[current_char])
	{
		send_bit(str[current_char], pid);
		current_char++;
	}
	send_bit(0, pid);
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
	handle_bit(av[2], pid);
	while (1)
		sleep(1);
}
