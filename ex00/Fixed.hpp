/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:09:54 by tduprez           #+#    #+#             */
/*   Updated: 2023/07/21 07:14:16 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{

private:
	int					_fixeValue;
	static const int	_bits;

public:
	Fixed(void);
	Fixed(const Fixed &obj);
	~Fixed(void);

	Fixed&	operator=(const Fixed& cpy);

	int		getRawBits(void) const;
	void	setRawBits(const int raw);

};
