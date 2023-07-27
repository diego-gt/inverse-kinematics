#pragma once

#include <iostream>
namespace usc {
	struct Point3 {
		// Cartesian
		double x;
		double y;
		double z;

		Point3() = default;
		Point3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

		void debug(const std::string& message = "") {
			if (message != "") {
				std::cout << message << '\n';
			}

			std::cout << "Point3 Debug Information:\n";
			std::cout << '\t' << '(' << x << ", " << y << ", " << z << ")\n";
		}
	};
}