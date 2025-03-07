/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:50:40 by mkulikov          #+#    #+#             */
/*   Updated: 2025/03/07 15:31:27 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

ostream &operator<<(ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}

void test(Point const& a, Point const& b, Point const& c, Point const& point, bool expected, std::string testName) {
	bool result = bsp(a, b, c, point);
	cout << testName << " - Expected: " << expected << ", Got: " << result;
	if (result == expected)
	{
		cout << " ✅" << endl;
	}
	else
	{
		cout << " ❌" << endl;
	}
}

int main() {
	Point a(-2, -1);
	Point b(-5, -3);
	Point c(-3, -6);

	test(a, b, c, Point(-1, -3), false, "Test 1: Point Outside");
	test(a, b, c, Point(-4, -3), true, "Test 2: Point Inside");
	test(a, b, c, Point(-5, -6), false, "Test 3: Point Outside");

	Point d(2, 2);
	Point f(3, 5);
	Point g(6, 2);
	test(d, f, g, Point(6, 6), false, "Test 4: Point Outside");
	test(d, f, g, Point(3, 3), true, "Test 5: Point Inside");
	test(d, f, g, Point(-4, -1), false, "Test 6: Point Outside");

	return 0;
}
