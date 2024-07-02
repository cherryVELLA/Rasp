#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

int main()
{
	printf("\033[2J");
	printf("\033[1;1H]");
	int	fd = wiringPiI2CSetup(0X48);
	
	while(1)
	{
		wiringPiI2CWrite(fd, 00);                    // ch00 (VR) select
		int x = (wiringPiI2CRead(fd) * 80) / 255; // x = 0 ~ 255
		delay(100);
		
		wiringPiI2CWrite(fd, 01);                    // ch01 (VR) select
		wiringPiI2CRead(fd);
		int y = (wiringPiI2CRead(fd)*24) / 255;  // y = 0 ~ 24
		delay(100);
		
		printf("\033[%d;%dH*", y, x);   
		delay(200);
	}
	return 0;
}
