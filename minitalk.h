/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:10:16 by grcharle          #+#    #+#             */
/*   Updated: 2025/09/29 22:12:41 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stddef.h>
# include <bits/sigaction.h>

# include "ft_printf.h"

void	error_found(char *message);
int		is_number(const char *str);
void	emit_signal(int pid, unsigned int c, unsigned int bits);

#endif // MINITALK_H
