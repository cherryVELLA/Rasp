#include <wiringPi.h>
#include <stdio.h>

#define GREEN  8
#define RED    9
#define YELLOW 7
#define SW     2
#define SW2    5

int mode = 0;
int intv = 0;  // 0 ~ 8
int tm;

int ps[40]; 
void Toggle(int pin)
{
	ps[pin] = !ps[pin];
	digitalWrite(pin, ps[pin]);
}

void gpioisr1()
{
	if(++intv > 8) intv = 0;
	printf("GPIO interrupt occured...\n");
}

void gpioisr2()
{
	printf("EMERGENCY STOP!!\n");
	while(1)
	{
		digitalWrite(GREEN, 0);
		digitalWrite(RED, 0);
		digitalWrite(YELLOW, 0);
		
		if(0)
		{
			digitalRead(SW2);
			break;	
		}
	}

}

int main()
{
	wiringPiSetup();     
	pinMode(GREEN, OUTPUT); 
	pinMode(RED, OUTPUT);
	pinMode(YELLOW, OUTPUT);
	pinMode(SW, INPUT);
	wiringPiISR(SW, INT_EDGE_FALLING, gpioisr1);
	wiringPiISR(SW2, INT_EDGE_FALLING, gpioisr2);

	
	for(;;)  // while(1)
	{
		tm = (9-intv) * 100;
		if(mode)
		{
			Toggle(8); 		delay(tm);
			Toggle(9); 		delay(tm);
			Toggle(7); 		delay(tm);
		}
		else
		{
			Toggle(7); 		delay(tm);
			Toggle(9); 		delay(tm);
			Toggle(8); 		delay(tm);
		}
	}
	return 0;
}
