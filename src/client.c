/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:10:19 by svanmarc          #+#    #+#             */
/*   Updated: 2023/07/02 18:37:42 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_bit_verif;

void	send_char(char c, pid_t pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (kill(pid, 0) < 0)
		{
			ft_printf("Error, can't send signal to server : ");
			exit(EXIT_FAILURE);
		}
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

void	send_str(char *str, pid_t pid)
{
	int	current_char;

	current_char = 0;
	while (str[current_char])
	{
		send_char(str[current_char], pid);
		current_char++;
	}
	send_char(0, pid);
}

void	handler_sig(int sig, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
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
	{
		ft_printf("You fucked up!!!\n");
		ft_printf("Try this noob: ./client <pid> <string to send>\n");
		exit(EXIT_FAILURE);
	}
	sa.sa_sigaction = handler_sig;
	sa.sa_flags = SA_RESTART | SA_NODEFER;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = ft_atoi(av[1]);
	if (!pid)
	{
		ft_printf("seems some weird shits happened with the pid");
		exit(EXIT_FAILURE);
	}
	send_str(av[2], pid);
	while (1)
		sleep(1);
}
