#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define NOTYET -1

void shift(int* line);

int main(void)
{
	errno=0;
	int line[4];

	while(errno==0)
	{
		scanf("%d-%d-%d-%d", line, line+1, line+2, line+3);
		shift(line);
		printf("%d-%d-%d-%d\n",line[0], line[1], line[2], line[3]);
	}
	return 0;
}

void shift(int* line)
{
	int i, j, add=0, lastpos=NOTYET;

	for(i=0;i<=3;i++)
		if(line[i]&&lastpos!=NOTYET)
			line[lastpos]=line[i], lastpos++,line[i]=0;
		else if(line[i]==0&&lastpos==NOTYET)
			lastpos=i;

	for(i=0;i<=2;i++)
		for(j=i;j<=2;j++)
		{
			if(line[j]==line[j+1]&&line[j]&&add==0)
				line[j]+=line[j+1], line[j+1]=0, add=1;
			add=0;
		}
}
