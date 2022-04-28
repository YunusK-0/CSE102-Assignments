#include<stdio.h>
void red (void);
void blue(void);
void reset (void);
void drawing_graph(int a, int b, int c); // this function draw the graph on terminal
void printing_txt(int a, int b, int c); // drawing the same graph on the graph.txt
void coefficients(void); // it contains coefficients of the equation

int main()
{
   int a,b,c;
   int selection;
   do
   {
      printf("0 -> Enter the coefficients.\n1 -> Draw the graph.\n2 -> Print the graph into a .txt file\n3 -> Exit.\n");
      scanf("%d",&selection);
      if(selection == 0)
      {
      coefficients();
      }
      else if(selection == 1)
      {
      	
         FILE * ptr;

         ptr = fopen("coefficients.txt","r");	
         if(ptr==NULL)
         {
       	  	printf("there is no coeffecients please press 0\n");
      	 }
         else
         {								
         fscanf(ptr,"%d ",&a);			// In there getting data from   coefficient.txt															
         fscanf(ptr,"%d ",&b);					
         fscanf(ptr,"%d ",&c);
         drawing_graph(a,b,c);
         fclose(ptr);
         }
        }
      
      else if(selection ==2 )
      {
     
      	
      		FILE * ptr;
        	ptr = fopen("coefficients.txt","r"); // In here too getting data from coefficient in order to send them the other functions.
       	if(ptr==NULL)
       	{
       	  	printf("there is no coeffecients please press 0\n");
       	  }
       	else
       	{
        	fscanf(ptr,"%d ",&a);
        	fscanf(ptr,"%d ",&b);
        	fscanf(ptr,"%d ",&c);
        	fclose(ptr);
        	printing_txt(a,b,c);
        	}
      }
      else if(selection == 3)
      {
         break;
      }
      else
      	printf("Invalid selection. please select from 0 to 3\n");
   }
   while(selection != 3);

}

void drawing_graph(int a, int b,int c)
{
   int yatay =-56; // from -56 to +56 it is not 55 because we have < and > so thats why.
   int dikey =16; // it is not 15 because we have ^.
   int result; // it containst the result of equation while indexing if it is the same it will be printed.
   int hastag = 16;
   while(dikey>-16)
   {
   		result = ((a)*dikey*dikey) +(b*dikey)+c; //it is done for every line becuase in there can be only one value for a line.
   		while(yatay <=56)
   		{
   			if(((a*dikey*dikey)+(b*dikey)+c) == yatay && dikey != 16)
   			{
   				red();
   				printf("#");
   				reset();
			}
   			else if(yatay == 0 && dikey != 16)
   			{
   				blue();
   				printf("|"); // this is vertical
   				reset();
   			}
   			else if(dikey == 16 && yatay == 0)
   			{
   				blue();
   				printf("^");
   				reset();		
   			}
   				
   			else if(dikey==0)
   			{
   				if(yatay == -56)
   				{
   					blue();
   					printf("<");
   					reset();
   				}
   				else if(yatay ==56)
   				{
   					blue();
   					printf(">");
   					reset();
   				}
   				else
   				{
   					blue();
   					printf("-"); // horizontal
   					reset();
   				}
   			}
 /* FOR THIS SECTION I WAS WORKING ON IT BUT I HAVE TO CHECK THEM FOR EVERY CASE 
 	CHECKING THEM FOR EVERY LINE IF IT WAS CHECKED FOR EVERY COLUMN IT WOULD BE PROBLEM */ 			
   			else if(dikey % 5 == 0 && dikey >0 && dikey != 5 && yatay == -1)
   				printf("\b%d",dikey);
   			else if(dikey ==5 && yatay == -1)
   				printf("%d",dikey);
   			else if(dikey == -5 && yatay == -1)
   				printf("\b%d",dikey);
   			else if(dikey == -10 && yatay == -1)
   				printf("\b\b%d",dikey);
   			else if(dikey == -15 && yatay == -1)
   				printf("\b\b%d",dikey);

   			else if(dikey == -1)
   			{
   				if(yatay == -50)
   					printf("\b\b-50"); // THERE 2 \n BECAUSE THE INDEX IS THERE AND IT MUST DELETE 2 DIGIT. IT HAS BASIC CALCULATION. YOU NEED TO USE ADD -1 TO DIGIT NUMBER. - 5 0 THERE ARE 3 DIGIT. SO THATS WHY 2 \n.
   				else if (yatay == -40)
   					printf("\b\b-40");
   				else if (yatay == -30)
   					printf("\b\b-30");
   				else if (yatay == -20)
   					printf("\b\b-20");
   				else if (yatay == -10)
   					printf("\b\b-10");
   				else if(yatay == -1)
   					printf("0"); // ADD -1 TO 1 DIGIT SO IT IS ZERO. NO NEED.
   				else if(yatay == 10)
   					printf("\b10");
   				else if(yatay == 20)
   					printf("\b20");
   				else if(yatay == 30)
   					printf("\b30");
   				else if(yatay == 40)
   					printf("\b40");
				else if(yatay == 50)
   					printf("\b50");	
   				else
   					printf(" ");
   			}
   			
   			else
   				printf(" ");
   			
   			yatay++;
   		}
   		yatay=-56;
   		printf("\n");
   		dikey--;
   		hastag--;
   }
}
void coefficients(void)
{
   FILE * ptr;
   int kat_sayi;
   ptr = fopen("coefficients.txt","w");

   printf("Please enter the coefficient for the following equation: x = a*(y*y) + b*y +c\n");
   printf("a: ");
   scanf("%d",&kat_sayi);
   fprintf(ptr, "%d\n",kat_sayi);
   printf("b: ");
   scanf("%d",&kat_sayi);
   fprintf(ptr, "%d\n",kat_sayi);
   printf("c: ");
   scanf("%d",&kat_sayi);
   fprintf(ptr, "%d",kat_sayi);
   fclose(ptr);
}
void red () {
  printf("\033[1;31m");
}
void blue() {
  printf("\033[0;34m");
}
void reset () {
  printf("\033[0m");
}
void printing_txt(int a, int b, int c) // IT IS THE SAME AS DRAWING _GRAPH. IT IS WITHOUT NUMBERS AND COLOURS.
{ 
	FILE * point;
    point =fopen("graph.txt","w");
	int yatay =-56;
   int dikey =16;
   int result;
   int hastag = 16;
   while(dikey>-16)
   {
   		result = ((a)*dikey*dikey) +(b*dikey)+c;
   		while(yatay <=56)
   		{
   			if(((a*dikey*dikey)+(b*dikey)+c) == yatay && dikey != 16)
   				fprintf(point,"#");
   			else if(yatay == 0 && dikey != 16)
   				fprintf(point,"|");
   			else if(dikey == 16 && yatay == 0)
   				fprintf(point,"^");
   			else if(dikey==0)
   			{
   				if(yatay == -56)
   					fprintf(point,"<");
   				else if(yatay ==56)
   					fprintf(point,">");
   				else
   					fprintf(point,"-");
   			}
   			else
   				fprintf(point," ");
   			
   			yatay++;
   		}
   		yatay=-56;
   		fprintf(point,"\n");
   		dikey--;
   		hastag--;
	}
	fclose(point);
}
