#define BOOST_TEST_MODULE ServoTests
#include <boost/test/included/unit_test.hpp>
#include <iostream>

#include "servo_configs.hpp"
#include "servo.hpp"
#include "mock_pwm_handler.cpp"

BOOST_AUTO_TEST_CASE(angle_to_pwm)
{
	BOOST_TEST_MESSAGE("Testing Servo Calibration");
	MockPwmHandler pwm;


	BOOST_TEST_MESSAGE("Testing Hip Joint");
	Servo hip(&ServoConfigs::hip, &pwm);
	hip.move(-90.0);
	BOOST_CHECK_EQUAL(pwm.last_value, 560);
	hip.move(0.0);
	BOOST_CHECK_EQUAL(pwm.last_value, 1560);
	hip.move(90.0);
	BOOST_CHECK_EQUAL(pwm.last_value, 2560);
	hip.move(-1.0);
	BOOST_CHECK(pwm.last_value > 560 && pwm.last_value < 1560);
	hip.move(1.0);
	BOOST_CHECK(pwm.last_value > 1560 && pwm.last_value < 2560);


	BOOST_TEST_MESSAGE("Testing Shoulder Joint");
	Servo shoulder(&ServoConfigs::shoulder, &pwm);
	shoulder.move(-80.0);
	BOOST_CHECK_EQUAL(pwm.last_value, 2350);
	shoulder.move(0.0);
	BOOST_CHECK_EQUAL(pwm.last_value, 1480);
	shoulder.move(80.0);
	BOOST_CHECK_EQUAL(pwm.last_value, 580);
	shoulder.move(-1.0);
	BOOST_CHECK(pwm.last_value > 1480 && pwm.last_value < 2350);
	shoulder.move(1.0);
	BOOST_CHECK(pwm.last_value > 580 && pwm.last_value < 1480);


	BOOST_TEST_MESSAGE("Testing Elbow Joint");
	Servo elbow(&ServoConfigs::elbow, &pwm);
	elbow.move(-90.0);
	BOOST_CHECK_EQUAL(pwm.last_value, 2450);
	elbow.move(0.0);
	BOOST_CHECK_EQUAL(pwm.last_value, 1450);
	elbow.move(90.0);
	BOOST_CHECK_EQUAL(pwm.last_value, 480);
	elbow.move(-1.0);
	BOOST_CHECK(pwm.last_value > 1450 && pwm.last_value < 2450);
	elbow.move(1.0);
	BOOST_CHECK(pwm.last_value > 480 && pwm.last_value < 1450);
	
	
	BOOST_TEST_MESSAGE("Testing Wrist Joint");
	Servo wrist(&ServoConfigs::wrist, &pwm);
	wrist.move(-90.0);
	BOOST_CHECK_EQUAL(pwm.last_value, 430);
	wrist.move(0.0);
	BOOST_CHECK_EQUAL(pwm.last_value, 1400);
	wrist.move(90.0);
	BOOST_CHECK_EQUAL(pwm.last_value, 1400);
	wrist.move(-1.0);
	BOOST_CHECK(pwm.last_value > 430 && pwm.last_value < 1400);
	wrist.move(1.0);
	BOOST_CHECK_EQUAL(pwm.last_value, 1400);
	
	
	BOOST_TEST_MESSAGE("Testing WristRot Joint");
	Servo wristRot(&ServoConfigs::wristRot, &pwm);
	wristRot.move(-90.0);
	BOOST_CHECK_EQUAL(pwm.last_value, 2450);
	wristRot.move(0.0);
	BOOST_CHECK_EQUAL(pwm.last_value, 1450);
	wristRot.move(90.0);
	BOOST_CHECK_EQUAL(pwm.last_value, 450);
	wristRot.move(-1.0);
	BOOST_CHECK(pwm.last_value > 1450 && pwm.last_value < 2450);
	wristRot.move(1.0);
	BOOST_CHECK(pwm.last_value > 450 && pwm.last_value < 1450);
	
	
	BOOST_TEST_MESSAGE("Testing Claw Joint");
	Servo claw(&ServoConfigs::claw, &pwm);
	claw.move(-90.0);
	BOOST_CHECK_EQUAL(pwm.last_value, 900);
	claw.move(0.0);
	BOOST_CHECK_EQUAL(pwm.last_value, 900);
	claw.move(75.0);
	BOOST_CHECK_EQUAL(pwm.last_value, 1450);
	claw.move(90.0);
	BOOST_CHECK_EQUAL(pwm.last_value, 1450);
	claw.move(-1.0);
	BOOST_CHECK_EQUAL(pwm.last_value, 900);
	claw.move(1.0);
	BOOST_CHECK(pwm.last_value > 900 && pwm.last_value < 1450);
}
