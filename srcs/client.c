/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:01:46 by mkoster           #+#    #+#             */
/*   Updated: 2024/06/02 14:20:20 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	g_flag;

void	send_end_of_file(int server_pid)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_strdup("010001010100111101000110");
	if (s == NULL)
		return ;
	while (s[i])
	{
		g_flag = 1;
		if (s[i] == '0')
			kill(server_pid, SIGUSR1);
		if (s[i] == '1')
			kill(server_pid, SIGUSR2);
		i++;
		while (g_flag == 1)
			usleep(200);
	}
	free(s);
}

void	send_signals(char *s, int server_pid)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		g_flag = 1;
		if (s[i] == '0')
			kill(server_pid, SIGUSR1);
		else if (s[i] == '1')
			kill(server_pid, SIGUSR2);
		while (g_flag == 1)
			usleep(200);
	}
	send_end_of_file(server_pid);
}

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		g_flag = 0;
}

int	main(int argc, char **argv)
{
	int					server_pid;
	char				*s;
	struct sigaction	sa;

	sa.sa_flags = 0;
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	server_pid = 0;
	s = NULL;
	if (!check_and_init_par(argc, argv, &server_pid))
	{
		ft_putstr_fd("Error with parameters\n", 2);
		return (1);
	}
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	s = conv_str_bits(argv[2]);
	send_signals(s, server_pid);
	free(s);
	return (0);
}
