/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:51:38 by tduprez           #+#    #+#             */
/*   Updated: 2023/07/31 16:06:59 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed
{

private:
	int					_fixeValue;
	static const int	_bitsFractionnal;

public:
	Fixed(void);
	Fixed(const int i);
	Fixed(const float f);
	Fixed(const Fixed& obj);
	~Fixed(void);

	int					getRawBits(void) const;
	void				setRawBits(int const raw);

	Fixed&				operator=(const Fixed& rhs);

	bool				operator>(const Fixed& rhs);
	bool				operator>=(const Fixed& rhs);
	bool				operator<(const Fixed& rhs);
	bool				operator<=(const Fixed& rhs);
	bool				operator==(const Fixed& rhs);
	bool				operator!=(const Fixed& rhs);

	Fixed&				operator++(void);
	Fixed				operator++(int);
	Fixed&				operator--(void);
	Fixed				operator--(int);

	Fixed				operator+(const Fixed& rhs) const;
	Fixed				operator-(const Fixed& rhs) const;
	Fixed				operator*(const Fixed& rhs) const;
	Fixed				operator/(const Fixed& rhs) const;

	static Fixed		min(Fixed& obj1, Fixed& obj2);
	static Fixed		min(const Fixed& obj1, const Fixed& obj2);
	static Fixed		max(Fixed& obj1, Fixed& obj2);
	static Fixed		max(const Fixed& obj1, const Fixed& obj2);
	int					toInt(void) const;
	float				toFloat(void) const;

};

std::ostream&		operator<<(std::ostream& out, const Fixed& obj);
