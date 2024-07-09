#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define wPi_PWM1 23
#define TRIG 8
#define ECHO 9

int main()
{
	extern double Dist();
	extern void calcRange();
	extern void playSound(int um, int rythm);
	extern int song[];
	extern int rythm[];
	
	wiringPiSetup();  
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT); 
	
	wiringPiSetup();
	pinMode(wPi_PWM1, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	calcRange();
	
	
	for(int i=0; song[i] != -1;i++)
	{
		playSound(song[i], rythm[i]);
		printf("Distance : %f(cm)\n", Dist());
	}
	return 0;
}
