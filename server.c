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

t_data g_data;

void	handle_action(int signum, siginfo_t *info, void *ucontext)
{
	(void) signum;
	(void) info;
	(void) ucontext;
	// if (signum == SIGUSR1)
	// 	ft_putchar_fd('1', STDOUT_FILENO);
	// else
	// 	ft_putchar_fd('0', STDOUT_FILENO);
	usleep(100);
	if (kill(info->si_pid, SIGUSR1) == -1)
		error_found("failed to send signal SIGUSR1");
}

void	init_callback(struct sigaction *server_sig)
{
	server_sig->sa_flags = SA_SIGINFO;
	server_sig->sa_sigaction = &handle_action;
}

int	main(void)
{
	struct sigaction	s_server;

	init_signal(&s_server, init_callback);
	ft_printf("Server PID: [%d]\n", getpid());
	ft_printf("Your server is now ready for use.\n");
	ft_printf("=================================\n");
	while (1)
		sleep(1);
	return (EXIT_SUCCESS);
}
