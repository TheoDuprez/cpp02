/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:04:44 by tduprez           #+#    #+#             */
/*   Updated: 2023/07/31 13:36:44 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

const int Fixed::_bitsFractionnal = 8;

Fixed::Fixed(void): _fixeValue(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
	return ;

}

Fixed::Fixed(const int i)
{
	this->_fixeValue = i * (1 << this->_bitsFractionnal);
	return ;
}

Fixed::Fixed(const float f)
{
	this->_fixeValue = roundf(f * (1 << this->_bitsFractionnal));
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed&	Fixed::operator=(const Fixed& cpy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixeValue = cpy.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixeValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixeValue = raw;
	return ;
}

int		Fixed::toInt(void) const
{
	return (this->_fixeValue / (1 << this->_bitsFractionnal));
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixeValue / (1 << this->_bitsFractionnal));
}

std::ostream&	operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return (out);
}

void	printFixe(const int i)
{
	std::cout << (i >> 8) << "." << (i & 0xFF) << std::endl;
}
