/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:51:38 by tduprez           #+#    #+#             */
/*   Updated: 2023/07/26 15:13:54 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{

private:
	int					_fixeValue;
	static const int	_bitsFractionnal;

public:
	Fixed(void);
	Fixed(const Fixed& obj);
	~Fixed(void);

	int			getRawBits(void) const;
	void		setRawBits(int const raw);
	Fixed&		operator=(const Fixed& obj);

};
