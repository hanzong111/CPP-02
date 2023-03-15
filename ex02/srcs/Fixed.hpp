/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 23:57:58 by ojing-ha          #+#    #+#             */
/*   Updated: 2023/03/15 23:36:40 by ojing-ha         ###   ########.fr       */
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
				Fixed();
				Fixed(const Fixed &a);
				Fixed(const int	input);
				Fixed(const float input);
				~Fixed();
				int		getRawBits(void) const;
				void	setRawBits(const int input);
				float	toFloat(void) const;
				int		toInt(void) const;

				//Copy assignation operator function
				Fixed	&operator=(const Fixed &src);

				//Comparison operator functions
				bool	operator>(Fixed src) const;
				bool	operator<(Fixed src) const;
				bool	operator>=(Fixed src) const;
				bool	operator<=(Fixed src) const;
				bool	operator==(Fixed src) const;
				bool	operator!=(Fixed src) const;

				//Arithmetic operator functions
				Fixed	operator+(Fixed src) const;
				Fixed	operator-(Fixed src) const;
				Fixed	operator*(Fixed src) const;
				Fixed	operator/(Fixed src) const;

				// Post-increment/reduction and Pre-increment/reduction functions
				Fixed	operator++();
				Fixed	operator--();
				Fixed	operator++(int);
				Fixed	operator--(int);

				//Own Overload functions
				static Fixed		&min(Fixed &a, Fixed &b);
				static const Fixed	&min(const Fixed &a, const Fixed &b);
				static Fixed		&max(Fixed &a, Fixed &b);
				static const Fixed	&max(Fixed const &a, Fixed const &b);

	private	:
				int					num;
				static const int	bits = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &src);

#endif