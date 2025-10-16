/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:11:15 by grcharle          #+#    #+#             */
/*   Updated: 2025/09/30 17:12:51 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_found(char *message)
{
	ft_printf("Error: %s\n", message);
	exit(EXIT_FAILURE);
}

void	init_signal(struct sigaction *sig, void (fcall)(struct sigaction *sig))
{
	if (sigemptyset(&(*sig).sa_mask) != 0)
		error_found("sigemptyset failed to initialize");
	fcall(&(*sig));
	if (sigaddset(&(*sig).sa_mask, SIGUSR1) != 0)
		error_found("sigaddset failed for SIGUSR1");
	if (sigaddset(&(*sig).sa_mask, SIGUSR2) != 0)
		error_found("sigaddset failed for SIGUSR2");
	if (sigaction(SIGUSR1, &(*sig), (void *)0) != 0)
		error_found("sigaction failed for SIGUSR1");
	if (sigaction(SIGUSR2, &(*sig), (void *)0) != 0)
		error_found("sigaction failed for SIGUSR2");
}
