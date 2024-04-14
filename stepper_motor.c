#include<LPC214x.h>
unsigned long i;
void delay(unsigned int);
int main()
{
	int a=250;
	IO1DIR=0x00ff0000;
	i=0x00010000;
	while(a)
	{
		IO1SET=i;
		delay(10000);
		IO1CLR=0x00ff0000;
		i=i<<1;
		if(i==0x00100000)
		{
		i=0x00010000;
		a--;
		}
	}
	void delay(unsigned int count)
	{
		unsigned int i,j=0;
		for(i=0;i<=count;i++){
		for(j=0;j<=90;j++){}
		}
	}
}