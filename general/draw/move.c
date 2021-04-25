#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#define HEIGHT 30
#define STATHEIGHT HEIGHT + 8
#define WIDTH 80
#define MOVE 1
#define DRAW 2
#define CLEAR 3


/* reads from keypress, doesn't echo */
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
	if ( ch == 27 )
	{
		getchar();
		ch = getchar();
	}
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
		
//gotoxy() function definition
void gotoxy(int x,int y)	
{
	printf("%c[%d;%df",0x1B,y,x);
}

void cleanup()
{
	for ( int x = 1; x <= 80 ; x++)
		for ( int y = 1;y <= 3 ; y++)
			gotoxy(x, y), printf(" ");
}

int main ()
{
	int x=1, y=1, maxY=0 ;
	int mode = MOVE;
	char chrToPrint = '#';
	int flag = 0;
	cleanup();
	gotoxy(1, HEIGHT + 3 );
	printf("Operating Modes:\n\td -> draw\n\tm -> move\n\tc -> clear\n\tx -> exit\n");
	while ( 1 )
	{		
			switch(getch()) 
			{
				case 65:    // key up
					--y;
					break;
				case 66:    // key down
					++y;
					maxY = maxY < y ? y : maxY;
					break;
				case 67:    // key right
					++x;
					break;
				case 68:    // key left
					--x;
					break;
				case 'm':    // key left
					mode = MOVE;
					break;
				case 'd':    // key left
					mode = DRAW;
					chrToPrint = '#';
					break;
				case 'c':    // key left
					mode = CLEAR;
					chrToPrint = ' ';
					break;
				case 'x':    // key left
					gotoxy(1, STATHEIGHT + 1);
					return 0;
					break;
			}
			
			x = x <= WIDTH ? x : WIDTH;
			x = x >= 1 ? x : 1;
			
			y = y >= 1 ? y : 1;
			y = y <= HEIGHT ? y : HEIGHT;
			
			gotoxy(1, STATHEIGHT ); //move cursor position
			printf("x: %d  y: %d" , x , y);
			
			gotoxy(x,y); //move cursor position
			if ( mode != MOVE)
				printf("%c",chrToPrint); //print message
			flag = 0;
	}
	gotoxy(1, STATHEIGHT + 1 );
	return 0;
}
