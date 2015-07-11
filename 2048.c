#include <stdio.h>

#define FIELD_SIZE 4
#define CRFLD field[i][j]

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
	int ended=0;
	do
	{
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
		printf("%s\n",game_over==-1 ? "You won." : "You lost.");
		printf("Want to play again?\t(y|n)\n");
		ended=1;
	}while(getchar()=='y');

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
	fill_free();
}

void fill_free(void)
{
	int i,j,z;

	i=rand()%FIELD_SIZE;
	j=rand()%FIELD_SIZE;

	while(CRFLD!=0)
	{
		i=rand()%FIELD_SIZE;
		j=rand()%FIELD_SIZE;
	}

	z=rand()%4;

	CRFLD=(z==0 ? 4 : 2);
}

void display_field(void)
{
	int i,j;

	system("clear");

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

void shift_down(void)
{
	int a,b;

	for(a=0;a<FIELD_SIZE;a++)
	{
		int added[FIELD_SIZE]={0,0,0,0};
		for(b=FIELD_SIZE-1;b>=0;b--)
		{
			if(field[b][a]!=0)
			{
				int c;
				int highest=c=b;

				while(c<FIELD_SIZE-1)
				{
					c++;
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
void shift_left(void)
{
	int a,b;

	for(a=0;a<FIELD_SIZE;a++)
	{
		int added[FIELD_SIZE]={0,0,0,0};
		for(b=0;b<FIELD_SIZE;b++)
		{
			if(field[a][b]!=0)
			{
				int c;
				int highest=c=b;
				while(c>0)
				{
					c--;
					if(field[a][c]==0)
						highest=c;

					if(field[a][c]!=0)
					{
						if(field[a][c]==field[a][b]&&added[c]==0)
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
					field[a][highest]=field[a][b];
					field[a][b]=0;
					shifted=1;
				}
				goto end;
			add:
				field[a][highest]+=field[a][b];
				field[a][b]=0;
				shifted=1;
				added[highest]=1;
			end:
				;
			}
		}
	}
}

void shift_right(void)
{
	int a,b;

	for(a=0;a<FIELD_SIZE;a++)
	{
		int added[FIELD_SIZE]={0,0,0,0};
		for(b=FIELD_SIZE-1;b>=0;b--)
		{
			if(field[a][b]!=0)
			{
				int c;
				int highest=c=b;

				while(c<FIELD_SIZE-1)
				{
					c++;
					if(field[a][c]==0)
						highest=c;

					if(field[a][c]!=0)
					{
						if(field[a][c]==field[a][b]&&added[c]==0)
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
					field[a][highest]=field[a][b];
					field[a][b]=0;
					shifted=1;
				}
				goto end;
			add:
				field[a][highest]+=field[a][b];
				field[a][b]=0;
				shifted=1;
				added[highest]=1;
			end:
				;
			}
		}
	}
}

void shift_numbers(char c)
{
	if(c==DOWN)
		shift_down();
	if(c==UP)
		shift_up();
	if(c==LEFT)
		shift_left();
	if(c==RIGHT)
		shift_right();
}

int game_over(void)
{
	int i,j;

	for(i=0;i<FIELD_SIZE;i++)
		for(j=0;j<FIELD_SIZE;j++)
		{
			if(CRFLD==2048)
				return -1;
			if(CRFLD==0||has_neighbours(i,j)==1)
				return 0;
		}
	return 1;
}

int has_neighbours(int i,int j)
{
	if(CRFLD==0)
	{
		return 0;
	}

	if(i==0&&field[i+1][j]==CRFLD)
		return 1;
	if(i==FIELD_SIZE-1&&field[i-1][j]==CRFLD)
		return 1;
	if(i>0&&i<FIELD_SIZE-1&&(field[i+1][j]==CRFLD||field[i-1][j]==CRFLD))
		return 1;
	if(j==0&&field[i][j+1]==CRFLD)
		return 1;
	if(j==FIELD_SIZE-1&&field[i][j-1]==CRFLD)
		return 1;
	if(j>0&&j<FIELD_SIZE-1&&(field[i][j+1]==CRFLD||field[i][j-1]==CRFLD))
		return 1;
	return 0;
}
