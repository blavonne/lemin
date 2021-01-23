/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 01:05:04 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 01:20:05 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_errmsg_and_exit(char type)
{
	type == 'm' ? ft_putstr_fd("Error\n", 2) : 0;
	type == 'd' ? ft_putstr_fd("Error\n", 2) : 0;
	type == 'r' ? ft_putstr_fd("Error\n", 2) : 0;
	type == 'c' ? ft_putstr_fd("Error\n", 2) : 0;
	type == 'a' ? ft_putstr_fd("Error\n", 2) : 0;
	type == 'h' ? ft_putstr_fd("Trying to destroy not head!\n", 2) : 0;
	type == 'u' ? ft_putstr_fd("Error: unknown conversion type.\n", 2) : 0;
	if (type == 0)
		exit(0);
	exit(1);
}
