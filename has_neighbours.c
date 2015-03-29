#include <stdio.h>
#define FIELD_SIZE 4

int field [FIELD_SIZE][FIELD_SIZE];

void display_field(void);
int has_neighbours(int i,int j);

int main()
{
		int i,j;
		int k,l,n,m,o,p;

		do
		{
				puts("Die Koordinaten\n"),

				scanf("%i",&k);
				scanf("%i",&l);
				scanf("%i",&m);
				scanf("%i",&n);

				for(i=0;i<FIELD_SIZE;i++)
						for(j=0;j<FIELD_SIZE;j++)
								field[i][j]=0;

				field[k][l]=2;
				field[m][n]=4;

				putchar('\n');

				for(i=0;i<FIELD_SIZE;i++)
						for(j=0;j<FIELD_SIZE;j++)
								printf("%i\t\t\t%i,%i\n",has_neighbours(i,j),i,j);

				putchar('\n');

				display_field();
		}while(i>=0&&j>=0);

		return 0;
}

int game_over(void)
{
		int i,j;

		printf("In game_over\n");

		for(i=0;i<FIELD_SIZE;i++)
				for(j=0;j<FIELD_SIZE;j++)
						if(field[i][j]==0||has_neighbours(i,j)==1)
						{
								return 0;
						}
						
		return 1;
}

void display_field(void)
{
		int i,j;
	   
		
		for(i=0;i<FIELD_SIZE;i++)
		{
				for(j=0;j<FIELD_SIZE;j++)
				{
						printf("%i\t",field[i][j]);
				}
				putchar('\n');
		}  
		putchar('\n');
}

int has_neighbours(int i,int j)
{
		putchar('\n');
		
		if(field[i][j]==0)
		{	
				return 0;
		}
		
		if(i==0)
		{
				if(j==0)
				{
						if(field[i+1][j]==field[i][j]||
						   field[i][j+1]==field[i][j])
								return 1;
				}
				if(j==FIELD_SIZE-1)
				{
						if(field[i+1][j]==field[i][j]||
						   field[i][j-1]==field[i][j])
								return 1;
				}
				else
				{
						if(field[i+1][j]==field[i][j]||
						   field[i][j+1]==field[i][j]||
						   field[i][j-1]==field[i][j])
								return 1;
				}
		}
		if(i==FIELD_SIZE-1)
		{
				if(j==0)
				{
						if(field[i-1][j]==field[i][j]||
						   field[i][j+1]==field[i][j])
								return 1;
				}
				if(j==FIELD_SIZE-1)
				{
						if(field[i-1][j]==field[i][j]||
						   field[i][j+1]==field[i][j])
								return 1;
				}
				else
				{
						if(field[i-1][j]==field[i][j]||
						   field[i][j+1]==field[i][j]||
						   field[i][j-1]==field[i][j])
								return 1;
				}
		}
		else
		{
				if(j==0)
				{
						if(field[i+1][j]==field[i][j]||
						   field[i-1][j]==field[i][j]||
						   field[i][j+1]==field[i][j])
								return 1;
				}
				if(j==FIELD_SIZE-1)
				{
						if(field[i+1][j]==field[i][j]||
						   field[i-1][j]==field[i][j]||
						   field[i][j-1]==field[i][j])
								return 1;
				}
				else
				{
						if(field[i+1][j]==field[i][j]||
						   field[i-1][j]==field[i][j]||
						   field[i][j+1]==field[i][j]||
						   field[i][j-1]==field[i][j])
								return 1;
				}
		}
		return 0;
}
