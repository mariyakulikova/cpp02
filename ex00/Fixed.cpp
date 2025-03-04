/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:38:50 by mkulikov          #+#    #+#             */
/*   Updated: 2025/03/04 11:53:15 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
	:_fixedPointValue(0)
{
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	cout << "Copy constructor called" << endl;
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	cout << "Copy assignment operator called" << endl;
	_fixedPointValue = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

int Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	cout << "setRawBits member function called" << endl;
	_fixedPointValue = raw;
}
