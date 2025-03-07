/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:59:00 by mkulikov          #+#    #+#             */
/*   Updated: 2025/03/07 15:23:55 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
	: x(0)
	, y(0)
{}

Point::Point(float x, float y)
	: x(x)
	, y(y)
{}

Point::Point(const Point &other)
	: x(other.x)
	, y(other.y)
{}

Point &Point::operator=(const Point &other)
{
	(void)other;
	return *this;
}

Point::~Point()
{}

Fixed Point::getX() const
{
	return x;
}

Fixed Point::getY() const
{
	return y;
}
