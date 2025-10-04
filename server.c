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

void	handle_action(int signum, siginfo_t *info, void *ucontext)
{
	(void) signum;
	(void) info;
	(void) ucontext;

	ft_printf("! %d ~ %d\n", signum, info->si_pid);
}

void	process_server(void)
{
	struct sigaction	s_server;

	if (sigemptyset(&s_server.sa_mask) != 0)
		error_found("sigemptyset failed to initialize");
	s_server.sa_flags = 0;
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
		error_found("CMD ARG is ≠ 1");
	process_server();
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
