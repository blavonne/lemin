/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 01:20:42 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 01:25:02 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result;

	result = 0;
	if (octet & 0b00000001)
		result = result | 0b10000000;
	if (octet & 0b00000010)
		result = result | 0b01000000;
	if (octet & 0b00000100)
		result = result | 0b00100000;
	if (octet & 0b00001000)
		result = result | 0b00010000;
	if (octet & 0b00010000)
		result = result | 0b00001000;
	if (octet & 0b00100000)
		result = result | 0b00000100;
	if (octet & 0b01000000)
		result = result | 0b00000010;
	if (octet & 0b10000000)
		result = result | 0b00000001;
	return (result);
}
