#define BOOST_TEST_MODULE ServoTests
#include <boost/test/included/unit_test.hpp>
#include <iostream>

#include "stm32_pwm_configs.hpp"
#include "servo.hpp"

BOOST_AUTO_TEST_CASE(angle_to_pwm)
{
	BOOST_TEST_MESSAGE("Testing Servo Calibration");

	BOOST_TEST_MESSAGE("Testing Hip Joint");
	Servo hip(&Stm32_ServoConfigs::hip);
	BOOST_CHECK_EQUAL(hip.angle_to_pwm(-90.0), 560);
	BOOST_CHECK_EQUAL(hip.angle_to_pwm(0.0), 1560);
	BOOST_CHECK_EQUAL(hip.angle_to_pwm(90.0), 2560);
	uint16_t pwm = hip.angle_to_pwm(-1.0);
	BOOST_CHECK(pwm > 560 && pwm < 1560);
	pwm = hip.angle_to_pwm(1.0);
	BOOST_CHECK(pwm > 1560 && pwm < 2560);


	BOOST_TEST_MESSAGE("Testing Shoulder Joint");
	Servo shoulder(&Stm32_ServoConfigs::shoulder);
	BOOST_CHECK_EQUAL(shoulder.angle_to_pwm(-80.0), 2350);
	BOOST_CHECK_EQUAL(shoulder.angle_to_pwm(0.0), 1480);
	BOOST_CHECK_EQUAL(shoulder.angle_to_pwm(80.0), 580);
	pwm = shoulder.angle_to_pwm(-1.0);
	BOOST_CHECK(pwm > 1480 && pwm < 2350);
	pwm = shoulder.angle_to_pwm(1.0);
	BOOST_CHECK(pwm > 580 && pwm < 1480);


	BOOST_TEST_MESSAGE("Testing Elbow Joint");
	Servo elbow(&Stm32_ServoConfigs::elbow);
	BOOST_CHECK_EQUAL(elbow.angle_to_pwm(-90.0), 2450);
	BOOST_CHECK_EQUAL(elbow.angle_to_pwm(0.0), 1450);
	BOOST_CHECK_EQUAL(elbow.angle_to_pwm(90.0), 480);
	pwm = elbow.angle_to_pwm(-1.0);
	BOOST_CHECK(pwm > 1450 && pwm < 2450);
	pwm = elbow.angle_to_pwm(1.0);
	BOOST_CHECK(pwm > 480 && pwm < 1450);
	
	
	BOOST_TEST_MESSAGE("Testing Wrist Joint");
	Servo wrist(&Stm32_ServoConfigs::wrist);
	BOOST_CHECK_EQUAL(wrist.angle_to_pwm(-90.0), 430);
	BOOST_CHECK_EQUAL(wrist.angle_to_pwm(0.0), 1400);
	BOOST_CHECK_EQUAL(wrist.angle_to_pwm(90.0), 1400);
	pwm = wrist.angle_to_pwm(-1.0);
	BOOST_CHECK(pwm > 430 && pwm < 1400);
	BOOST_CHECK_EQUAL(wrist.angle_to_pwm(1.0), 1400);
	
	
	BOOST_TEST_MESSAGE("Testing WristRot Joint");
	Servo wristRot(&Stm32_ServoConfigs::wristRot);
	BOOST_CHECK_EQUAL(wristRot.angle_to_pwm(-90.0), 2450);
	BOOST_CHECK_EQUAL(wristRot.angle_to_pwm(0.0), 1450);
	BOOST_CHECK_EQUAL(wristRot.angle_to_pwm(90.0), 450);
	pwm = wristRot.angle_to_pwm(-1.0);
	BOOST_CHECK(pwm > 1450 && pwm < 2450);
	pwm = wristRot.angle_to_pwm(1.0);
	BOOST_CHECK(pwm > 450 && pwm < 1450);
	
	
	BOOST_TEST_MESSAGE("Testing Claw Joint");
	Servo claw(&Stm32_ServoConfigs::claw);
	BOOST_CHECK_EQUAL(claw.angle_to_pwm(-90.0), 900);
	BOOST_CHECK_EQUAL(claw.angle_to_pwm(0.0), 900);
	BOOST_CHECK_EQUAL(claw.angle_to_pwm(75.0), 1450);
	BOOST_CHECK_EQUAL(claw.angle_to_pwm(90.0), 1450);
	BOOST_CHECK_EQUAL(claw.angle_to_pwm(-1.0), 900);
	pwm = claw.angle_to_pwm(1.0);
	BOOST_CHECK(pwm > 900 && pwm < 1450);
}
