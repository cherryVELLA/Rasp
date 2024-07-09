#include <stdio.h>
#include <wiringPi.h>

#define wPi_PWM1 23

int PSC = 19;
int RANGE = 100;
int DUTY = 50;

enum { DO = 0, Do, RE, Re, MI, FA, Fa, SL, Sl, LA, La, CI};
int pitch[] = {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};
int range[12];
int song[] = {SL, SL, LA, LA, SL, SL, MI, SL, SL, MI, MI, RE, SL, SL, 
			  LA, LA, SL, SL, MI, SL, MI, RE, MI, DO, -1};
int rythm[] = {4,4,4,4,4,4,8,4,4,4,4,10,4,4,4,4,4,4,8,4,4,4,4,10, -1};

void calcRange() // Calc Range values using Pitch data
{
	for(int i = 0; i<12; i++)
	{
		range[i] = 19200000/(pitch[i]*19);   // 19.2MHz / (freq * 19) -> 1MHz (delay calculate)
	}
}

void playSound(int um, int rythm)   // um : pitch, rythm
{	
	extern double Dist();
	
	pwmSetClock(PSC);   //Prescaler : ~ 1MHz
	pwmSetRange(range[um]);  // Range
	pwmWrite(wPi_PWM1, DUTY);
	delay(rythm * Dist());
	pwmWrite(wPi_PWM1, 0);   // after delay turnoff
	delay(50);
}
