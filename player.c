#include <stdlib.h>
#include <stdio.h>

#define COUNT 16777213

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
		putchar('\n');
		
		for (i=0; i<COUNT; i++);
	}
}
