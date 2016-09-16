#pragma config(Motor,  port2,           LeftF,         tmotorVex393_MC29, openLoop, driveLeft, encoderPort, None)
#pragma config(Motor,  port3,           LeftM,         tmotorVex393_MC29, openLoop, driveLeft, encoderPort, None)
#pragma config(Motor,  port4,           LeftB,         tmotorVex393_MC29, openLoop, driveLeft, encoderPort, None)
#pragma config(Motor,  port5,           RightF,        tmotorVex393_MC29, openLoop, reversed, driveRight, encoderPort, None)
#pragma config(Motor,  port6,           RightM,        tmotorVex393_MC29, openLoop, reversed, driveRight, encoderPort, None)
#pragma config(Motor,  port7,           RightB,        tmotorVex393_MC29, openLoop, reversed, driveRight)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

const int FullSpeed = 127;
const int Joystick = 30;

void LeftStop()
{
	motor[LeftF] = 0;
	motor[LeftM] = 0;
	motor[LeftB] = 0;
}

void RightStop()
{
	motor[RightF] = 0;
	motor[RightM] = 0;
	motor[RightB] = 0;
}
void LeftForward()
{
	motor[LeftF] = FullSpeed;
	motor[LeftM] = FullSpeed;
	motor[LeftB] = FullSpeed;
}

void RightForward()
{
	motor[RightF] = FullSpeed;
	motor[RightM] = FullSpeed;
	motor[RightB] = FullSpeed;
}

void LeftBackward()
{
	motor[LeftF] = -FullSpeed;
	motor[LeftM] = -FullSpeed;
	motor[LeftB] = -FullSpeed;
}

void RightBackward()
{
	motor[RightF] = -FullSpeed;
	motor[RightM] = -FullSpeed;
	motor[RightB] = -FullSpeed;
}

task autonomous()
{
}

task main()
{
	while (true)
	{
/*
		bool forward = false;
		bool backward = false;
		if (vexRT[vexJSLeftV] > Joystick)
		{
			forward = true;
		}
		else if (vexRT[vexJSLeftV] < -Joystick)
		{
			backward = true;
		}
		bool left = false;
		bool right = false;
		if (vexRT[vexJSLeftH] < -Joystick)
		{
			left = true;
		}
		else if (vexRT[vexJSLeftH] > Joystick)
		{
			right = true;
		}
		if (forward)
		{
			if (left)
			{
				RightForward();
			}
			else if (right)
			{
				LeftForward();
			}
			else
			{
				LeftForward();
				RightForward();
			}
		}
		else if (backward)
		{
			if (left)
			{
				LeftBackward();
			}
			else if (right)
			{
				RightBackward();
			}
			else
			{
				LeftBackward();
				RightBackward();
			}
		}
		else if (left)
		{
			LeftBackward();
			RightForward();
		}
		else if (right)
		{
			LeftForward();
			RightBackward();
		}
*/
		if (vexRT[vexJSLeftV] > Joystick)
		{
			LeftForward();
		}
		else if (vexRT[vexJSLeftV] < -Joystick)
		{
			LeftBackward();
		}
		else
		{
			LeftStop();
		}
		if (vexRT[vexJSRightV] > Joystick)
		{
			RightForward();
		}
		else if (vexRT[vexJSRightV] < -Joystick)
		{
			RightBackward();
		}
		else
		{
			RightStop();
		}
	}
}
