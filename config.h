/*
	Edit this file for a (minimal) configuration of 2048,
	after every change a recompilation is needed.
*/

#define FIELD_SIZE 4

/*
	The command for clearing the terminal window after
	each move.
*/

const char* CLEAR="clear";

/* Keys for moving the tiles. */

enum keys
{
	UP='w',
	LEFT='a',
	DOWN='s',
	RIGHT='d'
};
