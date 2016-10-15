//#define THREE_MOTORS
const int FullSpeed = 127;
const int LeftFullSpeed = 50;
const int RightFullSpeed = 100;
const int Joystick = 30;

void LeftStop()
{
	motor[LeftF] = 0;
#ifdef THREE_MOTORS
	motor[LeftM] = 0;
#endif
	motor[LeftB] = 0;
}

void RightStop()
{
	motor[RightF] = 0;
#ifdef THREE_MOTORS
	motor[RightM] = 0;
#endif
	motor[RightB] = 0;
}

void LeftForward()
{
	motor[LeftF] = LeftFullSpeed;
#ifdef THREE_MOTORS
	motor[LeftM] = LeftFullSpeed;
#endif
	motor[LeftB] = LeftFullSpeed;
}

void RightForward()
{
	motor[RightF] = RightFullSpeed;
#ifdef THREE_MOTORS
	motor[RightM] = RightFullSpeed;
#endif
	motor[RightB] = RightFullSpeed;
}

void LeftBackward()
{
	motor[LeftF] = -LeftFullSpeed;
#ifdef THREE_MOTORS
	motor[LeftM] = -LeftFullSpeed;
#endif
	motor[LeftB] = -LeftFullSpeed;
}

void RightBackward()
{
	motor[RightF] = -RightFullSpeed;
#ifdef THREE_MOTORS
	motor[RightM] = -RightFullSpeed;
#endif
	motor[RightB] = -RightFullSpeed;
}

void AllForward()
{
	LeftForward();
	RightForward();
}

void AllBackward()
{
	LeftBackward();
	RightBackward();
}

int JSLeftH()
{
	if (vexRT[vexJSLeftH] > Joystick)
		return 1;
	if (vexRT[vexJSLeftH] < -Joystick)
		return -1;
	return 0;
}

int JSLeftV()
{
	if (vexRT[vexJSLeftV] > Joystick)
		return 1;
	if (vexRT[vexJSLeftV] < -Joystick)
		return -1;
	return 0;
}

int JSRightH()
{
	if (vexRT[vexJSRightH] > Joystick)
		return 1;
	if (vexRT[vexJSRightH] < -Joystick)
		return -1;
	return 0;
}

int JSRightV()
{
	if (vexRT[vexJSRightV] > Joystick)
		return 1;
	if (vexRT[vexJSRightV] < -Joystick)
		return -1;
	return 0;
}

void TankMode()
{
	switch (JSLeftV())
	{
	case 1:
		LeftForward();
		break;
	case -1:
		LeftBackward();
		break;
	default:
		LeftStop();
		break;
	}
	switch (JSRightV())
	{
	case 1:
		RightForward();
		break;
	case -1:
		RightBackward();
		break;
	default:
		RightStop();
		break;
	}
}

void OneJS()
{
	switch (JSLeftV())
	{
	case 1:
		switch (JSLeftH())
		{
		case 1:
			LeftForward();
			RightStop();
			break;
		case -1:
			LeftStop();
			RightForward();
			break;
		default:
			LeftForward();
			RightForward();
			break;
		}
		break;
	case -1:
		switch (JSLeftH())
		{
		case 1:
			LeftBackward();
			RightStop();
			break;
		case -1:
			LeftStop();
			RightBackward();
			break;
		default:
			LeftBackward();
			RightBackward();
			break;
		}
		break;
	default:
		switch (JSLeftH())
		{
		case 1:
			LeftForward();
			RightBackward();
			break;
		case -1:
			LeftBackward();
			RightForward();
			break;
		default:
			LeftStop();
			RightStop();
			break;
		}
		break;
	}
}

task Movement()
{
	while (true)
	{
		TankMode();
		wait1Msec(100);
	}
}

void UserLoop()
{
	startTask(Movement);
	while (true)
	{
		sleep(1);
	}
}
