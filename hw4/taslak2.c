#include<stdio.h>

void drawing_graph(void);

int main()
{
	drawing_graph();
}

void drawing_graph(void)
{
	int yatay = 113;
	int dikey = 33;
	int i = 0;
	int j = 0;

	while(j<dikey)
	{
		while(i<yatay && j != 15)
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
			else if(i ==112)
				printf(">");
			else
				printf("-");
			i++;
		}
		printf("\n");
		i = 0;
		j++;
	}
}