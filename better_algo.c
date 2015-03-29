#include <stdio.h>

#define FIELD_SIZE 4
#define CRFLD field[i][j]

int shifted;
int field [FIELD_SIZE][FIELD_SIZE];

void shift_up(void);
void display_field(void);

int main()
{
		display_field();
		getchar();
		shift_up();
		display_field();
}

void display_field(void)
{
		int i,j;
		
		for(i=0;i<FIELD_SIZE;i++)
		{
				for(j=0;j<FIELD_SIZE;j++)
				{
						if(CRFLD==0)
								putchar('\t');
						else
								printf("%i\t",CRFLD);
				}
				putchar('\n');
		} 
		putchar('\n');
}

void shift_up(void)
{		
		int a,b;

		for(a=0;a<FIELD_SIZE;a++)
		{
				int added[FIELD_SIZE]={0,0,0,0};
				for(b=0;b<FIELD_SIZE;b++)
				{
						if(field[b][a]!=0)
						{
								int c;
								int highest=c=b;
								while(c>0)
								{		
										c--;
										if(field[c][a]==0)
												highest=c;

										if(field[c][a]!=0)
										{
												if(field[c][a]==field[b][a]&&added[c]==0)
												{
														highest=c;
														goto add;
												}
												else
														break;
										}										
								}

								if(highest!=b)
								{
										field[highest][a]=field[b][a];
										field[b][a]=0;
										shifted=1;
								}
								goto end;
						add:
								field[highest][a]+=field[b][a];
								field[b][a]=0;
								shifted=1;
								added[highest]=1;
						end:
								;
						}
				}
		}
}
