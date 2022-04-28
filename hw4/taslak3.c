#include<stdio.h>

void drawing_graph(void);

int main()
{
	drawing_graph();
}

void drawing_graph(void)
{
	int yatay = 112;
	int dikey = 33;
	int i = 0;
	int j = 0;

	while(j<dikey)
	{
		while(i<yatay && j != 15 && j!= 16)
		{
			printf(" ");
			if( i == 55 && j==0)
				printf("^");
			else if(i == 55)
				printf("|");
			i++;
		}
		while(j==15 && i<yatay)
		{
			if(i ==0)
				printf("<");
			else if(i ==114)
				printf(">");
			else
				printf("-");
			i++;
		}

		while(j==16 && i <yatay)
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
			else
				printf(" ");


			i++;
		}
		printf("\n");
		i = 0;
		j++;
	}
}