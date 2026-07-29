
// servo 1: D3  -> PB3  -> TIM2 CH2
// servo 2: D5  -> PB4  -> TIM3 CH1
// servo 3: D6  -> PB10 -> TIM2 CH3
// servo 4: D9  -> PC7  -> TIM8 CH2
// servo 5: D10 -> PB6  -> TIM4 CH1
// servo 6: D11 -> PA7  -> TIM3 CH2


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


/*


namespace {
    float hip_angle_to_pwm(float angle)
    {
        if (angle <= 0) {
            return std::max(560, 1560 + std::round(1000.0 * angle/90.0));
        } else {
            return std::min(2560, 1560 + std::round(1000.0 * angle/90.0));
        }
    }
    float shoulder_angle_to_pwm(float angle)
    {
        if (angle <= 0) {
            return std::min(2350, 1480 - std::round(870.0 * angle/80.0));
        } else {
            return std::max(580, 1480 - std::round(900.0 * angle/80.0));
        }
    }
    float elbow_angle_to_pwm(float angle)
    {
        if (angle <= 0) {
            return std::min(2450, 1450 - std::round(1000.0 * angle/90.0));
        } else {
            return std::min(480, 1450 - std::round(930.0 * angle/90.0));
        }
    }
    float wrist_angle_to_pwm(float angle)
    {
        if (angle <= 0) {
            return std::min(1400 + std::round(970.0 * angle/90.0));
        } else {
            return 1400;
        }
    }
    float wristRot_angle_to_pwm(float angle)
    {
        if (angle <= 0) {
            return std::min(2450, 1450 - std::round(1000.0 * angle/90.0));
        } else {
            return std::max(450, 1450 - std::round(1000.0 * angle/90.0));
        }
    }
    float claw_angle_to_pwm(float angle)
    {
        if (angle <= 0) {
            return 900;
        } else {
            return std::min(1450, 900 + std::round(550.0 * angle/75.0));
        }
    }
}

void joint_angle_to_pwm(Joint joint, float angle)
{

}



 */
