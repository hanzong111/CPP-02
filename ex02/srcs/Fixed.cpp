/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 00:13:55 by ojing-ha          #+#    #+#             */
/*   Updated: 2023/03/15 23:37:29 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->num = 0;
}

Fixed::Fixed(const Fixed &a)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = a;
}

//	Converts Int to Fpn	//
Fixed::Fixed(const int input)
{
	// std::cout << "Int constructor called" << std::endl;
	this->num = input << this->bits;
}

//	Converts Float to Fpn	//
Fixed::Fixed(const float input)
{
	// std::cout << "Float constructor called" << std::endl;
	this->num = std::roundf(input * (1 << this->bits));
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	// std::cout << "Copy assignation operator called" << std::endl;
	this->num = src.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->num);
}

void	Fixed::setRawBits(const int input)
{
	// std::cout << "setRawBits member function called" << std::endl;
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

//Comparison operator functions
bool	Fixed::operator>(Fixed src) const
{
	return (this->toFloat() > src.toFloat());
}

bool	Fixed::operator<(Fixed src) const
{
	return (this->toFloat() < src.toFloat());
}

bool	Fixed::operator>=(Fixed src) const
{
	return (this->toFloat() >= src.toFloat());
}

bool	Fixed::operator<=(Fixed src) const
{
	return (this->toFloat() <= src.toFloat());
}

bool	Fixed::operator==(Fixed src) const
{
	return (this->toFloat() == src.toFloat());
}

bool	Fixed::operator!=(Fixed src) const
{
	return (this->toFloat() != src.toFloat());
}

//Arithmetic operator functions
Fixed	Fixed::operator+(Fixed src) const
{
	return(this->toFloat() + src.toFloat());
}

Fixed	Fixed::operator-(Fixed src) const
{
	return(this->toFloat() - src.toFloat());
}

Fixed	Fixed::operator*(Fixed src) const
{
	return(this->toFloat() * src.toFloat());
}

Fixed	Fixed::operator/(Fixed src) const
{
	return(this->toFloat() / src.toFloat());
}

// Post-increment/reduction and Pre-increment/reduction functions
Fixed	Fixed::operator++()
{
	this->num++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->num--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp;

	temp = *this;
	this->num++;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp;

	temp = *this;
	this->num--;
	return (temp);
}

//Own overload functions
Fixed			&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed		&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	else
		return (b);
}

Fixed			&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed		&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	else
		return (b);
}