// gpio port is used, port0 - 29 pins, port1 - 16 pins
#include<lpc21xx.h>
void delay()
{
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<4000;j++);
}
int main()
{
	IO0DIR=0x00000000;
	IO1DIR=0x00ff0000;
	while(1)
	{
		if(IO0PIN & 0x00004000)
		{
			IO1SET=0x00550000;
			delay();
			IO1CLR=0x00550000;
			delay();
		}
		else
		{
			IO1SET=0x00aa0000;
			delay();
			IO1CLR=0x00aa0000;
			delay();
		}
	}
	return 0;
}