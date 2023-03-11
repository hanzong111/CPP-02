/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 23:57:58 by ojing-ha          #+#    #+#             */
/*   Updated: 2023/03/12 00:23:01 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	public	:
				Fixed();
				Fixed(Fixed &a);
				~Fixed();
				Fixed	&operator=(Fixed &src);
				int		getRawBits(void) const;
				void	setRawBits(const int input);
	private	:
				int					num;
				static const int	bits;
};

#endif