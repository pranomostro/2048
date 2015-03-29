#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	srand((unsigned)time(NULL));

	while(1)
	{
		int i=rand()%4;
		char c;
		
		switch(i)
		{
		case 0:
			c='w';
			break;
		case 1:
			c='a';
			break;
		case 2:
			c='s';
			break;
		case 3:
			c='d';
			break;
		default:
			break;
		}
		putchar(c);
		
		for(int j=0;j<=16777216;j++)
			;
	}
}
