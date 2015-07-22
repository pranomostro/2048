#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define FLDSIZE 4

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
	int i,j;

	for(i=0;i<=FLDSIZE-2;i++)
		for(j=i+1;j<=FLDSIZE-1;j++)
			if(line[i]==line[j])
			{
				line[i]+=line[j], line[j]=0;
				break;
			}
			else if(line[j]!=0||line[i]==0)
				break;
	for(i=-1;i<=FLDSIZE-2;i++)
		for(j=i+1;j<=FLDSIZE-1&&line[i+1]==0;j++)
			if(line[j]!=0)
			{
				line[i+1]=line[j];line[j]=0;
				break;
			}
}
