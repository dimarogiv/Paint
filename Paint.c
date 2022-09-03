#include <stdio.h>
#include <gconio.h>
#define w 50
#define h 20

void create_box();
void create_box_v();
void clearscr();

int main (void)
{
	clearscr();
	int x=50,y=20,col;
	create_box(x,y,1,h,3);
	create_box(x,y,w,1,3);
	char ch = 0, ch2 = 0;
	while (ch != '.'){
		getch();
		getch();
		ch = getch();
		switch(ch){
			case 65:{
				create_box(x,y+h-1,w,1,0);
				y--;
				create_box(x,y,w,1,col);
				break;
			}
			case 66:{
				create_box(x,y,w,1,0);
				y++;
				create_box(x,y+h-1,w,1,col);
				break;
			}

			case 67:{
				create_box_v(x,y,1,h,0);
				x++;
				create_box_v(x+w-1,y,1,h,col);
				break;
			}

			case 68:{
				create_box_v(x+w-1,y,1,h,0);
				x--;
				create_box_v(x,y,1,h,col);
				break;
			}
			
			default: {
				col=(int)ch-47;
			}
		}
	}
	return 0;
}

void create_box_v(int x, int y, int length, int width, int color){
	gotoxy(x+1,y);	
	printf("\033[0;%d;%dm",37,40+color);
	for(int i=1;i<=width;i++){
		printf(" ");
		gotoxy(x+1,y+i);
	}
	gotoxy(1,1);
}

void create_box(int x, int y, int length, int width, int color){
	gotoxy(x+1,y);	
	printf("\033[0;%d;%dm",37,40+color);
	for(int i=1;i<=width;i++){
		for(int o=1;o<=length;o++)printf(" ");
		gotoxy(x+1,y+i);
	}
	gotoxy(1,1);
}

void clearscr(void){
	gotoxy(1,1);
	printf("\033[0;%d;%dm",37,40);
	for(int i=1;i<=65;i++){
		for(int o=1;o<=160;o++)printf(" ");
		gotoxy(1,0+i);
	}
}

