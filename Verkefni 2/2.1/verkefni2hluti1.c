#pragma config(Sensor, in1,    lightSensor,    sensorReflection)
#pragma config(Sensor, in2,    potentiometer,  sensorPotentiometer)
#pragma config(Sensor, in3,    lineFollowerLeft, sensorLineFollower)
#pragma config(Sensor, in4,    lineFollowerMid, sensorLineFollower)
#pragma config(Sensor, in5,    lineFollowerRight, sensorLineFollower)
#pragma config(Sensor, in6,    gyroSensor,     sensorGyro)
#pragma config(Sensor, dgtl1,  rightEncoderTopWire, sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoderTopWire, sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  touchSensor,    sensorTouch)
#pragma config(Sensor, dgtl6,  sonarIn,        sensorSONAR_mm)
#pragma config(Sensor, dgtl8,  ,               sensorDigitalIn)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port4,           armMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           clawMotor,     tmotorServoContinuousRotation, openLoop)
task main()
{

//at full speed the robot goes 0.5 m/s
	wait1Msec(10000);							// Robot waits for 2000 milliseconds before executing program

	//0.5 m
	motor[rightMotor] = 127;		  // Motor on port2 is run at full (127) power forward
	motor[leftMotor]  = 127;		  // Motor on port3 is run at full (127) power forward
	wait1Msec(1000);							// Robot runs previous code for 1000 milliseconds before stoppping
	motor[rightMotor] = 0;		  	// stop motor
	motor[leftMotor]  = 0;		  	// stop motor
	wait1Msec(500);								// Robot runs previous code for 500 milliseconds before moving on

	motor[rightMotor] = -127;		  // Motor on port2 is run at full (127) power backwards
	motor[leftMotor]  = -127;		  // Motor on port3 is run at full (127) power backwards
	wait1Msec(1000);							// Robot runs previous code for 1000 milliseconds before moving on
	motor[rightMotor] = 0;		  	// Stop motor
	motor[leftMotor]  = 0;		  	// Stop motor
	wait1Msec(500);								// Robot runs previous code for 500 milliseconds before moving on

	// 1 m
	motor[rightMotor] = 127;		  // Motor on port2 is run at full (127) power forward
	motor[leftMotor]  = 127;		  // Motor on port3 is run at full (127) power forward
	wait1Msec(2000);							// Robot runs previous code for 2000 milliseconds before moving on
	motor[rightMotor] = 0;		  	// Stop motor
	motor[leftMotor]  = 0;		  	// Stop motor
	wait1Msec(500);								// Robot runs previous code for 500 milliseconds before moving on

	motor[rightMotor] = -127;		  // Motor on port2 is run at full (127) power backwards
	motor[leftMotor]  = -127;		  // Motor on port3 is run at full (127) power backwards
	wait1Msec(2000);							// Robot runs previous code for 2000 milliseconds before moving on
	motor[rightMotor] = 0;		  	// Stop motor
	motor[leftMotor]  = 0;		  	// Stop motor
	wait1Msec(500);								// Robot waits for 500 milliseconds

	// 1.5 m
	motor[rightMotor] = 127;		  // Motor on port2 is run at full (127) power forward
	motor[leftMotor]  = 127;		  // Motor on port3 is run at full (127) power forward
	wait1Msec(3000);							// Robot runs previous code for 3000 milliseconds before moving on
	motor[rightMotor] = 0;		  	// Stop motor
	motor[leftMotor]  = 0;		  	// Stop motor
	wait1Msec(500);								// Robot runs previous code for 500 milliseconds before moving on

	motor[rightMotor] = -127;		  // Motor on port2 is run at full (127) power backwards
	motor[leftMotor]  = -127;		  // Motor on port3 is run at full (127) power backwards
	wait1Msec(3000);							// Robot runs previous code for 3000 milliseconds before moving on
	motor[rightMotor] = 0;		  	// Stop motor
	motor[leftMotor] = 0;		  		// Stop motor
	wait1Msec(500);								// Robot runs previous code for 500 milliseconds before moving on

	// 2 m
	motor[rightMotor] = 127;		  // Motor on port2 is run at full (127) power forward
	motor[leftMotor]  = 127;		  // Motor on port3 is run at full (127) power forward
	wait1Msec(4000);							// Robot runs previous code for 4000 milliseconds before moving on
	motor[rightMotor] = 0;		  	// Stop motor
	motor[leftMotor] = 0;		  		// Stop motor
	wait1Msec(500);								// Robot runs previous code for 500 milliseconds before moving on

	motor[rightMotor] = -127;		  // Motor on port2 is run at full (127) power backwards
	motor[leftMotor]  = -127;		  // Motor on port3 is run at full (127) power backwards
	wait1Msec(4000);							// Robot runs previous code for 4000 milliseconds before moving on
	motor[rightMotor] = 0;		  	// Stop motor
	motor[leftMotor]  = 0;		  	// Stop motor
	wait1Msec(500);								// Robot runs previous code for 500 milliseconds before moving on

	// 2.5 m
	motor[rightMotor] = 127;		  // Motor on port2 is run at full (127) power forward
	motor[leftMotor]  = 127;		  // Motor on port3 is run at full (127) power forward
	wait1Msec(5000);							// Robot runs previous code for 5000 milliseconds before moving on
	motor[rightMotor] = 0;		  	// Stop motor
	motor[leftMotor] = 0;		  		// Stop motor
	wait1Msec(500);								// Robot runs previous code for 500 milliseconds before moving on

	motor[rightMotor] = -127;		  // Motor on port2 is run at full (127) power backwards
	motor[leftMotor]  = -127;		  // Motor on port3 is run at full (127) power backwards
	wait1Msec(5000);							// Robot runs previous code for 5000 milliseconds before moving on
	motor[rightMotor] = 0;		  	// Stop motor
	motor[leftMotor] = 0;		  		// Stop motor
	wait1Msec(500);								// Robot runs previous code for 500 milliseconds before moving on

}
