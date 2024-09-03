/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:11:11 by mkoster           #+#    #+#             */
/*   Updated: 2024/06/02 14:19:26 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

char	g_received_bits[10000];

int	check_received_bits(void)
{
	int	i;

	if (ft_strlen(g_received_bits) < 24)
		return (1);
	if (ft_strlen(g_received_bits) % 8 != 0)
		return (1);
	i = ft_strlen(g_received_bits) - 24;
	if (!ft_strncmp(g_received_bits + i, "010001010100111101000110", 24))
		return (0);
	return (1);
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	int	c_pid;

	(void)context;
	c_pid = info->si_pid;
	if (signal == 10)
	{
		cat_char(g_received_bits, '0');
		if (ft_strlen(g_received_bits) == 8000)
			print_and_conv();
		if (!check_received_bits())
			print_and_conv();
		kill(c_pid, SIGUSR1);
	}
	if (signal == 12)
	{
		cat_char(g_received_bits, '1');
		if (ft_strlen(g_received_bits) == 8000)
			print_and_conv();
		kill(c_pid, SIGUSR1);
	}
}

void	print_and_conv(void)
{
	char	*s;
	char	*new_s;

	if (!check_received_bits())
	{
		new_s = trim_received_bits(g_received_bits);
		s = conv_bits_to_str(new_s);
		ft_printf("%s", s);
		free(new_s);
	}
	else
	{
		s = conv_bits_to_str(g_received_bits);
		ft_printf("%s", s);
	}
	ft_memset(g_received_bits, '\0', 10000);
	free(s);
}

// SIGUSR1 == 0, SIGUSR2 == 1
int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	*g_received_bits = '\0';
	pid = getpid();
	ft_printf("%d\n", pid);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_putstr_fd("Error with receiving SIGUSR1\n", 2);
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr_fd("Error with receiving SIGUSR2\n", 2);
		return (2);
	}
	while (1)
		sleep(1);
	return (0);
}
