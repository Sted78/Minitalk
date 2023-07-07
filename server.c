/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:21:11 by svanmarc          #+#    #+#             */
/*   Updated: 2023/07/07 16:19:26 by svanmarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_error(const char *error_message)
{
	ft_printf("Error : %s\n", error_message);
	exit(EXIT_FAILURE);
}

char    *realloc_memory(char *dest, int size)
{
        char    *tmp;
        int             len;

        len = ft_strlen(dest);
        tmp = malloc(len + size + 1);
        if (!tmp)
                return (NULL);
        ft_memcpy(tmp, dest, (len + 1));
        free(dest);
        return (tmp);
}

void 	check_bit(char **message, int *bit, int *len, int *message_complete) 
 {
	if (*bit < 0)
    	{
        	if ((*message)[*len] == '\0')
		{        
            		ft_printf("%s\n", *message);
            		free(*message);
            		*message = NULL;
            		*len = 0;
            		*message_complete = 1;
		}
        	else
        	{
            	(*len)++;
            	*message = realloc_memory(*message, (*len + 1) * sizeof(char));
            	if (*message == NULL)
                	handle_error("Failed to allocate memory");
           	 (*message)[*len] = '\0';
       		}
	}
        *bit = 7;
}

int	handle_bit(char **message, int bit, int sig)
{
	static int	len = 0;
	int		message_complete;
	
	message_complete = 0;
	if (sig == SIGUSR1)
		(*message)[len] = (*message)[len] | (1 << bit);
	else if (sig == SIGUSR2)
		(*message)[len] = (*message)[len] & ~(1 << bit);
	bit--;
	check_bit(message, &bit, &len, &message_complete);
	return (message_complete);
}

void	handler_sig(int sig, siginfo_t *info, void *ucontext)
{
	static char	*message = NULL;
	static int	bit = -1;
	int	message_complete;

	(void)ucontext;
	if (kill(info->si_pid, 0) < 0)
		handle_error("can't send signal to PID");
	if (bit < 0 && message == NULL)
	{
		ft_printf("Client sent : ");
		message = ft_calloc(1, 1);
		if (message == NULL)
			handle_error("Failed to allocate memory");
		message[0] = '\0';
	}
	if (bit < 0)
		bit = 7;
	message_complete = handle_bit(&message, bit, sig);
	bit--;
	if (message_complete)
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
	ft_printf("and the boys are funny...\nPID : %d\n", pid);
	while (1)
		sleep (1);
}
