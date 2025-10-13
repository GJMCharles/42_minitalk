/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:10:51 by grcharle          #+#    #+#             */
/*   Updated: 2025/09/29 22:11:07 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*get_text_size(unsigned int client_pid, int signum, unsigned int count, unsigned int *size)
{
	char	*text;

	if (signum == SIGUSR1)
		*size |= (1 << count);
	if (count == 31)
	{
		text = ft_calloc(sizeof(char), *size + 1);
		if (!text)
		{
			emit_signal(client_pid, 1, 1);
			error_found("Failed to allocate space with 'malloc'");
		}
		return (text);
	}
	return (0);
}

void	handle_action(int signum, siginfo_t *info, void *ucontext)
{
	static unsigned int		count;
	static char				*text;
	static unsigned int		size;
	static unsigned int		i;

	(void) ucontext;
	if (count < 32)
		text = get_text_size(info->si_pid, signum, count, &size);
	else
	{
		if (signum == SIGUSR1)
			text[(i / 8)] |= (1 << (i % 8));
		i += 1;
	}
	count += 1;
	if (count >= 32 && ((count - 32) / 8) == size)
	{
		ft_printf("client [%d]: %s\n", info->si_pid, text);
		free(text);
		count = 0;
		size = 0;
		i = 0;
		emit_signal(info->si_pid, 0, 1);
	}
}

void	init_server_signal(void)
{
	struct sigaction	s_server;

	if (sigemptyset(&s_server.sa_mask) != 0)
		error_found("sigemptyset failed to initialize");
	s_server.sa_flags = SA_SIGINFO;
	s_server.sa_sigaction = &handle_action;
	if (sigaction(SIGUSR1, &s_server, (void *)0) != 0)
		error_found("sigaction failed for SIGUSR1");
	if (sigaction(SIGUSR2, &s_server, (void *)0) != 0)
		error_found("sigaction failed for SIGUSR2");
}

int	main(int argc, char *argv[])
{
	(void) argv;
	if (argc != 1)
		error_found("Command ARG is ≠ 1");
	init_server_signal();
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (EXIT_SUCCESS);
}

