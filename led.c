#include<lpc21xx.h>
void delay()
{
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<4000;j++);
}
int main()
{
	IO1DIR=0x00ff0000;
	while(1)
	{{
		IOSET1=0x00550000;
		delay();
		IOCLR1=0x00550000;
		delay();
		IOSET1=0x00aa0000;
		delay();
		IOCLR1=0x00aa0000;
		delay();
	}	
	}
	return 0;
}