#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define TRIG 8
#define ECHO 9

double Dist()
{
	digitalWrite(TRIG, 1);
	delayMicroseconds(10);
	digitalWrite(TRIG, 0);
	delayMicroseconds(200);  

	while(digitalRead(ECHO) != 1); 
	int t1 = micros();  
	while(digitalRead(ECHO) != 0);
	int t2 = micros();

	return (t2 - t1) * 0.017;
}
