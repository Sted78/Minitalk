/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:24:35 by svanmarc          #+#    #+#             */
/*   Updated: 2023/07/02 18:38:32 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_sig(int sig, siginfo_t *info, void *ucontext)
{
	static char	c = 0;
	static int	bit = -1;

	(void)ucontext;
	if (kill(info->si_pid, 0) < 0)
	{
		ft_printf("looks like something has fucked up somewhere\n");
		ft_printf("ERROR : can't send signal to PID : %d\n", info->si_pid);
		exit(EXIT_FAILURE);
	}
	if (bit < 0 && !c)
		ft_printf("\n\nClient sent : ");
	if (bit < 0)
		bit = 7;
	if (sig == SIGUSR1)
		c = c | (1 << bit);
	else if (sig == SIGUSR2)
		c = c & ~(1 << bit);
	if (!bit && c)
		ft_putchar(c);
	else if (!bit && !c)
		kill(info->si_pid, SIGUSR2);
	bit--;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_sigaction = handler_sig;
	sa.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Take me down to the paradise city, where the grass is ");
	ft_printf("green and the boys are funny...\nPID : %d\n", pid);
	while (1)
	{
		sleep(1);
	}
}
