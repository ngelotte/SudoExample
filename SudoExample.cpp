// SudoExample.cpp : Defines the entry point for the application.
//

#include "SudoExample.h"
#include <iostream>		// Include all needed libraries here
extern "C" {
#include <wiringPi.h>
}

using namespace std;		// No need to keep using “std”

int main()
{
	int l;
	if (wiringPiSetup() == -1)
	{
		exit(1);
	}

	pinMode(1, PWM_OUTPUT);	// Configure GPIO1 as a PWM_OUTPUT

	// Main program loop
	while (1)
	{

		for (l = 0; l < 1024; ++l)
		{
			pwmWrite(1, l);
			delay(1);
		}

		for (l = 1023; l >= 0; --l)
		{
			pwmWrite(1, l);
			delay(1);
		}

	}
}
