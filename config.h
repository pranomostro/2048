/*
	Edit this file for a (minimal) configuration of 2048,
	after every change of the configuration a recompile is needed.
*/

#define FIELD_SIZE 4

/*
	The command for clearing the terminal window.
	This depends on you OS, of course
*/
char* CLEAR="clear";

/* Keys for moving the tiles. */
enum keys
{
	UP='v',
	LEFT='u',
	DOWN='i',
	RIGHT='a'
};
