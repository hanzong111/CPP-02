/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 23:57:58 by ojing-ha          #+#    #+#             */
/*   Updated: 2023/05/19 11:50:41 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	public	:
				/*	Orthodox Canonical Class Form */
				Fixed();
				Fixed(const Fixed &a);
				Fixed(const int	input);
				Fixed(const float input);
				~Fixed();
				Fixed	&operator=(const Fixed &src);

				/*	Member Functions */
				int		getRawBits(void) const;
				void	setRawBits(const int input);
				float	toFloat(void) const;
				int		toInt(void) const;
	private	:
				int					num;
				static const int	bits = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &src);

#endif