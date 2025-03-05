/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:38:50 by mkulikov          #+#    #+#             */
/*   Updated: 2025/03/05 17:05:34 by mkulikov         ###   ########.fr       */
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
