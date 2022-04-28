#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gameArea(char tahta[][30]); //This function is filling the bound of the array.
int dice(void); // it produces random numbers between [1-6]
int startGame(void); // it decides who is going to start firstly, and it returns who it is as a value.
int moving(char tahta[][30], int ilk); // this is the moving function. It will be explained below..
void printMap(char tahta[][30]); // prints the game area (not the function!!!) with colors.


int main()
{
	int baslangic;
	char c;
	int check;
	int times = 0; // after player1 and player2's dice then it helps us to print the board. Briefly, it helps print it every 2 times.
	srand(time(NULL));
	char tahta[15][30]; // the game area is here.
	gameArea(tahta);
	printMap(tahta);

	do
	{
		baslangic = startGame();
	}while(baslangic == 0); // the loop which decides who is going to start first will countinue until it is draw.
	printf("PLAYER%d will start the game\n",baslangic);
	do
	{
		check = moving(tahta,baslangic);
		times++;
			if(times % 2 == 0 || check == 999)
			{
				printMap(tahta);
			}
		if(check == 999) // this mean is the game is finished.
			break;
		if(baslangic == 1)				//After make a moving for one player,the order of moves of the players changes.
			baslangic = 2;				//After make a moving for one player,the order of moves of the players changes.
		else if(baslangic ==2)				//After make a moving for one player,the order of moves of the players changes.
			baslangic=1;
	} while (c != '\n' || check ==999); // 999 return code was used for finishing.
	
	
}

void gameArea(char tahta[][30])
{// filling the game area. there is nothing else to explain it.
	int i ,j;

	for(i = 0; i<15;i++)
	{
		for (j = 0; j < 30; j++)
		{
			if((i ==0 || i == 14) || ((j>=2 && j<=27) && (i==2 || i ==12)) )
				tahta[i][j] = '.';
			else if((i==4 || i == 10) && (j>=4 && j<=25))
				tahta[i][j] = '.';
			else if ((i>0 && i<14) && ((j == 0 || j==29) || (j==2 ||j == 27)))
			{
				tahta[i][j] = ':';
				if((i==1 || i ==13) && (j!=0 && j !=29))
					tahta[i][j] = ' ';
			}
			else if((i>=5 && i<=9) && (j == 4 || j==25))
				tahta[i][j] = ':';
			else if(i == 1 && j == 1)
				tahta[i][j] = '1';
			else if(i==3 && j ==3)
				tahta[i][j] = '2';
			else if( (i==2 && j ==1) || (i==4 && j ==3))
				tahta[i][j] = '_';
			else if((i == 1 && j ==14) ||(i == 7 && j==28) || (i==13 && j==14)||(i==3 && j==10 ) || (i ==3 && j==19))
				tahta[i][j] = 'X';
			else if((i==5 && j ==26) ||(i==10 && j==26) || (i==11 && j==10)|| (i==11 && j==18))
				tahta[i][j] = 'X';
			else
				tahta[i][j] = ' ';
		}
		
	}
}

int dice(void)
{
	
	int a;
	a = rand() %6+1;
	return a;
}

int startGame(void)
{
	int a;
	int b;
	char c;
	printf("To start to game, players should dice and decide who is going to start first according to it...\n");
	printf("\033[1;31mPlayer1... press enter to dice\033[0m\n");
	do
	{
		c=getchar();
	} while (c != '\n');
	
	a = dice(); // this is for player1
	printf("\033[1;31mDICE : %d\033[0m\n",a);
	printf("\033[0;34mPlayer2... press enter to dice\033[0m\n");
	do
	{
		c=getchar();
	} while (c != '\n');
	
	b = dice(); // player 2
	printf("\033[0;34mDICE: %d\033[0m\n",b);
	if(a==b )
		printf("One more time\n");
	if(a >b)
		return 1;
	else if( a==b)
		return 0; // return 0 means one more time until one them is greater than.
	else
		return 2;

}

int moving(char tahta[][30], int ilk)
{
	/*the whole things actually happening here. To understand this part you need to know that there is 4 main if
	one them for moving to right,down,left,up. then you can understand it easily.
	one more thing. In this code it checks there is 'x' or not if there is it checks again wheter or not ends up their movement on it. 
	if it is, it moves 2 step backward. if it is not it goes2 step forward in a single move. In order to not have a issue with it, it is decreasing twice in a single.
	ALL the other cases it moves one move in a single time.
	*/
	char c;
	char temp;
	int ileri;
	int flag_1 = 0;
	int i;
	int j;
	int konum1;
	int konum2;
	int a,b,cx,d;
	char aranan;
	int bitis = 0;
	if(ilk == 1)
		aranan = '1';
	else if(ilk == 2)
		aranan = '2';
	if(ilk == 1)
		printf("\n\033[1;31mPlayer%d press enter to dice\033[0m",ilk);
	else
		printf("\n\033[0;34mPlayer%d press enter to dice\033[0m",ilk);
	do
	{
		c=getchar();
	} while (c != '\n');
	ileri = dice();
	if(ilk == 1)
		printf("\033[1;31mDICE: %d\033[0m\n",ileri);
	else
		printf("\033[0;34mDICE: %d\033[0m\n",ileri);
	for(i = 0 ; i<15;i++)
	{
		for(j = 0; j<30;j++)			// This nested loop was used for find out position of the player who has the order of moves.
		{			// This nested loop was used for find out position of the player who has the order of moves.
			if(tahta[i][j] == aranan)			// This nested loop was used for find out position of the player who has the order of moves.
			{
				a= i;
				b = j;
				break;
			}
		}
	}
	for(i=a;i<14 && ileri >0 && bitis != 1;i++)
	{
		for(j=b;j<29 && ileri >0;j++)
		{
			if((i==3 || i==1) && (tahta[i][j+1] == ' ' || tahta[i][j+1] =='X')) // This is for moving to right
			{
				
				if(tahta[i][j+1] == 'X')
				{
					temp= tahta[i][j+1];
					if(ileri>1)
					{
						tahta[i][j] = ' ';
						tahta[i][j+1] = 'X';  // i.e you can examine this case it playes 2 step forward and also it decrease twice.
						tahta[i][j+2] = aranan;
						flag_1=1;
						ileri -=2; // twice time.
						j+=1;
					}
					else
					{
						tahta[i][j] = ' ';
						tahta[i][j-1] = aranan;
						j = j-1; // if the next move ends up on the 'x' it can go backword for one time. Then semantically it moved 2 step backward.
						if(ilk ==2)
							printf("\033[0;34mPENALTY FOR PLAYER%d\033[0m\n",ilk);
						else
							printf("\033[1;31mPENALTY FOR PLAYER%d\033[0m\n",ilk);
						ileri--;
					}

				}
				else
				{
					tahta[i][j] = ' ';
					tahta[i][j+1] = aranan;
					ileri--;
				}
			}
			else if( (j==28 || j == 26)&&tahta[i][j] == aranan &&(tahta[i+1][j] == ' ' || tahta[i+1][j] == 'X')) 	// This part going to down
																													// (j == 28 || j == 26) part for avoiding overlapping with going upside.
			{
				if(tahta[i+1][j] == 'X')
				{
					temp= tahta[i][j+1];
					if(ileri>1)
					{
						tahta[i][j] = ' ';
						tahta[i+1][j] = 'X';
						tahta[i+2][j] = aranan;
						flag_1=1;
						ileri -=2;
						i+=2;
						j-=1;
					}
					else
					{
						tahta[i][j] = ' ';
						tahta[i-1][j] = aranan;
						i = i-1;
						j-=1;
						if(ilk ==2)
							printf("\033[0;34mPENALTY FOR PLAYER%d\033[0m\n",ilk);
						else
							printf("\033[1;31mPENALTY FOR PLAYER%d\033[0m\n",ilk);
						ileri--;
					}

				}
				else
				{
					tahta[i][j] = ' ';
					tahta[i+1][j] = aranan;
					j-=1;
					i++;
					ileri--;
				}
			}
			else if(tahta[i][j] == aranan && (tahta[i][j-1] == ' '|| tahta[i][j-1] =='X')) // this part for going to left side.
			{
				if(tahta[i][j-1] == 'X')
				{
					temp= tahta[i][j-1];
					if(ileri>1)
					{
						tahta[i][j] = ' ';
						tahta[i][j-1] = 'X';
						tahta[i][j-2] = aranan;
						flag_1=1;
						ileri -=2;
						j-=3;
					}
					else
					{
						tahta[i][j] = ' ';
						tahta[i][j+1] = aranan;
						j+=1;
						if(ilk ==2)
							printf("\033[0;34mPENALTY FOR PLAYER%d\033[0m\n",ilk);
						else
							printf("\033[1;31mPENALTY FOR PLAYER%d\033[0m\n",ilk);
						ileri--;
					}

				}
				else
				{
 
						tahta[i][j] = ' ';
						tahta[i][j-1] = aranan;
						j=j-2;
						ileri--;
				}
			}
			else if(tahta[i-1][j] == ' '|| tahta[i-1][j] =='X' || tahta[i-1][j]== '_') // this part for going to upside.
			{
				if(tahta[i-1][j] == 'X')
				{
					temp= tahta[i-1][j];
					if(ileri>1)
					{
						tahta[i][j] = ' ';
						tahta[i-1][j] = 'X';
						tahta[i-2][j] = aranan;
						flag_1=1;
						ileri -=2;
						i-=2;
						j-=1;
					}
					else
					{
						tahta[i][j] = ' ';
						tahta[i+1][j] = aranan;
						i = i+1;
						j-=1;
						if(ilk ==2)
							printf("\033[0;34mPENALTY FOR PLAYER%d\033[0m\n",ilk);
						else
							printf("\033[1;31mPENALTY FOR PLAYER%d\033[0m\n",ilk);
						ileri--;
					}

				}
				else if(tahta[i-1][j] == '_' && ileri != 0)
				{
					bitis= 1;
					printf("PLAYER%d won!!\n",ilk);
					tahta[i][j] = ' ';
					tahta[i-1][j] = aranan;
					if(ilk =1)
					{
						konum1 = 2;
						konum2 = 1;
					}
					else
					{
						konum1 = 4;
						konum2 =3;
					}
					j=j-1;
					i-=1;
					ileri--;

				}

				else
				{
					tahta[i][j] = ' ';
					tahta[i-1][j] = aranan;
					j=j-1;
					i-=1;
					ileri--;
				}
			}

			for(cx = 0 ; cx<15;cx++)
			{
				for(d = 0; d<30;d++)
				{
					if(tahta[cx][d] == aranan)
					{
						a= i;
						b = j;
						break;
					}
				}
			}
				

		}
	}
	if(bitis ==1 )
	{
		if(tahta[2][1] == ' ')
			tahta[2][1] = '_';
		
		else if( tahta[4][3] == ' ')
			tahta[4][3] = '_';
		return 999;
	}

	return 0;
}

void printMap(char tahta[][30]) // colors..
{
	int i;
	int j;
	for(i = 0; i<15;i++)
	{
		for(j=0; j<30;j++)
		{
			if(tahta[i][j] == 'X')  printf("\033[1;31m%c\033[0m",tahta[i][j]);
            else if(tahta[i][j] == '1')  printf("\033[1;33m%c\033[0m",tahta[i][j]);
			else if(tahta[i][j] == '2')  printf("\033[1;35m%c\033[0m",tahta[i][j]);
			else if(tahta[i][j] == '_')  printf("\033[1;32m%c\033[0m",tahta[i][j]);
			else if(tahta[i][j] == ':')  printf("\033[1;36m%c\033[0m",tahta[i][j]);
			else if(tahta[i][j] == '.')  printf("\033[1;34m%c\033[0m",tahta[i][j]);
			else    printf("%c",tahta[i][j]);
		}
		printf("\n");
	}
}