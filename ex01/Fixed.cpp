/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:38:50 by mkulikov          #+#    #+#             */
/*   Updated: 2025/03/05 15:51:49 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
	:_fixedPointValue(0)
{
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const int num)
{
	cout << "Int consructor called" << endl;
	_fixedPointValue = num << _fractionalBits;
}

Fixed::Fixed(const float num)
{
	cout << "Float consructor called" << endl;
	_fixedPointValue = static_cast<int>(roundf(num * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed &fixed)
{
	cout << "Copy constructor called" << endl;
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	cout << "Copy assignment operator called" << endl;
	if (this != &other)
	{
		this->_fixedPointValue = other._fixedPointValue;
	}
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

float Fixed::toFloat(void) const
{
	return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _fixedPointValue >> _fractionalBits;
}
