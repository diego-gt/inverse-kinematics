#pragma once
#include <numbers> // std::numbers::pi

namespace usc::conversion {
	double degrees(double radians) {
		return (radians * 180.0) / std::numbers::pi;
	}

	double radians(double degrees) {
		return (degrees * std::numbers::pi) / 180.0;
	}
}
