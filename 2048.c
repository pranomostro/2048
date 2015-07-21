#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FIELD_SIZE 4
#define CRTFIELD field[i][j]

#define UP 'v'
#define LEFT 'u'
#define DOWN 'i'
#define RIGHT 'a'

int shifted;
int field [FIELD_SIZE][FIELD_SIZE];

void init(void);
void fill_free(void);
void display_field(void);

void shift_up(void);
void shift_down(void);
void shift_left(void);
void shift_right(void);

void shift_numbers(char c);

int game_over(void);
int has_neighbours(int i,int j);

int main()
{
	char c;

	init();
	display_field();

	while(game_over()==0)
	{
		c=getchar();
		shift_numbers(c);

		if(shifted)
			fill_free();

		display_field();

		shifted=0;
	}

	printf("Game over.\n");
	printf("%s\n", game_over()==-1 ? "You won." : "You lost.");

	return 0;
}

void init(void)
{
	int i,j;

	shifted=1;

	srand((unsigned)time(NULL));

	for(i=0;i<FIELD_SIZE;i++)
		for(j=0;j<FIELD_SIZE;j++)
			field [i][j]=0;

	fill_free();
}

void fill_free(void)
{
	int i,j,z;

	i=rand()%FIELD_SIZE;
	j=rand()%FIELD_SIZE;

	while(CRTFIELD!=0)
	{
		i=rand()%FIELD_SIZE;
		j=rand()%FIELD_SIZE;
	}

	z=rand()%4;

	CRTFIELD=(z==0 ? 4 : 2);
}

void display_field(void)
{
	int i,j;

	system("clear");

	for(i=0;i<FIELD_SIZE;i++)
	{
		for(j=0;j<FIELD_SIZE;j++)
		{
			if(CRTFIELD==0)
				putchar('\t');
			else
				printf("%i\t",CRTFIELD);
		}
		putchar('\n');
	}
	putchar('\n');
}

void shift_numbers(char c)
{
	switch(c)
	{
	case DOWN:
		break;
	case UP:
		break;
	case LEFT:
		break;
	case RIGHT:
		break;
	default:
		break;
	}
}

int game_over(void)
{
	int i,j;

	for(i=0;i<FIELD_SIZE;i++)
		for(j=0;j<FIELD_SIZE;j++)
		{
			if(CRTFIELD==2048)
				return -1;
			if(CRTFIELD==0||has_neighbours(i,j)==1)
				return 0;
		}
	return 1;
}

int has_neighbours(int i,int j)
{
	if(CRTFIELD==0)
	{
		return 0;
	}

	if(i==0&&field[i+1][j]==CRTFIELD)
		return 1;
	if(i==FIELD_SIZE-1&&field[i-1][j]==CRTFIELD)
		return 1;
	if(i>0&&i<FIELD_SIZE-1&&(field[i+1][j]==CRTFIELD||field[i-1][j]==CRTFIELD))
		return 1;
	if(j==0&&field[i][j+1]==CRTFIELD)
		return 1;
	if(j==FIELD_SIZE-1&&field[i][j-1]==CRTFIELD)
		return 1;
	if(j>0&&j<FIELD_SIZE-1&&(field[i][j+1]==CRTFIELD||field[i][j-1]==CRTFIELD))
		return 1;
	return 0;
}
