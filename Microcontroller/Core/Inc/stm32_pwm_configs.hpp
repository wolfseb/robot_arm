#include "servo.hpp"

#pragma once

// calibration
/*
 * servo		|	min		|	center	|	max
 *
 * 1: hip		|	560		|	1560	|	2560		560: 90deg cw (-), 2560: 90deg ccw (+)
 * 2: shoulder	|	580		|	1480	|	2350		580: 80deg back, 2350: 80deg forward (measured from vertical center)
 * 3: elbow		|	480		|	1450	|	2450		480: 90dg back, 2450: 90deg forward
 * 4: wrist		|	430		|	1400	|	1400		430: 90deg forward, do not go over 0deg, mechanical block!!
 * 5: wrist rot	|	450		|	1450	|	2450		450: 90deg ccw (+), 2450: 90deg cw (-)
 * 6: claw		|	900		|	 900	|	1450        900: closed: 0deg, 1450: open: 75deg
 */

namespace Stm32_ServoConfigs {
    inline constexpr ServoConfig hip = {
        .minAngle = -90,
        .maxAngle = 90,
        .minPWM = 560,
        .centerPWM = 1560,
        .maxPWM = 2560,
		.inverted = false
    };
    inline constexpr ServoConfig shoulder = {
        .minAngle = -80,
        .maxAngle = 80,
        .minPWM = 2350, // forward
        .centerPWM = 1480,
        .maxPWM = 580, // backward
		.inverted = false
    };
    inline constexpr ServoConfig elbow = {
        .minAngle = -90,
        .maxAngle = 90,
        .minPWM = 2450,
        .centerPWM = 1450,
        .maxPWM = 480,
		.inverted = false
    };
    inline constexpr ServoConfig wrist = {
        .minAngle = -90,
        .maxAngle = 0,  // mechanical block, don't go over 0 deg!!
        .minPWM = 430,
        .centerPWM = 1400,
        .maxPWM = 1400,
		.inverted = false
    };
    inline constexpr ServoConfig wristRot = {
        .minAngle = -90.0,
        .maxAngle = 90.0,
        .minPWM = 2450, // -90deg (ccw)
        .centerPWM = 1450,
        .maxPWM = 450,   // +90deg (cw)
		.inverted = false
    };
    inline constexpr ServoConfig claw = {
        .minAngle = 0,
        .maxAngle = 75,
        .minPWM = 900,
        .centerPWM = 900,
        .maxPWM = 1450,
		.inverted = false
    };
}
