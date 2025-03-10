/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:46:48 by mkulikov          #+#    #+#             */
/*   Updated: 2025/03/10 15:15:25 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed area(Point const a, Point const b, Point const c) {
	Fixed area = (a.getX() * (b.getY() - c.getY()) +
					b.getX() * (c.getY() - a.getY()) +
					c.getX() * (a.getY() - b.getY())) / 2.0f;
	if (area < 0)
	{
		area = area * -1;
	}
	return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed fullArea = area(a, b, c);
	Fixed area1 = area(point, b, c);
	Fixed area2 = area(a, point, c);
	Fixed area3 = area(a, b, point);

	return (fullArea == (area1 + area2 + area3));
}
