#pragma config(Motor,  port2,           LeftF,         tmotorVex393_MC29, openLoop, driveLeft, encoderPort, None)
#pragma config(Motor,  port3,           LeftM,         tmotorVex393_MC29, openLoop, driveLeft, encoderPort, None)
#pragma config(Motor,  port4,           LeftB,         tmotorVex393_MC29, openLoop, driveLeft, encoderPort, None)
#pragma config(Motor,  port5,           RightF,        tmotorVex393_MC29, openLoop, reversed, driveRight, encoderPort, None)
#pragma config(Motor,  port6,           RightM,        tmotorVex393_MC29, openLoop, reversed, driveRight, encoderPort, None)
#pragma config(Motor,  port7,           RightB,        tmotorVex393_MC29, openLoop, reversed, driveRight)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "PhilippVEX.c"

task main()
{
	startTask(usercontrol);
	while (true)
		sleep(100);
}
