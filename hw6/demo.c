#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void filling_board(char tahta[][30]);
int dice(void);
int startGame(void);
void moving(char tahta[][30], int ilk);
void print_board(char tahta[][30]);
int main()
{
    int baslangic;
    char c;
    srand(time(NULL));
    char tahta[15][30];
    filling_board(tahta);
    dice();
    do
    {
        baslangic = startGame();
       // printf("%dxx",baslangic);
    }while(baslangic == 0);
    printf("PLAYER%d will start the game\n",baslangic);
    do
    {
        moving(tahta,baslangic);
        print_board(tahta);
        //printf("baslangic = %d",baslangic);
        if(baslangic == 1)
            baslangic = 2;
        else if(baslangic ==2)
            baslangic=1;
    } while (c != '\n');
    
    
}

void filling_board(char tahta[][30])
{
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
            else if((i == 1 && j ==14) ||(i == 7 && j==28) || (i==13 && j==14)||(i==3 && j==10 ) || (i ==3 && j==19)||(i==5 && j ==26) ||(i==10 && j==26) || (i==11 && j==10)|| (i==11 && j==18))
                tahta[i][j] = 'X';
            else
                tahta[i][j] = ' ';
            printf("%c",tahta[i][j]);
        }
        printf("\n");
        
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
    printf("Player1... press enter to dice\n");
    do
    {
        c=getchar();
    } while (c != '\n');
    
    a = rand() %6+1;
    printf("DICE : %d\n",a);
    printf("Player2... press enter to dice\n");
    do
    {
        c=getchar();
    } while (c != '\n');
    
    b = rand() %6+1;
    printf("DICE: %d\n",b);
    if(a==b )
        printf("One more time\n");
    if(a >b)
        return 1;
    else if( a==b)
        return 0;
    else
        return 2;

}
void moving(char tahta[][30], int ilk)
{
    char hamle[]= {'r','b','l','u'};
    char c;
    char temp;
    int ileri;
    int flag_1 = 0;
    int i;
    int j;
    int a,b,cx,d;
    char aranan;
    if(ilk == 1)
        aranan = '1';
    else if(ilk == 2)
        aranan = '2';
    else
        printf("zaxd");
    //printf("aranan: %c\n",aranan);
    printf("Player%d press enter to dice\n",ilk);
    do
    {
        c=getchar();
    } while (c != '\n');
    ileri = dice();
    printf("DICE: %d\n",ileri);
    for(i = 0 ; i<15;i++)
    {
        for(j = 0; j<30;j++)
        {
            if(tahta[i][j] == aranan)
            {
                a= i;
                b = j;
                printf("i==%d &&&& j == %d",i,j);
                break;
            }
        }
    }
    printf("zaaa0\n");
    for(i=a;i<14 && ileri >0;i++)
    {
        for(j=b;j<29 && ileri >0;j++)
        {
            if(tahta[i][j+1] == ' ' || tahta[i][j+1] =='X')
            {
                
                if(tahta[i][j+1] == 'X')
                {
                    temp= tahta[i][j+1];
                    if(ileri>1)
                    {
                        tahta[i][j] = ' ';
                        tahta[i][j+1] = 'X';
                        tahta[i][j+2] = aranan;
                        printf("bura\n");
                        flag_1=1;
                        ileri -=2;
                        j+=1;
                    }
                    else
                    {
                        tahta[i][j] = ' ';
                        tahta[i][j-1] = aranan;
                        j = j-1;
                        printf("zaaa1\n");
                        ileri--;
                    }

                }
                else
                {
                    tahta[i][j] = ' ';
                    tahta[i][j+1] = aranan;
                    printf("zaaa1\n");
                    ileri--;
                }
            }
            else if(tahta[i][j] == aranan &&(tahta[i+1][j] == ' ' || tahta[i+1][j] == 'X'))
            {
                if(tahta[i+1][j] == 'X')
                {
                    temp= tahta[i][j+1];
                    if(ileri>1)
                    {
                        tahta[i][j] = ' ';
                        tahta[i+1][j] = 'X';
                        tahta[i+2][j] = aranan;
                        printf("bura\n");
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
                        printf("zaaa1\n");
                        ileri--;
                    }

                }
                else
                {
                    tahta[i][j] = ' ';
                    tahta[i+1][j] = aranan;
                    printf("zaaa2\n");
                    j-=1;
                    i++;
                    ileri--;
                }
            }
            else if(tahta[i][j] == aranan && (tahta[i][j-1] == ' '|| tahta[i][j-1] =='X'))
            {
                if(tahta[i][j-1] == 'X')
                {
                    temp= tahta[i][j-1];
                    if(ileri>1)
                    {
                        tahta[i][j] = ' ';
                        tahta[i][j-1] = 'X';
                        tahta[i][j-1] = aranan;
                        printf("bura\n");
                        flag_1=1;
                        ileri -=2;
                        j-=3;
                    }
                    else
                    {
                        tahta[i][j] = ' ';
                        tahta[i][j+1] = aranan;
                        j+=1;
                        printf("zaaa1\n");
                        ileri--;
                    }

                }
                else
                {
                    tahta[i][j] = ' ';
                    tahta[i][j-1] = aranan;
                    j=j-2;
                    printf("zaaa3\n");
                    ileri--;
                }
            }
            else if(tahta[i-1][j] == ' '|| tahta[i-1][j] =='X')
            {
                tahta[i][j] = ' ';
                tahta[i-1][j] = aranan;
                printf("zaaa4\n");
                ileri--;
            }
            else
                printf("HAMLE BULAMADIM\n");

            for(cx = 0 ; cx<15;cx++)
            {
                for(d = 0; d<30;d++)
                {
                    if(tahta[cx][d] == aranan)
                    {
                        a= i;
                        b = j;
                        printf("\n\n\ni==%d &&&& j == %d\n\n",cx,d);
                        break;
                    }
                }
            }
                

        }
        printf("zaaa6\n");
    }

}

void print_board(char tahta[][30])
{
    int i;
    int j;
    for(i = 0; i<15;i++)
    {
        for(j=0; j<30;j++)
        {
            printf("%c",tahta[i][j]);
        }
        printf("\n");
    }
}
