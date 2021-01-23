/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:55:36 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:55:39 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_pow(double basis, int exponent)
{
	double			base;
	long long int	exp;

	if (exponent == 0)
		return (1);
	base = basis;
	exp = exponent;
	exp = exp < 0 ? -exp : exp;
	while (--exp)
		basis *= base;
	if (exponent < 0)
		return (1. / basis);
	else
		return (basis);
}
