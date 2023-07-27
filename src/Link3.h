#pragma once
#include "Joint.h"
#include "Point3.h"
#include "Vector3.h"
#include "Conversion.h"

namespace usc {
	// A Link3 is basically a restricted Vector3 using Joints and 
	// with the ability to be chained together to other links
	struct Link3 {
		Joint inclination_joint;
		Joint azimuth_joint;
		Vector3 result;
		Link3* next = nullptr;

		// ==========================
		// CONSTRUCTORS / DESTRUCTORS
		// ==========================
		Link3() = default;

		Link3(Point3 _start, Point3 _end) {
			result = Vector3(_start, _end);

			inclination_joint = Joint(conversion::degrees(result.inclination));
			azimuth_joint = Joint(conversion::degrees(result.azimuth));
		}

		Link3(Point3 _start, double _length, double _inclination, double _azimuth) {
			result = Vector3(_start, _length, _inclination, _azimuth);

			inclination_joint = Joint(conversion::degrees(result.inclination));
			azimuth_joint = Joint(conversion::degrees(result.azimuth));
		}


		// ==========
		// PROPERTIES
		// ==========

		double Length() {
			return result.length;
		}

		// =======
		// METHODS
		// =======

		void AttachLink(Link3* link) {
			next = link;
		}

		void ChangeOrigin(Point3 new_position) {
			result.ChangeOrigin(new_position);
			inclination_joint.SetAngle(result.inclination);
			azimuth_joint.SetAngle(result.azimuth);
			// TODO: review joint limits
		}

		void RotateInclination(double inclination) {
			// Check if new inclination angle is within the joint restriction
			if (inclination_joint.SetAngle(inclination)) {
				result.RotateInclination(inclination);
			}
		}

		void RotateAzimuth(double azimuth) {
			// Check if new azimuth angle is within the joint restriction
			if (azimuth_joint.SetAngle(azimuth)) {
				result.RotateAzimuth(azimuth);
			}
		}
	};
}