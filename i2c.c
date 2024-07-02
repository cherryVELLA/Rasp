#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

int main()
{
	int fd = wiringPiI2CSetup(0X48);       
	
	int v1, v2, v3;
	float f1, f2, f3;
	
	while(1)
	{
		wiringPiI2CWrite(fd, 0);                    // ch00 (VR) select
		v1 = wiringPiI2CRead(fd);
		f1 = (float)((v1/255.0)*5.0);
		delay(100);
		
		wiringPiI2CWrite(fd, 1);                    // ch01 (VR) select
		v2 = wiringPiI2CRead(fd);
		f2 = (float)((v2/255.0)*5.0);
		delay(100);
		
		wiringPiI2CWrite(fd, 3);                    // ch03 (VR) select
		v3 = wiringPiI2CRead(fd);
		f3 = (float)((v3/255.0)*5.0);
				printf("VR input level = %d %d %d(%4.1fV, %4.1fV, %4.1fV)\n", v1, v2, v3, f1, f2, f3);
		delay(100);
	}
}
