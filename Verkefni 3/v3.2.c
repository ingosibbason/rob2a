#pragma config(Sensor, in1,    lightSensor,    sensorReflection)
#pragma config(Sensor, in2,    potentiometer,  sensorPotentiometer)
#pragma config(Sensor, in3,    lineFollowerLeft, sensorLineFollower)
#pragma config(Sensor, in4,    lineFollowerMid, sensorLineFollower)
#pragma config(Sensor, in5,    lineFollowerRight, sensorLineFollower)
#pragma config(Sensor, in6,    gyroSensor,     sensorGyro)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  touchSensor,    sensorTouch)
#pragma config(Sensor, dgtl6,  sonarIn,        sensorSONAR_mm)
#pragma config(Sensor, dgtl8,  ,               sensorDigitalIn)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port4,           armMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           clawMotor,     tmotorServoContinuousRotation, openLoop)


task EmergencyBrake()
{
	int i;
	while (true)
	{
		if (vexRT[Btn8R] !=0)
		{
			for (i=0; i<3; i++)
			{
				motor[rightMotor] = 0;
				motor[leftMotor]  = 0;
			}
			StopAllTasks();
		}
		wait1Msec(20);
	}
	return;
}
const float rotations = 360.0;

void driveForward(){
	if(SensorValue[rightEncoder] == SensorValue[leftEncoder]) // If rightEncoder has counted the same amount as leftEncoder:
	{
		// Move Forward
		motor[rightMotor] = 80;		    // Right Motor is run at power level 80
		motor[leftMotor]  = 80;		    // Left Motor is run at power level 80
	}
	else if(SensorValue[rightEncoder] > SensorValue[leftEncoder])	// If rightEncoder has counted more encoder counts
	{
		// Turn slightly right
		motor[rightMotor] = 60;		    // Right Motor is run at power level 60
		motor[leftMotor]  = 80;		    // Left Motor is run at power level 80
	}
	else	// Only runs if leftEncoder has counted more encoder counts
	{
		// Turn slightly left
		motor[rightMotor] = 80;		    // Right Motor is run at power level 80
		motor[leftMotor]  = 60;		    // Left Motor is run at power level 60
	}
}

void TurnLeft(float r)
{
  SensorValue[rightEncoder] = 0;    /* Clear the encoders for    */
  SensorValue[leftEncoder]  = 0;    /* consistancy and accuracy. */

  // While the encoders have not yet met their goal: (left is compared negativly since it will in reverse)
  while(SensorValue[rightEncoder] < (r * rotations) && SensorValue[leftEncoder] > (-1 * r * rotations))
  {
    motor[rightMotor] = 63;         // Run the right motor forward at half speed
    motor[leftMotor]  = -63;        // Run the left motor backward at half speed
  }
  motor[rightMotor] = 0;            /* Stop both motors!  This is important so that each function          */
  motor[leftMotor]  = 0;            /* can act independantly as a "chunk" of code, without any loose ends. */
}

void TurnRight(float r)
{
  SensorValue[rightEncoder] = 0;    /* Clear the encoders for    */
  SensorValue[leftEncoder]  = 0;    /* consistancy and accuracy. */

  // While the encoders have not yet met their goal: (left is compared negativly since it will in reverse)
  while(SensorValue[rightEncoder] < (r * rotations) && SensorValue[leftEncoder] > (-1 * r * rotations))
  {
    motor[rightMotor] = -63;         // Run the right motor backward at half speed
    motor[leftMotor]  = 63;        // Run the left motor forward at half speed
  }
  motor[rightMotor] = 0;            /* Stop both motors!  This is important so that each function          */
  motor[leftMotor]  = 0;            /* can act independantly as a "chunk" of code, without any loose ends. */
}
task main()
{
	StartTask(EmergencyBrake);
	float distance = 1.59;
	float spins  = 360 * distance;

	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;
	while(SensorValue[rightEncoder]< spins && SensorValue[leftEncoder] < spins)
  {
    driveForward();
  }

	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;
  motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
  wait1Msec(1000);

  TurnLeft(1);

  SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;
  motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(1000);

  while(SensorValue[rightEncoder]< spins && SensorValue[leftEncoder] < spins)
  {
    driveForward();
  }

	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;
  motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(1000);

  TurnRight(1);

  SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;
  motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(1000);

  while(SensorValue[rightEncoder]< spins && SensorValue[leftEncoder] < spins)
  {
    driveForward();
  }

	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;
  motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(1000);

  TurnRight(1);

  SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;
  motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(1000);

	while(SensorValue[rightEncoder]< spins && SensorValue[leftEncoder] < spins)
  {
    driveForward();
  }

	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;
  motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(1000);
}
