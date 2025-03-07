/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:46:48 by mkulikov          #+#    #+#             */
/*   Updated: 2025/03/07 15:26:21 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed area(Point const a, Point const b, Point const c) {
	Fixed area = (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
					b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
					c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0f;
	// if (area < 0)
	// {
	// 	area = area * -1;
	// }
	return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed fullArea = area(a, b, c);
	Fixed area1 = area(point, b, c);
	Fixed area2 = area(a, point, c);
	Fixed area3 = area(a, b, point);

	if (area1 < 0 || area2 < 0 || area3 < 0)
	{
		return false;
	}

	return (fullArea == (area1 + area2 + area3));
}
