#include<lpc214x.h>
void delay(unsigned int a);
void pll();
int main(void)
{
	IO1DIR=0x00ff0000;
	pll();
	while(1)
	{
		IOSET1=0x00aa0000;
		delay(1000);
		IOCLR1=0x00aa0000;
		delay(1000);
	}
	return 0;
}
	void pll()
	{
			PLL0CON=0x01;
			PLL0CFG=0x24;
			PLL0FEED=0xaa;
			PLL0FEED=0x55;
			while(!(PLL0STAT & (1<<10)));
			PLL0CON=0x03;
			PLL0FEED=0xaa;
			PLL0FEED=0x55;
			VPBDIV=0x01;
	}
	void delay(unsigned int x)
	{
		T0CTCR=0x0;
		T0TCR=0x00;
		T0PR=59999;
		T0TCR=0x02;
		T0TCR=0X01;
		while(T0TC<x);
		T0TCR=0x00;
		T0TC=0;
	}