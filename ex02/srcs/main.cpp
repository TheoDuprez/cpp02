/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:05:18 by tduprez           #+#    #+#             */
/*   Updated: 2023/07/31 16:13:38 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int main( void )
{

	// Mandatory

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;

	std::cout << "------------------------------------------" << std::endl;

	Fixed	max;
	max = Fixed::max(a, b);
	std::cout << max.getRawBits() << std::endl;

	Fixed	maxConst;
	maxConst = Fixed::max(a, a);
	std::cout << maxConst.getRawBits() << std::endl;

	// More exemple :
	std::cout << "------------------------------------------" << std::endl;

	Fixed test(42.21f);
	std::cout << test << std::endl;
	std::cout << test++ << std::endl;
	std::cout << test << std::endl;
	std::cout << ++test << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << test << std::endl;
	std::cout << test-- << std::endl;
	std::cout << test << std::endl;
	std::cout << --test << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << test + test << std::endl;
	std::cout << test - test << std::endl;
	std::cout << test * test << std::endl;
	std::cout << test / test << std::endl;
	std::cout << "------------------------------------------" << std::endl;

	std::cout << test << "|" << max << std::endl;
	std::cout << (test > max) << std::endl;
	std::cout << (test < max) << std::endl;

return 0;
}
