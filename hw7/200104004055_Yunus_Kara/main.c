#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
void built_board(char   board[][15]); // every function is calling in here
void producing_vocab(char words[][20],int *nums); // it gets 7 different words
void print_board(char   board[][15]); // just print the board
void filling_randomly(char board[][15]); // it puts random char
void direction_and_vocab(char board[][15], char *words); // putting random words in a random way.
void filling_with_dash(char board[][15]); // this is first part put '-' first of all
void game_part(char board[][15], char words[][20]); // game part
int comp(char words[][20], char *gelen); // it control words and input comperasion function.
int comp_n(char words[][20], char *gelen,int n);
int main()
{
    char board[15][15];
    srand(time(NULL));
    built_board(board);
}

void built_board(char   board[][15])
{
    int random;
    FILE *ptr;
    int i;
    char words[7][20];
    int nums[7] = {0};
    ptr = fopen("wordlist.txt","r");
    producing_vocab(words,nums);
    filling_with_dash(board);
    for(i = 0; i<7; i++)
    {
        direction_and_vocab(board,words[i]);
    }
    filling_randomly(board);
    print_board(board);
    game_part(board,words);
}

void producing_vocab(char words[][20], int *nums)
{
    int i;
    int random;
    int j;
    int k;
    int flag_1; // daha önce aynı sayıya ulaşıldı mı ulaşılmadı mı flagi ?
    FILE * PtForWord;
    PtForWord = fopen("wordlist.txt","r");
    for(i = 0;i<7;i++)
    {
        flag_1 = 0;
        random = rand() % 50 +1;
        nums[i] = random;
        for(k = 0; k<i;k++)
        {
            if(nums[k] == random)
            {
                flag_1 = 1;
                i--;
            }
        }
        //printf(" rand : %d--",random);
        for(j =0 ; j<random && flag_1 == 0; j++)
        {
            fscanf(PtForWord,"%s ",words[i]);
        }
        fseek(PtForWord,0,SEEK_SET);
      //  printf("%d -- %s\n",i,words[i]);
    }
    fclose(PtForWord);
}

void print_board(char   board[][15])
{
    printf("\n\n\n\n\n");
    int i;
    int j;
    for(i = 0; i<15;i++)
    {
        for(j = 0; j<15; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void filling_randomly(char board[][15])
{
    int i;
    int j;
    char c;
    for(i = 0; i<15;i++)
    {
        for(j = 0 ; j<15; j++)
        {
            c= (char)(rand() %26);
            if(board[i][j] == '-')
            board[i][j] = c +'a';
        }
    }
}

void filling_with_dash(char board[][15])
{
    int i;
    int j;
    for(i = 0; i<15;i++)
    {
        for(j = 0 ; j<15; j++)
        {
            board[i][j] = '-';
        }
    }
}
void direction_and_vocab(char board[][15], char *words)
{
    int num;
    int row;
    int col;
    int i;
    int j;
    int flag_1; // bitiş için
    int flag_2; // yerleştirmek için asıl amacı bu kelimenin konulacağı düzlemde herhangi bir harfle çakışıyor mu çakışmıyor mu?
    do
    {
        flag_1 = 0;
        flag_2 = 0;
        num = rand() %8; // THIS IS FOR WHICH DIRECTION? FOR EXAMPLE 0 MEANS FROM LEFT TO RIGHT HORIZONTALLY.
        row = rand() % 15;//  RANDOM ROW
        col = rand() % 15;// RANDOM COLUMN
        if(num == 0) // yatay sağa doğru yerleştirmek için.
        {
            if(strlen(words)+ col <16) // IT CHECKS WHETHER OR NOT OVERFLOWING
            {
                for(j = col; j<col + strlen(words);j++) // I USED THE SAME ALGORTIHM FOR ALL DIRECTIONS SO I AM GONNA EXPLAIN IT ONE TIME, REST OF THEM IS SAME.
                {                                       // BEFORE PUTTING THE LETTERS IT CHECKS IF THERE IS A WORD OR NOT. IF THERE IS, FLAG IS TRGIGGED AND 
                                                        // LOOP PRODUCES NEW RANDOM DIRECTION RANDOM COLUMN AND ROW. IF THERE IS NOT IT PUTS ON IT.
                    if(board[row][j] != '-')
                    {
                        flag_2 = 1;
                    }
                   
                }
               if(flag_2 == 0)
               {
                   printf("%s- row: %d,, col: %d \n",words,row,col);
                   for(i = 0;i<strlen(words);i++,col++)
                   {
                       board[row][col] = words[i];
                   }
                   flag_1=1;
               }

            }
            
        } 
        else if(num == 1) //yatay sola doğru yerleştirmek için.
        {
            if((col - (int)strlen(words)+1) >=0)
            {
                for(j = col; col -j  <strlen(words) ; j--)
                {
                    if(board[row][j] != '-')
                    {
                        flag_2 = 1;
                    }
                }
                if(flag_2==0)
                {
                    printf("%s- row: %d,, col: %d\n",words,row,col);
                    for(i = 0; i<strlen(words); i++,col--)
                    {
                        board[row][col] = words[i];
                    }
                    flag_1=1;
                }
            }

        }
        else if(num == 2) // yukarıdan aşağıya doğru.
        {
            if((int)strlen(words) + row <16)
            {
                for(i = row; i<row + strlen(words);i++)
                {
                    if(board[i][col] != '-')
                    {
                        flag_2 = 1;
                    }
                   
                }
               if(flag_2 == 0)
               {
                   printf("%s- row: %d,, col: %d\n",words,row,col);
                   for(i = 0;i<strlen(words);i++,row++)
                   {
                       board[row][col] = words[i];
                   }
                   flag_1=1;
               }
            }
        }
        else if(num == 3) // aşağıdan yukarıya.
        {
            if(row -(int)strlen(words) >=-1)
            {
                for(i = row; row -i< strlen(words);i--)
                {
                    if(board[i][col] != '-')
                    {
                        flag_2 = 1;
                    }
                   
                }
               if(flag_2 == 0)
               {
                   printf("%s- row: %d,, col: %d\n",words,row,col);
                   for(i = 0;i<strlen(words);i++,row--)
                   {
                       board[row][col] = words[i];
                   }
                   flag_1=1;
               }
            } 
        }
        else if(num == 4) //sağ üst çarpraza doğru.
        {
           
            if(strlen(words)+ col <16 && (row -(int)strlen(words) >=-1))
            {
                for(j = col, i = row; j<col + strlen(words) && row -i< strlen(words) ;j++, i--)
                {
                    if(board[i][j] != '-')
                    {
                        flag_2 = 1;
                    }
                }
                    if(flag_2 == 0)
                    {
                        printf("%s- row: %d,, col: %d\n",words,row,col);
                        for(i = 0;i<strlen(words);i++,row--,col++)
                        {
                            board[row][col] = words[i];
                        }
                        flag_1=1;
                    }
                
            }
        }  
        else if(num == 5)//sol alt çarpraz.
        {
            if((col - (int)strlen(words)+1) >=0 && (int)strlen(words) + row <16)
            {
                for(j = col, i = row; col -j  <strlen(words) && i<row + strlen(words) ; j--, i++)
                {
                    if(board[i][j] != '-')
                    {
                        flag_2 = 1;
                    }
                }
                if(flag_2==0)
                {
                    printf("%s- row: %d,, col: %d\n",words,row,col);
                    for(i = 0; i<strlen(words); i++,col--,row++)
                    {
                        board[row][col] = words[i];
                    }
                    flag_1=1;
                }
            }
        }
        else if(num == 6) // sol üst çarpraz.
        {
            if((col - (int)strlen(words)) >=-1 && row -(int)strlen(words) >=-1)
            {
                for(i = row, j = col; row -i< strlen(words) && col -j  <strlen(words);i--,j--)
                {
                    if(board[i][j] != '-')
                    {
                        flag_2 = 1;
                    }
                   
                }
               if(flag_2 == 0)
               {
                   printf("%s- row: %d,, col: %d\n",words,row,col);
                   for(i = 0;i<strlen(words);i++,row--,col--)
                   {
                       board[row][col] = words[i];
                   }
                   flag_1=1;
               }
            }
        }
        else if (num == 7) // sağ alt çarpraz.
        {
            if(strlen(words)+ col <16 && (int)strlen(words) + row <16)
            {
                for(j = col, i = row; j<col + strlen(words) && i<row + strlen(words);j++,i++)
                {
                    if(board[i][j] != '-')
                    {
                        flag_2 = 1;
                    }
                   
                }
               if(flag_2 == 0)
               {
                   printf("%s- row: %d,, col: %d\n",words,row,col);
                   for(i = 0;i<strlen(words);i++,col++,row++)
                   {
                       board[row][col] = words[i];
                   }
                   flag_1=1;
               }

            }
        }
    }while((flag_1 == 0 && flag_2 == 1) || (flag_2 == 0 && flag_1 == 0) ); // FLAGLAR TRIGGERLANDIGI SURECE DEVAM ETSIN
}

void game_part(char board[][15], char words[][20])
{
    char input[40]; // this is for not successfull scanf to get ":q"
    char gelen[40]; // this is for successfull scanf to get strıng "word"
    char dogruluk[10]; // i do know why i put it here...
    int point = 0; //this is users point
    int num1; // input row
    int num2 = 7; // input column. it was init. while testing the code. the value is not important.
    int times = 3; 
    int check; // it chekcs scanf gets value or not.
    int copy_num1;
    int copy_num2;
    int diff_copy_1;
    int diff_copy_2;
    char c;
    int i;
    int k = 0;
    int flag =0;
    int flag_4 = -1;
    do
    {
        flag_4 = -1;
        k = 0;
        printf("Enter coordinates and word\n\n");
        check = scanf("%d %d %s",&num1,&num2,gelen);
        i =0;
        if(check == 0) // this part for  unsuccessfull scanf 
        {
            do
            {
                c = getchar(); // if scanf 0 means there is string. and this algorithm checks what is in buffer.
                input[i] = c;
                //printf("%c",input[i]);
                i++;
            } while (c != '\n');
            for(i = 0; i<40;i++)
            {
                if(input[i] == '\n')
                    input[i] = '\0';
            }
            if(strncmp(input,":q",2) == 0 && strlen(input) == 2) // if the buffer is ':q' quitting.
            {
                printf("you have %d point good bye\n",point);
                break;
            }
            else
            {
                printf("invalid input\n");
            }
            
        }
        else if(num1<0 || num1 >14 || num2 <0|| num2 >14) // bounderys.
        {
            printf("these numbers are invalid please try again\n");
        }
        else
        {
            copy_num1 = num1;
            copy_num2 = num2;
            diff_copy_1 = num1;
            diff_copy_2 = num2;
          //  printf("geldim %ld %d\n",strlen(gelen),num2);
            i = 0;
            if(board[num1][num2] == gelen[0] && strlen(gelen)+ num2 <16 && board[num1][num2+1] == gelen[1]) // from left to right horizontally
            {
                for(k =0,i = 0;i<strlen(gelen); i++,num2++,k++)
                {                                                      // The main algorith is just below.             
                    if(board[num1][num2]== gelen[i])
                    {
                        dogruluk[k] = gelen[i];
                       // printf("1|||dogruluk = %c\n|||",dogruluk[k]);
                    }
                    
                }
                if(i ==strlen(gelen))
                {
                    if(comp(words,gelen) == 0&& comp_n(words,dogruluk,k) == 0 )
                    {
                        for(; k> 0; copy_num2++,k--)
                        {
                            board[copy_num1][copy_num2]='-';
                        }
                        point += 2;
                        flag_4=10;
                        printf("Congrulations you earned 2 point and your total point is %d",point);
                    }
                }
                print_board(board);
                k = 0;
            }
            num1 = diff_copy_1;
            num2 = diff_copy_2;
            copy_num1 = num1;
            copy_num2 = num2;
            if(board[num1][num2] == gelen[0] && num2-strlen(gelen) >= 0 && board[num1][num2-1] == gelen[1]) // from right to left horizontally
            {
                for(i=0,k =0;i<strlen(gelen); i++,num2--,k++)  // the same algorithm was used for all of them so 1 time explain is enough...........
                {                                      // First of all conditions cheks. It checks first letters. and boundrys..............
                    if(board[num1][num2]== gelen[i])   // Last condition is for second letter. If it is from left to right horizontally......
                    {                                  // it should checks  board[num1][num2+1]  just plus 1................................               // In loop it checks how many of them are same......................................
                        dogruluk[k] = gelen[i];        // and some other manipulations......................................................
                        //printf("2|||dogruluk = %c\n|||",dogruluk[k]);
                    }
                    
                }
                if(i ==strlen(gelen))
                {
                    if(comp(words,gelen) == 0&& comp_n(words,dogruluk,k) == 0 )
                    {
                        for(; k> 0; copy_num2--,k--)
                        {
                            board[copy_num1][copy_num2]='-';
                        }
                        point += 2;
                        flag_4=10;
                        printf("Congrulations you earned 2 point and your total point is %d",point);
                    }
                }
                print_board(board);
                k = 0;
            }
            num1 = diff_copy_1;
            num2 = diff_copy_2;
            copy_num1 = num1;
            copy_num2 = num2;
            if(board[num1][num2] == gelen[0] && num1+strlen(gelen) <= 15 && board[num1+1][num2] == gelen[1]) // from up to down vertically
            {
                for(k = 0,i= 0;i<strlen(gelen); i++,num1++,k++)
                {
                    if(board[num1][num2]== gelen[i])
                    {
                        dogruluk[k] = gelen[i];
                        //printf("3|||dogruluk = %c\n|||",dogruluk[k]);
                    }
                    
                }
                if(i ==strlen(gelen))
                {
                    if(comp(words,gelen) == 0 && comp_n(words,dogruluk,k) == 0 )
                    {
                        for(; k> 0; copy_num1++,k--)
                        {
                            board[copy_num1][copy_num2]='-';
                        }
                        point += 2;
                        flag_4=10;
                        printf("Congrulations you earned 2 point and your total point is %d",point);
                    }
                }
                print_board(board);
                k = 0;
            }
            num1 = diff_copy_1;
            num2 = diff_copy_2;
            copy_num1 = num1;
            copy_num2 = num2;
            if(board[num1][num2] == gelen[0] && num1-strlen(gelen) >= 0 && board[num1-1][num2] == gelen[1]) // from down to up vertically
            {
                for(k = 0, i = 0;i<strlen(gelen); i++,num1--,k++)
                {
                    if(board[num1][num2]== gelen[i])
                    {
                        dogruluk[k] = gelen[i];
                        //printf("4|||dogruluk = %c\n|||",dogruluk[k]);
                    }
                    
                }
                if(i ==strlen(gelen))
                {
                    if(comp(words,gelen) == 0&& comp_n(words,dogruluk,k) == 0 )
                    {
                        for(; k> 0; copy_num1--,k--)
                        {
                            board[copy_num1][copy_num2]='-';
                        }
                        point += 2;
                        flag_4=10;
                        printf("Congrulations you earned 2 point and your total point is %d",point);
                    }
                }
                print_board(board);
                k = 0;
            }
            num1 = diff_copy_1;
            num2 = diff_copy_2;
            copy_num1 = num1;
            copy_num2 = num2;
            if(board[num1][num2] == gelen[0] && num1-strlen(gelen) >= 0 &&num2 + strlen(gelen) <= 15 && board[num1-1][num2+1] == gelen[1]) // upper right cross
            {
                for(k = 0, i = 0;i<strlen(gelen); i++,num1--,num2++,k++)
                {
                    if(board[num1][num2]== gelen[i])
                    {
                        dogruluk[k] = gelen[i];
                        //printf("5|||dogruluk = %c\n|||",dogruluk[k]);
                    }
                    
                }
                if(i ==strlen(gelen))
                {
                    if(comp(words,gelen) == 0&& comp_n(words,dogruluk,k) == 0 )
                    {
                        for(; k> 0; copy_num1--,copy_num2++,k--)
                        {
                            board[copy_num1][copy_num2]='-';
                            //printf("dogruluk = %c\n",dogruluk[k]);
                        }
                        point += 2;
                        flag_4=10;
                        printf("Congrulations you earned 2 point and your total point is %d",point);
                    }
                }
                print_board(board);
                k = 0;
            }
            num1 = diff_copy_1;
            num2 = diff_copy_2;
            copy_num1 = num1;
            copy_num2 = num2;
            if(board[num1][num2] == gelen[0] && num1+strlen(gelen) <= 15 &&num2 - strlen(gelen) >= 0 && board[num1+1][num2-1] == gelen[1]) // lower left cross
            {
                for(k = 0, i = 0;i<strlen(gelen); i++,num1++,num2--,k++)
                {
                    if(board[num1][num2]== gelen[i])
                    {
                        dogruluk[k] = gelen[i];
                        //printf("6|||dogruluk = %c\n|||",dogruluk[k]);
                    }
                    
                }
                if(i ==strlen(gelen))
                {
                    if(comp(words,gelen) == 0&& comp_n(words,dogruluk,k) == 0 )
                    {
                        for(; k> 0; copy_num1++,copy_num2--,k--)
                        {
                            board[copy_num1][copy_num2]='-';
                           // printf("dogruluk = %c\n",dogruluk[k]);
                        }
                        point += 2;
                        flag_4=10;
                        printf("Congrulations you earned 2 point and your total point is %d",point);
                    }
                }
                print_board(board);
                k = 0;
            }
            num1 = diff_copy_1;
            num2 = diff_copy_2;
            copy_num1 = num1;
            copy_num2 = num2;
            if(board[num1][num2] == gelen[0] && num1+strlen(gelen) <= 15 &&num2 + strlen(gelen) <= 15 && board[num1+1][num2+1] == gelen[1]) // lower right cross
            {
                for(k = 0, i = 0;i<strlen(gelen); i++,num1++,num2++,k++)
                {
                    if(board[num1][num2]== gelen[i])
                    {
                        dogruluk[k] = gelen[i];
                        //printf("7|||dogruluk = %c\n|||",dogruluk[k]);
                    }
                    
                }
                if(i ==strlen(gelen))
                {
                    if(comp(words,gelen) == 0&& comp_n(words,dogruluk,k) == 0 )
                    {
                        for(; k> 0; copy_num1++,copy_num2++,k--)
                        {
                            board[copy_num1][copy_num2]='-';
                            //printf("dogruluk = %c\n",dogruluk[k]);
                        }
                        point += 2;
                        flag_4=10;
                        printf("Congrulations you earned 2 point and your total point is %d",point);
                    }
                }
                k = 0;
                print_board(board);
            }
            num1 = diff_copy_1;
            num2 = diff_copy_2;
            copy_num1 = num1;
            copy_num2 = num2;
            if(board[num1][num2] == gelen[0] && num1-strlen(gelen) >= 0 &&num2 - strlen(gelen) >= 0 && board[num1-1][num2-1] == gelen[1]) // upper left cross
            {
                for(k = 0, i = 0;i<strlen(gelen); i++,num1--,num2--,k++)
                {
                    if(board[num1][num2]== gelen[i])
                    {
                        dogruluk[k] = gelen[i];
                        //printf("8|||dogruluk = %c\n|||",dogruluk[k]);
                    }
                    
                }
                if(i ==strlen(gelen))
                {
                    if(comp(words,gelen) == 0 && comp_n(words,dogruluk,k) == 0 )
                    {
                        for(; k> 0; copy_num1--,copy_num2--,k--)
                        {
                            board[copy_num1][copy_num2]='-';
                            //printf("dogruluk = %c\n",dogruluk[k]);
                        }
                        point += 2;
                        printf("Congrulations you earned 2 point and your total point is %d",point);
                        flag_4=10;
                    }
                }
                k = 0;
                print_board(board);
            }
            if(flag_4 == -1)
            {
                times--;
                if(times >=1)
                    printf("Wrong choice! You have only %d lefts.",times);
            }
            //else
            //    printf("Doru\n");
        }
    //    printf("gelen %s -%d-%d",gelen,num1,num2);
    } while (times >0 && point != 14);
    if (times == 0)
        printf("You have %d point good bye",point); 
}

int comp(char words[][20], char *gelen) // kullanıcının verdiği kelime ile elimdeki kelimelerini kıyasladığım yer.
{
    int i;
    int r=-1;
    for(i = 0; i<7; i++)
    {
        if(strcmp(words[i],gelen) == 0)
            r = 0;
    }
        return r;
}

int comp_n(char words[][20], char *gelen,int n) // kullanıcının verdiği kelime ile elimdeki kelimelerini kıyasladığım yer.
{
    int i;
    int r=-1;
    for(i = 0; i<7; i++)
    {
        if(strncmp(words[i],gelen,n) == 0)
            r = 0;
    }
        return r;
}