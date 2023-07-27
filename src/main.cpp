#include <iostream>

#include "Point3.h"
#include "Vector3.h"
#include "Link3.h"

// ==================================
// TODO(Diego):
// - Handle errors for trig functions
// ==================================


// ============
// ASSUMPTIONS:
// ============
// =====================================
// Coordinates:
// X axis: positive front, negative rear
// Y axis: positive right, negative left
// Z axis: positive up, negative down
// =====================================
// ===============================================
// Everything in the usc namespace is our own code
// ===============================================

void demo() {
	usc::Point3 origin(0, 0, 0);

	origin.debug("Origin:");

	usc::Point3 x3y2z2(3, 2, 2);
	usc::Vector3 v1(origin, x3y2z2);
	usc::Vector3 v2(x3y2z2, 3, usc::conversion::radians(0), usc::conversion::radians(0));
	usc::Vector3 v3(x3y2z2, 3, usc::conversion::radians(90), usc::conversion::radians(90));

	v1.debug("Vector3 v1");
	v2.debug("Vector3 v2");
	v3.debug("Vector3 v3");
}

struct Leg {
	usc::Link3 coxa;
	usc::Link3 femur;
	usc::Link3 tibia;
	usc::Point3 effector;

	Leg() = default;

	void MoveEffector(usc::Point3 position) {
		effector = position;
		// TODO: calculate new positions for joints of links
	}
};

int main() {
	usc::Point3 height(0, 0, 6.3);

	// Goliath dimensions
	const double COXA_LENGTH = 5.4;
	const double FEMUR_LENGTH = 7.5;
	const double TIBIA_LENGTH = 12.75;

	usc::Vector3 coxa(height, COXA_LENGTH, usc::conversion::radians(90), usc::conversion::radians(45));
	usc::Vector3 femur(coxa.end, FEMUR_LENGTH, usc::conversion::radians(30), coxa.azimuth);
	usc::Vector3 tibia(femur.end, TIBIA_LENGTH, usc::conversion::radians(180), femur.azimuth);

	coxa.debug("Coxa:");
	femur.debug("Femur:");
	tibia.debug("Tibia:");

	return 0;
}