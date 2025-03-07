/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:38:50 by mkulikov          #+#    #+#             */
/*   Updated: 2025/03/07 15:21:19 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
	:_fixedPointValue(0)
{}

Fixed::Fixed(const int num)
{
	_fixedPointValue = num << _fractionalBits;
}

Fixed::Fixed(const float num)
{
	_fixedPointValue = static_cast<int>(roundf(num * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->_fixedPointValue = other._fixedPointValue;
	}
	return *this;
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return _fixedPointValue > fixed._fixedPointValue;
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return _fixedPointValue < fixed._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return _fixedPointValue >= fixed._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return _fixedPointValue <= fixed._fixedPointValue;
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return _fixedPointValue == fixed._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return _fixedPointValue != fixed._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	Fixed result;
	result.setRawBits(_fixedPointValue + fixed._fixedPointValue);
	return result;
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	Fixed result;
	result.setRawBits(_fixedPointValue - fixed._fixedPointValue);
	return result;
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	long long temp = static_cast<long long>(_fixedPointValue) * fixed._fixedPointValue;
	Fixed result;
	result.setRawBits(static_cast<int>(temp >> _fractionalBits));
	return result;
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	long long temp = static_cast<long long>(_fixedPointValue) << _fractionalBits;
	Fixed result;
	result.setRawBits(static_cast<int>(temp / fixed._fixedPointValue));
	return result;
}

Fixed &Fixed::operator++()
{
	_fixedPointValue += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed copy(*this);
	this->_fixedPointValue += 1;
	return copy;
}

Fixed &Fixed::operator--()
{
	_fixedPointValue -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed copy(*this);
	this->_fixedPointValue -= 1;
	return copy;
}

Fixed::~Fixed()
{}

int Fixed::getRawBits(void) const
{
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
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

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

const Fixed &min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}
