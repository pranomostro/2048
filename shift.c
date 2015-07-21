#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

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
	int i, j;

	for(i=0;i<=2;i++)
		for(j=i+1;j<=3;j++)
		{
			if(line[i]==line[i+1]&&line[i]!=0)
				line[i]+=line[i+1], line[i+1]=0;
			if(line[i]==0&&line[j]!=0)
				line[i]=line[j], line[j]=0;
		}
}
