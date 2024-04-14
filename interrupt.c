#include <LPC214x.h>
void delay(void);
void ext_int_init();
__irq void Ext_ISR(void);
int main(void)
{
	IODIR0 = 0x00000000;
	IO1DIR = 0x00FF0000;
	ext_int_init();
	while (1)
	{
		IO1SET = 0x00FF0000;
		delay();
		IO1CLR = 0x00FF0000;
		delay();
	}
}
void ext_int_init()
{
	EXTMODE = 0x2; // EINT1 is edge sensitive

	EXTPOLAR &= ~(0x2);					  // Falling edge sensitive
	PINSEL0 = 0x20000000;				  // P0.14 is configured as ENT1
	VICIntSelect &= ~(1 << 15);			  // EINT1 is assigned as FIQ
	VICVectAddr5 = (unsigned int)Ext_ISR; // VICVectAddr5 has the ISR address
	VICVectCntl5 = (1 << 5) | 15;		  // EINT1 is alloted to slot 5
	VICIntEnable = (1 << 15);			  // The interrupt is enabled
}
__irq void Ext_ISR(void)
{
	IO1SET = 0x00550000;
	delay();
	IO1CLR = 0x00550000;
	EXTINT |= 0x2; // clear the interrupt
	VICVectAddr = 0;
}
void delay()
{
	int i, j;
	for (i = 0; i < 2000; i++)
		for (j = 0; j < 2000; j++)
		{
		};
}