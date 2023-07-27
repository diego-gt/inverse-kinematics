#pragma once
#include "Point3.h"
#include "Conversion.h"

#include <cmath>

namespace usc {
	struct Vector3 {
		// cartesian coordinates
		Point3 origin;
		Point3 end;
		// spherical coordinates
		double azimuth;
		double inclination;
		double length; // also known as radial distance

		Vector3() = default;

		Vector3(Point3 _origin, Point3 _end) : origin(_origin), end(_end) {
			length = std::hypot(_end.x - _origin.x, _end.y - _origin.y, _end.z - _origin.z);
			inclination = std::acos((end.z - origin.z) / length);
			azimuth = std::atan2((end.y - origin.y), (end.x - origin.x));
		}

		Vector3(Point3 _origin, double _length, double _inclination, double _azimuth) : origin(_origin), length(_length), inclination(_inclination), azimuth(_azimuth) {
			end.x = origin.x + length * std::sin(inclination) * std::cos(azimuth);
			end.y = origin.y + length * std::sin(inclination) * std::sin(azimuth);
			end.z = origin.z + length * std::cos(inclination);
		}

		// TODO: create a version of this function that works on 2 already created instances of Vector3
		void CalculateEnd() {
			end.x = origin.x + length * std::sin(inclination) * std::cos(azimuth);
			end.y = origin.y + length * std::sin(inclination) * std::sin(azimuth);
			end.z = origin.z + length * std::cos(inclination);
		}

		void ChangeOrigin(Point3 new_position) {
			origin = new_position;
			CalculateEnd();
		}

		void RotateInclination(double _inclination) {
			inclination = _inclination;
			CalculateEnd();
		}

		void RotateAzimuth(double _azimuth) {
			azimuth = _azimuth;
			end.x = origin.x + length * std::sin(inclination) * std::cos(azimuth);
			end.y = origin.y + length * std::sin(inclination) * std::sin(azimuth);
		}

		void Resize(double new_length) {
			length = new_length;
			CalculateEnd();
		}

		// TODO: implement rotation methods

		void debug(const std::string& message = "") {
			if (message != "") {
				std::cout << message << '\n';
			}

			//std::cout << "Vector3 Debug Information:\n";
			std::cout << '\t' << "Origin: " << '(' << origin.x << ", " << origin.y << ", " << origin.z << ")\n";
			std::cout << '\t' << "End: " << '(' << end.x << ", " << end.y << ", " << end.z << ")\n";
			std::cout << '\t' << "Length: " << length << '\n';
			std::cout << '\t' << "Inclination (theta): " << inclination << "rad or " << usc::conversion::degrees(inclination) << " degrees\n";
			std::cout << '\t' << "Azimuth (phi): " << azimuth << "rad or " << usc::conversion::degrees(azimuth) << " degrees\n";
		}
	};
}