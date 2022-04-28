#include<stdio.h>

void drawing_graph(void);

int main()
{
	drawing_graph();
}

void drawing_graph(void)
{
	int yatay = 113;
	int dikey = 32;
	int i = 0;
	int j = 0;

	while(j<dikey)
	{
		while(i<yatay && j != 16 && j!= 17)
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
			i++;
		}
		while(j==16 && i<yatay)
		{
			if(i ==0)
				printf("<");
			else if(i ==112)
				printf(">");
			else
				printf("-");
			i++;
		}


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
			if(i == 80)
				printf("\b\b\b25");
			if(i == 91)
				printf("\b\b\b35");
			if(i == 102)
				printf("\b\b\b45");
			if(i == 112)
				printf("\b\b55");

			else
				printf(" ");


			i++;
		}

		printf("\n");
		i = 0;
		j++;
	}
}