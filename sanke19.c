//   WRITTEN BY MOHAMMAD AHMADI
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define NROW 24
#define NCOLUMN 79
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define COLOR_OF_FINISH 118
#define COLOR_OF_YOUR_SNAKE 3
#define COLOR_OF_COM_SNAKE 5
#define COLOR_EMPTY 1
#define SPEED_SNAKE 50
#define BEGIN_YOUR_SNAKE 9
#define BEGIN_COM_SNAKE 18

struct snake {
  int row,col;
} snake1[100],snake2[100];

void gotoxy(short X,short Y);
void set_direction(struct snake s[100],char dir);

int X,Y,i,snake_length=13;
char direction1='\n',direction2=RIGHT,keypress;

int main(){
	int tmp1,tmp2,count_for_up,count_for_down,count_for_right,count_for_left,flag=1,flag2=0;
	struct snake j; 
	struct snake p;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for(i=0;i<=snake_length;i++){
		snake2[i].row=BEGIN_COM_SNAKE;
		snake1[i].row=BEGIN_YOUR_SNAKE;
	}
	do{
		gotoxy(30,6);
		SetConsoleTextAttribute(hConsole,COLOR_EMPTY);
		printf("                                  ");
		gotoxy(30,9);
		SetConsoleTextAttribute(hConsole,COLOR_EMPTY);
		printf("                                  ");
		do{
			if (kbhit()){
				keypress=(char)getch();
				if((keypress==RIGHT)||(keypress==LEFT)||(keypress==UP)||(keypress==DOWN)){
		    		if(keypress==RIGHT && direction1==LEFT)
		    			keypress=LEFT;
		    		else if(keypress==LEFT && direction1==RIGHT)
		    			keypress=RIGHT;
		    		else if(keypress==UP && direction1==DOWN)
		    			keypress=DOWN;
		    		else if(keypress==DOWN && direction1==UP)
		    			keypress=UP;
		    		direction1 = keypress;
				}
			}if(direction1!='\n'){
				j=snake1[snake_length];
				p=snake2[snake_length];
	    		if((snake1[snake_length].row)==NROW && direction1==DOWN){
	    			(snake1[snake_length].row)=-1;
	    		}
	    		else if((snake1[snake_length].col)==NCOLUMN && direction1==RIGHT)
	    			(snake1[snake_length].col)=-1;
	    		else if((snake1[snake_length].row)==0 && direction1==UP){
	    			(snake1[snake_length].row)=NROW+1;
	    		}
	    		else if((snake1[snake_length].col)==0 && direction1==LEFT)
	    			(snake1[snake_length].col)=NCOLUMN+1;
	    		if((snake2[snake_length].row)==NROW && direction2==DOWN){
	    			(snake2[snake_length].row)=-1;
	    		}
	    		else if((snake2[snake_length].col)==NCOLUMN && direction2==RIGHT)
	    			(snake2[snake_length].col)=-1;
	    		else if((snake2[snake_length].row)==0 && direction2==UP){
	    			(snake2[snake_length].row)=NROW+1;
	    		}
	    		else if((snake2[snake_length].col)==0 && direction2==LEFT)
	    			(snake2[snake_length].col)=NCOLUMN+1;
	    		gotoxy(snake1[0].col,snake1[0].row);
	    		printf(" ");
	    		gotoxy(snake2[0].col,snake2[0].row);
	    		printf(" ");

	    		for (i=1;i<snake_length;i++){
	    			snake1[i-1]=snake1[i];
	    			snake2[i-1]=snake2[i];
				}
				snake1[snake_length-1]=j;
				snake2[snake_length-1]=p;


				for(i=0;i<=snake_length;i++){
					if(direction2==RIGHT && snake2[snake_length].row==snake1[i].row &&  snake2[snake_length].col+1==snake1[i].col){
						for(tmp1=1,count_for_up=1;tmp1<NROW+1;tmp1++,count_for_up++){
							for(tmp2=0;tmp2<=snake_length;tmp2++){
								if((snake2[snake_length].row-tmp1)==snake1[tmp2].row && snake2[snake_length].col==snake1[tmp2].col){
									flag=0;
									break;
								}
							}
							if(flag==0)
								break;
						}

						flag=1;
						for(tmp1=1,count_for_down=1;tmp1<NROW+1;tmp1++,count_for_down++){
							for(tmp2=0;tmp2<=snake_length;tmp2++){
								if((snake2[snake_length].row+tmp1)==snake1[tmp2].row && snake2[snake_length].col==snake1[tmp2].col){
									flag=0;
									break;
								}
							}
							if(flag==0)
								break;
						}
						if(count_for_up>=count_for_down)
							direction2=UP;
						else
							direction2=DOWN;
						break;
					}

					else if(direction2==LEFT && snake2[snake_length].row==snake1[i].row &&  snake2[snake_length].col-1==snake1[i].col){
						for(tmp1=1,count_for_up=1;tmp1<NROW+1;tmp1++,count_for_up++){
							for(tmp2=0;tmp2<=snake_length;tmp2++)
								if((snake2[snake_length].row-tmp1)==snake1[tmp2].row && snake2[snake_length].col==snake1[tmp2].col){
									flag=0;
									break;
								}
							if(flag==0)
								break;
						}
						flag=1;
						for(tmp1=1,count_for_down=1;tmp1<NROW+1;tmp1++,count_for_down++){
							for(tmp2=0;tmp2<=snake_length;tmp2++){
								if((snake2[snake_length].row+tmp1)==snake1[tmp2].row && snake2[snake_length].col==snake1[tmp2].col){
									flag=0;
									break;
								}
							}
							if(flag==0)
								break;
						}
						if(count_for_up>=count_for_down)
							direction2=UP;
						else
							direction2=DOWN;
						break;
					}

					else if(direction2==UP && snake2[snake_length].col==snake1[i].col &&  snake2[snake_length].row-1==snake1[i].row){
						for(tmp1=1,count_for_right=1;tmp1<NCOLUMN+1;tmp1++,count_for_right++){
							for(tmp2=0;tmp2<=snake_length;tmp2++){
								if((snake2[snake_length].col+tmp1)==snake1[tmp2].col && snake2[snake_length].row==snake1[tmp2].row){
									flag=0;
									break;
								}
							}
							if(flag==0)
								break;
						}
						flag=1;
						for(tmp1=1,count_for_left=1;tmp1<NCOLUMN+1;tmp1++,count_for_left++){
							for(tmp2=0;tmp2<=snake_length;tmp2++)
								if((snake2[snake_length].col-tmp1)==snake1[tmp2].col && snake2[snake_length].row==snake1[tmp2].row){
									flag=0;
									break;
								}
							if(flag==0)
								break;
						}
						if(count_for_right>=count_for_left)
							direction2=RIGHT;
						else
							direction2=LEFT;
						break;
					}

					else if(direction2==DOWN && snake2[snake_length].col==snake1[i].col &&  snake2[snake_length].row+1==snake1[i].row){
						for(tmp1=1,count_for_right=1;tmp1<NCOLUMN+1;tmp1++,count_for_right++){
							for(tmp2=0;tmp2<=snake_length;tmp2++)
								if((snake2[snake_length].col+tmp1)==snake1[tmp2].col && snake2[snake_length].row==snake1[tmp2].row){
									flag=0;
									break;
								}
							if(flag==0)
								break;
						}
						flag=1;
						for(tmp1=1,count_for_left=1;tmp1<NCOLUMN+1;tmp1++,count_for_left++){
							for(tmp2=0;tmp2<=snake_length;tmp2++)
								if((snake2[snake_length].col-tmp1)==snake1[tmp2].col && snake2[snake_length].row==snake1[tmp2].row){
									flag=0;
									break;
								}
							if(flag==0)
								break;
						}
						if(count_for_right>=count_for_left)
							direction2=RIGHT;
						else
							direction2=LEFT;
						break;
					}
				}

				set_direction(snake1,direction1);
	    		set_direction(snake2,direction2);
	    	
	    		for (i=0;i<=snake_length;i++){
	    			gotoxy(snake1[i].col,snake1[i].row);
					SetConsoleTextAttribute(hConsole,COLOR_OF_YOUR_SNAKE);
	    			printf("o");
	    		}
	    		for (i=0;i<=snake_length;i++){
	    			gotoxy(snake2[i].col,snake2[i].row);
					SetConsoleTextAttribute(hConsole,COLOR_OF_COM_SNAKE);
	    			printf("x");
	    		}
	    		for(i=0;i<snake_length;i++)
	    			if ( (snake1[snake_length].row)==(snake1[i].row) && (snake1[snake_length].col)==(snake1[i].col)){
	    				keypress='h';
	    				break; 
	    			}
	    		for(i=0;i<snake_length;i++)
	    			if ( (snake2[snake_length].row)==(snake2[i].row) && (snake2[snake_length].col)==(snake2[i].col)){
	    				keypress='h'; 
	    				break; 
	    			}
				for(i=0;i<snake_length;i++)
					if( ((snake1[snake_length].row)==(snake2[i].row) &&  (snake1[snake_length].col)==(snake2[i].col)) || ((snake2[snake_length].row)==(snake1[i].row) &&  (snake2[snake_length].col)==(snake1[i].col))){
	    				keypress='h';
	    				break;
					}
				flag2=0;
				if((direction2==RIGHT && direction1==LEFT) || (direction2==LEFT && direction1==RIGHT) || (direction2==UP && direction1==DOWN) || (direction2==DOWN && direction1==UP))
					flag2=1;
				if((snake1[snake_length].row==snake2[snake_length].row && snake1[snake_length].col==snake2[snake_length].col) && flag2==0){
    				keypress='h';
    				break;
				}
			}
			Sleep(SPEED_SNAKE);
		} while (keypress!='h');
		gotoxy(30,6);
		SetConsoleTextAttribute(hConsole,COLOR_OF_FINISH);
		printf("G A M E   O V E R");
		gotoxy(30,9); printf("Resume Game (y/n)? ");
		do{
			keypress=getch();
		}while((keypress!='y')&&(keypress!='n'));
	}while (keypress=='y');
	return 0;
}


void gotoxy(short X,short Y){
	COORD coord;
	coord.X=X;
	coord.Y=Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void set_direction(struct snake s[100],char dir){
  switch(dir){
    case(RIGHT): s[snake_length].row=s[snake_length].row;
                     s[snake_length].col=s[snake_length].col+1;
                     break;
    case(LEFT) : s[snake_length].row=s[snake_length].row;
                     s[snake_length].col=s[snake_length].col-1;
                     break;
    case(UP)   : s[snake_length].row=s[snake_length].row-1;
                     s[snake_length].col=s[snake_length].col;
                     break;
    case(DOWN) : s[snake_length].row=s[snake_length].row+1;
                     s[snake_length].col=s[snake_length].col;
  }
}
