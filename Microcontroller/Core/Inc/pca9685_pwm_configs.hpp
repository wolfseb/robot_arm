#include "servo.hpp"

#pragma once

// calibration
/*
 * servo		|	min		|	center	|	max
 *
 * 1: hip		|	500		|	1400	|	2300		500: 90deg cw (-), 2300: 90deg ccw (+)
 * 2: shoulder	|	680		|	1330	|	1950		580: 70deg back, 1950: 70deg forward (measured from vertical center)
 * 3: elbow		|	490		|	1330	|	2170		490: 90dg back, 2170: 90deg forward
 * 4: wrist		|	400		|	1250	|	1250		400: 90deg forward, do not go over 0deg, mechanical block!!
 * 5: wrist rot	|	400		|	1300	|	2200		400: 90deg ccw (+), 2200: 90deg cw (-)
 * 6: claw		|	750		|	 750	|	1250        900: closed: 0deg, 1450: open: 75deg
 */

namespace PCA9685_ServoConfigs {
    inline constexpr ServoConfig hip = {
        .minAngle = -90,
        .maxAngle = 90,
        .minPWM = 500,
        .centerPWM = 1400,
        .maxPWM = 2300,
		.inverted = false
    };
    inline constexpr ServoConfig shoulder = {
        .minAngle = -70,
        .maxAngle = 70,
        .minPWM = 1950, // forward
        .centerPWM = 1330,
        .maxPWM = 680, // backward
		.inverted = false
    };
    inline constexpr ServoConfig elbow = {
        .minAngle = -90,
        .maxAngle = 90,
        .minPWM = 2170,
        .centerPWM = 1330,
        .maxPWM = 490,
		.inverted = false
    };
    inline constexpr ServoConfig wrist = {
        .minAngle = -90,
        .maxAngle = 0,  // mechanical block, don't go over 0 deg!!
        .minPWM = 400,
        .centerPWM = 1250,
        .maxPWM = 1250,
		.inverted = false
    };
    inline constexpr ServoConfig wristRot = {
        .minAngle = -90.0,
        .maxAngle = 90.0,
        .minPWM = 2200, // -90deg (ccw)
        .centerPWM = 1300,
        .maxPWM = 400,   // +90deg (cw)
		.inverted = false
    };
    inline constexpr ServoConfig claw = {
        .minAngle = 0,
        .maxAngle = 75,
        .minPWM = 750,
        .centerPWM = 750,
        .maxPWM = 1250,
		.inverted = false
    };
}
