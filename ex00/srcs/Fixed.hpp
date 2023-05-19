/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 23:57:58 by ojing-ha          #+#    #+#             */
/*   Updated: 2023/05/19 11:33:14 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	public	:
				/*	Orthodox Canonical Class Form */
				Fixed(Fixed &a);
				Fixed	&operator=(Fixed &src);
				Fixed();
				~Fixed();

				/*	Member Functions */
				int		getRawBits(void) const;
				void	setRawBits(const int input);
	private	:
				int					num;
				static const int	bits = 8;
};

#endif