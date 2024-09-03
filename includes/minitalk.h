/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:12:29 by mkoster           #+#    #+#             */
/*   Updated: 2024/06/02 14:21:10 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../printf/includes/libft.h"
# include "../printf/includes/ft_printf.h"
# include <signal.h>

void	ft_stringjoin(char *s1, char *s2);
void	conv_bits_to_char(char *to_conv, int min, int max, char *new);
void	print_and_conv(void);
void	send_end_of_file(int server_pid);
char	*conv_bits_to_str(char *s);
char	*trim_received_bits(char *s);
void	cat_char(char *s, char c);
char	*conv_str_bits(char *s);
int		checkrangeofint(char *s);
int		check_received_bits(void);
int		check_and_init_par(int argc, char **argv, int *server_pid);

#endif
