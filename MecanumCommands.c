
const int FullSpeed = 127;
const int Joystick = 30;

void RightTurn()
{
motor[chassisFR] = FullSpeed;
motor[chassisBR] = FullSpeed;
motor[chassisFL] = -FullSpeed;
motor[chassisBL] = -FullSpeed;
}

void LeftTurn()
{
motor[chassisFL] = FullSpeed;
motor[chassisBL] = FullSpeed;
motor[chassisFR] = -FullSpeed;
motor[chassisBR] = -FullSpeed;
}

void Forward()
{
motor[chassisFR] = FullSpeed;
motor[chassisBR] = FullSpeed;
motor[chassisFL] = FullSpeed;
motor[chassisBL] = FullSpeed;
}

void Backward()
{
motor[chassisFR] = -FullSpeed
motor[chassisBR] = -FullSpeed
motor[chassisFL] = -FullSpeed
motor[chassisBL] = -FullSpeed
}

void RightStrafe()
{
motor[chassisFR] = -FullSpeed
motor[chassisBR] = FullSpeed
motor[chassisFL] = FullSpeed
motor[chassisBL] = -FullSpeed
}
