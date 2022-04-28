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
	int yatay = 113;
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
			//	if(result == i-57)
			//		printf("\b#");

			}
			else if(j == 16)
			{
				while(j==16 && i<yatay && hastag ==j )
				{
					if(i ==0)
						printf("<");
					else if(i ==112)
						printf(">");
					else
					{
						printf("-");
					//	if(result == i-58)
					//		printf("\b#");
					}
					i++;
				}

			}
			else if(j==17)
			{
				while(j==17 && i <yatay)
				{
					if (i==0)
						printf("\b\b\b-55");
					if(i==10)
						printf("\b\b\b-45");
					if(i==20)
						printf("\b\b\b-35");
					if (i ==30)
						printf("\b\b\b-25");
					if(i == 40)
						printf("\b\b\b-15");
					if (i == 49)
						printf("\b\b-5");
					if (i == 53)
						printf("\b0");
					if (i == 53)
						printf("|");
					if(i == 58)
						printf("\b5");
					if(i == 69)
						printf("\b\b15");
					if(i == 79)
						printf("\b\b25");
					if(i == 89)
						printf("\b\b35");
					if(i == 99)
						printf("\b\b45");
					if(i == 109)
							printf("\b\b55");
					else
						if(i <111)
							printf(" ");
				//	if(result == i-57)
				//			printf("\b#");
				
		
					i++;
				}
			}
			i++;
		}
	//	printf("\nhastag = %d\nresult = %d",hastag,result);
		
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