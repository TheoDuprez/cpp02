/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:04:44 by tduprez           #+#    #+#             */
/*   Updated: 2023/07/31 12:47:08 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// Pour recuperer la valeur a virgule fixe de 10 il faut le multiplier par 2^8, soit 10 * 256, ou le bitshift << 8.
// Pourquoi ? Car on imagine comme ceci : 10 est le nombre entier, 1010 en binaire. Il a huit 0 apres la virgule, donc en bitshiftant vers la gauche on obtient :
// 101000000000 qui correspond au nombre decimal 2560

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

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixeValue = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed& rhs)
{
	return (this->_fixeValue > rhs._fixeValue);
}

bool	Fixed::operator>=(const Fixed& rhs)
{
	return (this->_fixeValue >= rhs._fixeValue);
}

bool	Fixed::operator<(const Fixed& rhs)
{
	return (this->_fixeValue < rhs._fixeValue);
}

bool	Fixed::operator<=(const Fixed& rhs)
{
	return (this->_fixeValue <= rhs._fixeValue);
}

bool	Fixed::operator==(const Fixed& rhs)
{
	return (this->_fixeValue == rhs._fixeValue);
}

bool	Fixed::operator!=(const Fixed& rhs)
{
	return (this->_fixeValue != rhs._fixeValue);
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

Fixed&	Fixed::operator++(void)
{
	(this->_fixeValue)++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	this->_fixeValue++;
	return (temp);
}

Fixed&	Fixed::operator--(void)
{
	(this->_fixeValue)--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	this->_fixeValue--;
	return (temp);
}

Fixed				Fixed::operator+(const Fixed& rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed				Fixed::operator-(const Fixed& rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed				Fixed::operator*(const Fixed& rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed				Fixed::operator/(const Fixed& rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed				Fixed::max(const Fixed& obj1, const Fixed& obj2)
{
	if (obj1.getRawBits() < obj2.getRawBits())
		return (obj2);
	return (obj1);
}


std::ostream&	operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return (out);
}
