#include<LPC214x.h>
void pll()
{
	PLL0CON=0x01;
	PLL0CFG=0x24;
	PLL0FEED=0xaa;
	PLL0FEED=0x55;
	while(!(PLL0STAT&(1<<10)));
	PLL0CON=0x03;
	PLL0FEED=0xaa;
	PLL0FEED=0x55;
	VPBDIV=0x01;
}
int main()
{
	int c;
	PINSEL0=0x00000005;
	U0LCR=0x83;
	U0DLL=0x87;
	U0DLM=0x01;
	U0LCR=0x03;
	pll();
	while(1)
	{
		while(!(U0LSR&0x01));
		c=U0RBR;
		c++;
		while(!(U0LSR&0x20));
		U0THR=c;
	}
}