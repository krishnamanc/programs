#include<lpc214x.h>
int main()
{
	unsigned int val;
	val=0x000003ff;
	PINSEL1=0x01000000;
	SCS=0x03;
	FIO1MASK=0xff00ffff;
	FIO1DIR=0x00000000;
	FIO1PIN=0x00000000;
	AD0CR=0x00200E02;
	while(1)
	{
	AD0CR|=0x01000000;
	do{
	val=AD0DR1;
	}
	while((val&0x80000000)==0);
	FIO1PIN=(val<<8);
	}
	return 0;
}