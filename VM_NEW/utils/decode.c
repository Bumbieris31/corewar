/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   decode.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 14:40:28 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/22 15:54:17 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function determines type of argument
**	@param	- unsigned char dec_num, number read
**			- short fraction_num, value to divide by (nb of arg)
**	@return	- e_argctype, type of argument
*/

static e_argctype	get_type(unsigned char dec_num, short fraction_num)
{
	if (fraction_num == 3)
		return (dec_num / 4);
	else if (fraction_num == 2)
		return (dec_num / 16);
	return (dec_num / 64);
}

/*
**	@desc	- function decodes encoding byte
**	@param	- int octal, encoding byte
**			- e_argctype args[3], array to fill
*/

void				decode(int octal, e_argctype args[3])
{
	unsigned char	mask[3];
	unsigned char	byte_fr[3];

	ft_bzero(byte_fr, 3);
	mask[0] = 0b11000000;
	mask[1] = 0b00110000;
	mask[2] = 0b00001100;
	byte_fr[0] = mask[0] & octal;
	byte_fr[1] = mask[1] & octal;
	byte_fr[2] = mask[2] & octal;
	args[0] = get_type(byte_fr[0], 1);
	args[1] = get_type(byte_fr[1], 2);
	args[2] = get_type(byte_fr[2], 3);
}
