#include<stdio.h>

void drawing_graph(int a, int b, int c);
void coefficients(void);

int main()
{
   int a,b,c;
   int selection;
   do
   {
      printf("0 -> Enter the coefficients.\n 1 -> Draw the graph.\n2 -> Print the graph into a .txt file\n 3 -> Exit.\n");
      scanf("%d",&selection);
      if(selection == 0)
      {
         coefficients();
      }
      else if(selection == 1)
      {
         FILE * ptr;
         ptr = fopen("a.txt","r");
         fscanf(ptr,"%d ",&a);
         printf("%d\n",a);
         fscanf(ptr,"%d ",&b);
         printf("%d\n",b);
         fscanf(ptr,"%d ",&c);
         printf("%d\n",c);
         drawing_graph(a,b,c);
      }
      else if(selection == 3)
      {
         break;
      }
   }
   while(selection>= 0 && selection <=3);
   //drawing_graph();
}

void drawing_graph(int a, int b,int c)
{
   int yatay =-56;
   int dikey = 16;
   int result;
   int hastag = 16;
   int i;
   int j;
   while(dikey>-16)
   {
   		result = ((a)*dikey*dikey) +(b*dikey)+c;
   		while(yatay <=56)
   		{
   			if(result == yatay && dikey != 16)
   				printf("#");	
   				
   			else if(dikey==0)
   			{
   				if(yatay == -56)
   					printf("<");
   				else if(yatay ==56)
   					printf(">");
   				else
   				{
   					if(yatay != 0)
   						printf("-");
   					else
   						printf("|");
   					
   				}
   			}
   			
   			else if(yatay == 0)
   			{
   				if(dikey == 16)
   					printf("^");
   				else
   					printf("|");
   				
  				
   				
   			}

   			else if(dikey == -1)
   			{
   				if(yatay == -50)
   					printf("\b\b-50");
   				else if (yatay == -40)
   					printf("\b\b-40");
   				else if (yatay == -30)
   					printf("\b\b-30");
   				else if (yatay == -20)
   					printf("\b\b-20");
   				else if (yatay == -10)
   					printf("\b\b-10");
   				else if(yatay == -1)
   					printf("0");
   				else if(yatay == 11)
   					printf("\b10");
   				else if(yatay == 21)
   					printf("\b20");
   				else if(yatay == 31)
   					printf("\b30");
   				else if(yatay == 41)
   					printf("\b40");
				else if(yatay == 51)
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
   ptr = fopen("a.txt","w");

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