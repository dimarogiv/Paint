#include <stdio.h>
#include <conio.h>

void create_box(int x, int y, int length, int width, int color);
bool move_box(int x, int y, int length, int width, int color, int direction, bool mode);
void clearscr(void);

int main (void)
{
        clearscr();
        int x=50,y=20,high=1,width=1,col;
        char ch = 0; 
        bool mode=0;
        while (ch != '.'){
                for(ch=27;ch==27||ch==91;ch=getch());
                switch(ch){
                        case 65:{
                                        move_box(x,y,width,1,col,1,mode);
                                        y--;
                                        break;
                                }
                        case 66:{
                                        move_box(x,y,width,1,col,2,mode);
                                        y++;
                                        break;
                                }

                        case 67:{
                                        move_box(x,y,1,high,col,3,mode);
                                        x++;
                                        break;
                                }

                        case 68:{
                                        move_box(x+width-1,y,1,high,col,4,mode);
                                        x--;
                                        break;
                                }
                        case 112:{
                                         mode=1;
                                         break;
                                 }
                        case 109:{
                                         mode=0;
                                         break;
                                 }
                        case 104:{
                                         high=getch()-48;
                                         break;
                                 }
                        case 119:{
                                         width=getch()-48;
                                         break;
                                 }
                        default:{
                                        if(ch<56&&ch>47)col=ch-48;
                                }
                }
        }
        return 0;
}

bool move_box(int x, int y, int length, int width, int color, int direction, bool mode){ // 1=up, 2=down, 3=right, 4=left
        switch(direction){
                case 1:
                        if(mode==0)create_box(x,y+width,length,1,0);
                        create_box(x,y,length,1,color);
                        break;
                case 2:
                        if(mode==0)create_box(x,y,length,1,0);
                        create_box(x,y+width,length,1,color);
                        break;
                case 3:
                        if(mode==0)create_box(x,y,1,width,0);
                        create_box(x+length,y,1,width,color);
                        break;
                case 4:
                        if(mode==0)create_box(x+length,y,1,width,0);
                        create_box(x,y,1,width,color);
                        break;
                default:
                        return 1;
        }
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

