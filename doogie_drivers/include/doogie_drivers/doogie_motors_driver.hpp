#ifndef _INCLUDE_DOOGIE_DRIVERS_DOOGIE_MOTORS_DRIVER_HPP_
#define _INCLUDE_DOOGIE_DRIVERS_DOOGIE_MOTORS_DRIVER_HPP_

// Pins referenced by BCM_GPIO
#define MOTOR_LEFT_PWM 18
#define MOTOR_LEFT_EN1 27
#define MOTOR_LEFT_EN2 17

// Pins referenced by BCM_GPIO
#define MOTOR_RIGHT_PWM 19
#define MOTOR_RIGHT_EN1 6 
#define MOTOR_RIGHT_EN2 12

// Pin referenced by BCM_GPIO
#define HBRIDGE_STDBY 23

// pwm_freq (Hz) = 19200000 / PWM_CLOCK / PWM_RANGE
#define PWM_CLOCK 100
#define PWM_RANGE 100

namespace doogie_drivers {

enum VelocityType {
	LINEAR,
	ANGULAR
};

enum MotorSide {
	LEFT,
	RIGHT
};

class DoogieMotorsDriver {
 public:
	DoogieMotorsDriver(float wheel_diameter=0.032, float gear_ratio=29.86);
	void init();
	void setMotorVelocity(float velocity, MotorSide motor_side, VelocityType velocity_type=LINEAR);
	void setMotorsVelocity(float velocity, VelocityType velocity_type=LINEAR);
	void brakeMotor(MotorSide motor_side);
	void brakeMotors();
	float getLeftMotorVelocity();
	float getRightMotorVelocity();
	~DoogieMotorsDriver();
 
 private:
	enum TurningDirection {
		CLOCKWISE,
		COUNTER_CLOCKWISE
	};

	void setMotorTurningDirection(MotorSide motor_side, TurningDirection turning_direction);
	float wheel_diameter_;
	float gear_ratio_;
};

}

#endif // _INCLUDE_DOOGIE_DRIVERS_DOOGIE_MOTORS_DRIVER_HPP_