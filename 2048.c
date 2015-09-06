#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "config.h"

int shifted;
int field [FIELD_SIZE][FIELD_SIZE];

void init(void);
void fill_free(void);
void display_field(void);

void shift_numbers(char c);
void shift(int* line);

int game_over(void);
int has_neighbours(int i, int j);

int main(void)
{
	init();
	display_field();

	do
	{
		shift_numbers(getchar());

		if(shifted)
			fill_free();

		display_field();

		shifted=0;
	}
	while(game_over()==0);

	printf("Game over, %s\n", game_over()==-1?"you won.":"you lost.");

	return 0;
}

void init(void)
{
	int i, j;

	shifted=1;

	srand((unsigned)time(NULL));

	for(i=0; i<FIELD_SIZE; i++)
		for(j=0; j<FIELD_SIZE; j++)
			field [i][j]=0;

	fill_free();
}

void fill_free(void)
{
	int i, j;

	do
	{
		i=rand()%FIELD_SIZE;
		j=rand()%FIELD_SIZE;
	}
	while(field[i][j]!=0);

	field[i][j]=((rand()%4)==0 ? 4 : 2);
}

void display_field(void)
{
	int i, j, errval;

	errval=system(CLEAR);

	if(errval!=0)
	{
		fprintf(stderr, "error: could not execute shell command %s, exiting.\n", CLEAR);
		exit(1);
	}

	for(i=0; i<FIELD_SIZE; i++)
	{
		for(j=0; j<FIELD_SIZE; j++)
		{
			if(field[i][j]==0)
				putchar('\t');
			else
				printf("%i\t", field[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
}

void shift_numbers(char c)
{
	int i,j;
	int line[FIELD_SIZE];

	for(i=0; i<FIELD_SIZE; i++)
		switch(c)
		{
		case LEFT:
			shift(field[i]);
			break;
		case RIGHT:
			for(j=FIELD_SIZE-1; j>=0; j--)
				line[FIELD_SIZE-1-j]=field[i][j];
			shift(line);
			for(j=FIELD_SIZE-1; j>=0; j--)
				field[i][j]=line[FIELD_SIZE-1-j];
			break;
		case DOWN:
			for(j=FIELD_SIZE-1; j>=0; j--)
				line[FIELD_SIZE-1-j]=field[j][i];
			shift(line);
			for(j=FIELD_SIZE-1; j>=0; j--)
				field[j][i]=line[FIELD_SIZE-1-j];
			break;
		case UP:
			for(j=0; j<=FIELD_SIZE-1; j++)
				line[j]=field[j][i];
			shift(line);
			for(j=0; j<=FIELD_SIZE-1; j++)
				field[j][i]=line[j];
			break;
		}
}

void shift(int* line)
{
	int i, j;

	for(i=0; i<=FIELD_SIZE-2; i++)
		for(j=i+1; j<=FIELD_SIZE-1; j++)
			if(line[i]==line[j])
			{
				line[i]+=line[j], line[j]=0; shifted=1;
				break;
			}
			else if(line[j]!=0||line[i]==0)
				break;

	for(i=-1; i<=FIELD_SIZE-2; i++)
		for(j=i+1; j<=FIELD_SIZE-1&&line[i+1]==0; j++)
			if(line[j]!=0)
			{
				line[i+1]=line[j]; line[j]=0; shifted=1;
				break;
			}
}

int game_over(void)
{
	int i, j;

	for(i=0; i<FIELD_SIZE; i++)
		for(j=0; j<FIELD_SIZE; j++)
		{
			if(field[i][j]==2048)
				return -1;
			if(field[i][j]==0||has_neighbours(i, j)==1)
				return 0;
		}
	return 1;
}

int has_neighbours(int i, int j)
{
	if((i==0&&field[i+1][j]==field[i][j])
	||(i==FIELD_SIZE-1&&field[i-1][j]==field[i][j])
	||(i>0&&i<FIELD_SIZE-1&&(field[i+1][j]==field[i][j]||field[i-1][j]==field[i][j]))
	||(j==0&&field[i][j+1]==field[i][j])
	||(j==FIELD_SIZE-1&&field[i][j-1]==field[i][j])
	||(j>0&&j<FIELD_SIZE-1&&(field[i][j+1]==field[i][j]||field[i][j-1]==field[i][j])))
		return 1;
	return 0;
}
