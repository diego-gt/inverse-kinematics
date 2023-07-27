#pragma once
//#include "Point3.h"

namespace usc {
	struct Joint {
		// TODO: should we consider the position of the joint?
		//Point3 position;
		double angle = 0.0;
		// TODO: replace values with real limits of servos
		double lower_limit = -180.0;
		double upper_limit = 180.0;

		Joint() = default;

		Joint(double _angle, double _lower_limit, double _upper_limit) : angle(_angle), lower_limit(_lower_limit), upper_limit(_upper_limit) {}
		Joint(double _angle) : angle(_angle) {}

		// returns true if the angle was successfully changed, otherwise returns false
		bool SetAngle(double new_angle) {
			// TODO: log error if trying to set angle out of limits
			if (lower_limit <= new_angle && new_angle <= upper_limit) {
				angle = new_angle;
				return true;
			}

			return false;
		}

		void SetUpperLimit(double new_limit) {
			// TODO: if new limit is less than current angle
			upper_limit = new_limit;
		}
	};
}