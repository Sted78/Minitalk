/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:21:11 by svanmarc          #+#    #+#             */
/*   Updated: 2023/07/15 09:05:56 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_message_complete;

void	first_msg(char **message)
{
	ft_printf("Client sent : ");
	*message = ft_calloc(1, 1);
	if (*message == NULL)
		handle_error("Failed to allocate memory");
	(*message)[0] = '\0';
}

void	handle_char(char *message, int *len)
{
	if (message[*len] == '\0')
	{
		ft_printf("%s\n", message);
		free(message);
		*len = 0;
		g_message_complete = 1;
	}
	else
	{
		message = realloc_memory(message, (*len)  * sizeof(char));
		if (message == NULL)
			handle_error("Failed to allocate memory");
		(*len)++;
		message[*len] = '\0';
	}
}

void	handle_bit(char *message, int bit, int len, int sig)
{
	if (sig == SIGUSR1)
		message[len] = message[len] | (1 << bit);
	else if (sig == SIGUSR2)
		message[len] = message[len] & ~(1 << bit);
}

void	handler_sig(int sig, siginfo_t *info, void *ucontext)
{
	static char *message = NULL;
	static int bit = -1;
	static int len = 0;
	
	(void)ucontext;
	if (kill(info->si_pid, 0) < 0)
		handle_error("Can't send signal to PID");
	if (bit < 0 )
	{
		if (message == NULL)
			first_msg(&message);
		else
			handle_char(message, &len);
		bit = 7;
	}
	handle_bit(message, bit, len, sig);
	bit--;
	if (g_message_complete)
		kill(info->si_pid, SIGUSR2);
	else
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
		sleep(1);
}
