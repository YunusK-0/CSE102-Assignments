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
   int yatay = 112;
   int dikey = 32;
   int deger_kumesi= 15;
   int hastag = 0;
   int result;
   int i = 0;
   int j = 0;

   while(j<dikey)
   {
      result = (a*(deger_kumesi*deger_kumesi)) + (b*deger_kumesi)+ c;
      
      while(i<yatay)
      {
         if(j != 16 && j != 17 && hastag != 16 && hastag != 17)
         {
            if(result == i-56 && hastag !=0 && hastag <16 && hastag != 0)
               printf("K");
            else if (hastag >= 18)
            {
               
               if(result == i-56)
                  printf("L");
            }
            else
            {
               printf(" ");
               if( i == 55 && j==0)
                  printf("^");
         	   else if(i == 54 && j == 1)
                  printf("\b\b15");
               else if(i == 54 && j == 6)
                  printf("\b\b10");
               else if(i == 54 && j == 11)
                  printf("\b5");
               else if(i == 54 && j == 21)
                  printf("\b\b-5");
               else if(i == 54 && j == 26)
                  printf("\b\b\b-10");
               else if(i == 54 && j == 31)
                  printf("\b\b\b-15");
               else if(i == 55)
                  printf("|");
               if(result == i-56 && hastag !=0 && hastag <16 && hastag != 0)
                  printf("\bK");
               
            }
            i++;

         }
         else if(j == 16)
         {
            while(j==16 && i<yatay && hastag ==j )
            {
               if(i ==0)
                  printf("<");
               else if(i ==112)
                  printf(">");
               else if(i == 56)
                  printf("|");
               else
               {
                  //printf("-");
                  if(result == i-57)
                  {
                     printf("M");
                  }
                  else
                  	printf("-");
               }
               i++;
            }

         }
         else if(j==17)
         {
            while(j==17 && i <yatay)
            {
               if (i==7)
                  printf("\b\b\b-50");
               if(i==17)
                  printf("\b\b\b-40");
               if(i==27)
                  printf("\b\b\b-30");
               if (i ==37)
                  printf("\b\b\b-20");
               if(i == 47)
                  printf("\b\b\b-10");
               if (i == 56)
                  printf("\b0");
               if (i == 57)
                  printf("\b|");
               if(i == 68)
                  printf("\b\b10");
               if(i == 78)
                  printf("\b\b20");
               if(i == 88)
                  printf("\b\b30");
               if(i == 98)
                  printf("\b\b40");
               if(i == 108)
                     printf("\b\b50");
               else
                  if(i <110)
                     printf(" ");
               if(result == i-57)
                     printf("\bN");
               
      
               i++;
            }
         }
         i++;
      }
      //printf("\nhastag = %d\nresult = %d",hastag,result);
      
      hastag++;
      deger_kumesi--;
      printf("\n");
      i = 0;
      j++;
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