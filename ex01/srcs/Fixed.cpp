/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 00:13:55 by ojing-ha          #+#    #+#             */
/*   Updated: 2023/03/15 00:22:13 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->num = 0;
}

Fixed::Fixed(const Fixed &a)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = a;
}

//	Converts Int to Fpn	//
Fixed::Fixed(const int input)
{
	std::cout << "Int constructor called" << std::endl;
	this->num = input << this->bits;
}

//	Converts Float to Fpn	//
Fixed::Fixed(const float input)
{
	std::cout << "Float constructor called" << std::endl;
	this->num = std::roundf(input * (1 << this->bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignation operator called" << std::endl;
	this->num = src.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->num);
}

void	Fixed::setRawBits(const int input)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->num = input;
}

//	Convert Fpn to float	//
float	Fixed::toFloat(void) const
{	
	return ((float) this->num / (float) (1 << this->bits));
}

//	Convert Fpn to int	//
int		Fixed::toInt(void) const
{
	return (this->num / (1 << this->bits));
}

std::ostream	&operator<<(std::ostream &out, Fixed const &src)
{
	out << src.toFloat();
	return (out);
}
