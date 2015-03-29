#include <stdio.h>

#define FIELD_SIZE 4

int field [FIELD_SIZE][FIELD_SIZE];
int filled;

void fill_free(void);
void display_field(void);

int main()
{
		while(1)
		{
				getchar();
				fill_free();
				display_field();

				printf("%i\n",filled);
		}
}

void display_field(void)
{
		 int i,j;
		 filled=0;

		 for(i=0;i<FIELD_SIZE;i++)
		 {
				 for(j=0;j<FIELD_SIZE;j++)
				 {
						 printf("%i\t",field[i][j]);

						 if(field[i][j]!=0)
								 filled++;
				 }
				 putchar('\n');
		 }	

		 putchar('\n');
 }

void fill_free(void)
{
		int i,j;

		i=rand()%FIELD_SIZE;
		j=rand()%FIELD_SIZE;

		while(field[i][j]!=0)
		{
				printf("i=%i\tj=%i\n",i,j);

				i=rand()%FIELD_SIZE;
				j=rand()%FIELD_SIZE;
		}

		field[i][j]=2;
}
