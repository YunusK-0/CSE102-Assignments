#include<stdio.h>
#include<math.h>
/* IN THIS CODE THERE SOME PRINTF FUNCTIONS BECAUSE WHEN I WAS CODING I NEEDED TO SEE WHAT IS HAPPENING SO THAT'S WHY I PUT THEM. AFTER I DONE THEY ARE IN COMMENT SECTION*/
void theory_of_everything(void); // the menu is here;
int sum(int n1, int n2, int flag); 
int multi(int n1, int n2, int flag);
void write_file(int number);
int isprime(int a);
void print_file(void);
void sort_file(void);
int counting(FILE * ptr); // this function is help to find how many numbers there in result.txt
int max_of_file(FILE * ptr); // // this function is help to find the biggest number in result.txt
void	first_min_3(FILE * ptr, FILE * ptr_temp); // it helps me to find out every 3 numbers which are the min.
void	filling_temp_text(FILE *ptr_temp , int num); // it is write the min values which are got from result.txt on temp.txt
void deleting(FILE * ptr, int num); // it is deleting min numbers from result.txt
void file_copy(FILE * ptr, FILE * ptr_temp); //  after deleting it get numbers from temp.txt to result.txt
int counting_temp(FILE * ptr_temp);// this function is help to find how many numbers there in temp.txt

int main(void)
{
	theory_of_everything();

}
void theory_of_everything(void)
{
	int fark;
	int bayrak = 0; // it is also flag but i have the variable which name is flag;
	int gorev2_sayi;
	int secim;
	int num1;
	int num2;
	int karar;
	int flag;
	int cevap;
	int temp ;// temporary variable for if n1> n2 
	cevap = 0;
	do
	{
		printf("Select operation\n1. Calculate sum/multiplication between\n2. Calculate prime numbers\n3. Show number sequence in file\n4. Sort number sequence in file.\n0. For exit\n");
		scanf("%d", &secim);
	
			if(secim == 1)
			{
				printf("Please enter '0' for sum, '1' for multiplication\n");
				scanf("%d",&karar);
				switch (karar)
				{
					case 0:
						printf("Please enter '0' to work on even numbers, '1' to work on odd numbers\n");
						scanf("%d",&flag);
						if(flag != 0 && flag != 1)
						{
							printf("error please press 1 or 0x\n");
							break;
							}
						
						do
						{
							printf("Please enter two different number:\nNumber 1:");
							scanf("%d",&num1);
							printf("\nNumber 2: ");
							scanf("%d",&num2);
							if(num1>num2)
							{
								temp = num1;
								num1= num2;
								num2 = temp;
							}
							fark = num2 -num1;

							if(num1 < 0 || num2 < 0)
								printf("error. There is no number between them\n");
						}
						while((num1 < 0 || num2 <0) && fark != 2); // i have many ideas about what fark does. however i dont touch if the code works.
						if(num1>num2) // THIS IS FOR IF FIRST NUMBER GREATER THAN SECOND NUMBER, I SWAP THEM.
						{
							temp = num1;
							num1= num2;
							num2 = temp;
						}
						temp = num1;
						fark = num2 -temp;
						if(num2 % 2 == 0 && num1 % 2 == 0 && flag == 0 && fark == 2)
						{
							printf("there is no numbers between them\n");
							break;
						}
						if(num2 % 2 == 1 && num1 % 2 == 1 && flag == 1 && fark == 2)
						{
							printf("there is no numbers between them\n");
							break;
						}
						cevap = 0;
						while(sum(temp,num2,flag) != 0 && !(temp >= num2) && fark != 2)
						{
							cevap +=sum(temp,num2,flag); // STACKING THE NUMBERS WHICH ARE COMING FROM SUM
							temp = sum(temp,num2,flag); // TEMPS MAKES THE RANGE NARROW
									printf("%d+",temp);
						}
						if(cevap != 0) // THIS IS CASE FOR 12-14 FOR EVEN NUMBERS. THERE IS NO NUMBERS BETWEEN THEM. I CHECK IT IF IT NOT 0 GO ON.
							printf("\b = %d\n\n",cevap);
						else
						{
							printf("=%d\n\n", temp+1);
							break;
						}
						write_file(cevap);
						cevap = 0;
						break;


					case 1:
						printf("Please enter '0' to work on even numbers, '1' to work on odd numbers\n");
						scanf("%d",&flag);
						if(flag != 0 || flag != 1)
						{
								while(flag != 1 && flag != 0)
							{
							printf("it is invalid. please try again \n");
							scanf(" %d ",&flag);
							}
						}
						do
						{
							printf("Please enter two different number:\nNumber 1:");
							scanf("%d",&num1);
							printf("\nNumber 2:");
							scanf("%d",&num2);
						}
						while(num1 < 0 || num2 <0);
	
						if(num1>num2)
						{
							temp = num1;
							num1= num2;
							num2 = temp;
						}
						temp = num1;
						cevap = 1;
						if(num2 % 2 == 1 && num1 %2 == 1)
						{
							printf("there is no number between them\n");
							break;
						}
						while(multi(temp,num2,flag) != 1)
						{
							cevap *=multi(temp,num2,flag); // STACKING RESULT OF MULTI FUNCTION THE SAME AS SUM FUNCTION
							temp = multi(temp,num2,flag) ;
							printf("%d * ",temp);
						}
						if(cevap != 1)
							printf("\b\b = %d\n\n",cevap);
						else
						{ 
							printf("%d =%d \n",temp+1,temp+1);
							break;
						}
						write_file(cevap);
						break;
					default:
						printf("error has occured. Please select from 0 to 1\n");
						break;
	
				}	
		}
		else if(secim == 2)
		{
			int checking;
			gorev2_sayi = 0;
			bayrak = 0;
			checking = 0; // IT IS KIND OF CONTROLL.
			for(;bayrak != 1;)
			{
				printf("give an positive integer\n");
				scanf("%d",&gorev2_sayi);
				if(gorev2_sayi > 1)
					bayrak++;
			}
			if(gorev2_sayi != 2)
				gorev2_sayi -= 1;
			int baslangic;
			for(baslangic = 2;baslangic <= gorev2_sayi; baslangic++)
			{
				checking = isprime(baslangic);
				//printf("checking == %d ||| gorev2_sayi %d\n",checking,gorev2_sayi);
				if(checking == 0)
					printf("%d is prime\n",baslangic);
				else
				{
					printf("%d is not a prime number, it is dividible by %d\n", baslangic,checking);
					checking = 0;
				}
			}
		}

		else if(secim == 3)
		{
			print_file();
		}
		else if(secim == 4)
		{
			sort_file();
		}
		else if(secim == 0)
			;
		else
			printf("error. Please select a valid number from 0 to 4");

	}
	while(secim != 0);
}

int sum(int n1, int n2, int flag) /* in this function it finds out every numbers which the user gives us in range. */
{
	if(n1 +2>n2 )
		return 0;
	if(n1 %2 != flag)
	{
		n1 += 1;
	//printf("%d ",n1);
		return n1;
	}
	if(n2 %2 != flag)
		n2 -= 1;
	if(n1  %2 == flag && !(n1>n2))
	{
		return n1+2;
	}
	return 0;
}

int multi(int n1, int n2, int flag)
{
	if(n1+2 > n2 )
		return 1;
	if(n1 %2 != flag)
	{
		n1 += 1;
	//	printf("%d ",n1);
		return n1;
	}
	if(n2 %2 != flag)
		n2 -= 1;
	if(n1  %2 == flag && !(n1+2>=n2))
	{
		return n1+2;
	}
	return 1;
}

void	write_file(int number)
{
	FILE * ptr;
	ptr = fopen("result.txt","a"); // APPENDING ON THE FILE.
	fprintf(ptr, "%d ",number);
	fclose(ptr);
}

int isprime(int a)
{
	int c;
	double temp;
	double kok;
	kok = sqrt((double )a);
	int i; // 'I' SHOULD START FROM 2 BECAUSE EVERY NUMBER CAN BE DIVEDED 1.
	int flag = 0;
	for(i = 2; i<=(int)kok; i++)
	{
		//printf("kok = %d", (int)kok);
		if(a% i == 0)
			return i;
	}
	return 0;
}

void print_file(void)
{
	int temp;
	FILE * ptr;
	ptr = fopen("result.txt","r");
	rewind(ptr);
	while(!feof(ptr))
	{
		fscanf(ptr,"%d ",&temp);
		printf("%d ",temp);
	}
	fclose(ptr);
}
void sort_file(void)
{
	FILE * ptr;
	FILE * ptr_temp;
	int eleman_sayisi;
	ptr = fopen("result.txt","r+");
	ptr_temp = fopen("temp.txt","w+");
	eleman_sayisi = counting(ptr);
	eleman_sayisi = (eleman_sayisi /3) + 1; // IF THERE ARE 9 NUMBERS THE FUNCTION SHOULD RETURN 3 TIMES. HOWEVER, IF THERE IS 8 NUMBERS THE FUNCTION SHOULD RETURN 3 TIMES SO THAT'S WHY THERE IS PLUS 1.
	while(eleman_sayisi>0)
	{
		first_min_3(ptr, ptr_temp);
		eleman_sayisi--;
	}
	file_copy(ptr,ptr_temp);
	rewind(ptr);
	print_file();

	fclose(ptr);
	fclose(ptr_temp);

}

int counting(FILE * ptr)
{
	int i = 0;
	int temp;
	while(!feof(ptr))
	{
		fscanf(ptr,"%d ",&temp);
		i++;
	}
	rewind(ptr);
	return i;

}

int max_of_file(FILE * ptr)
{
	int temp2 = 0;
	int temp = 0;
	while(!feof(ptr))
	{
		fscanf(ptr,"%d",&temp);
		if(temp > temp2)
			temp2 = temp;
	}
	rewind(ptr);
	return temp2;
}

void	first_min_3(FILE * ptr, FILE * ptr_temp)
{
	rewind(ptr);
	int min1 = max_of_file(ptr); // IT SHOULD BE DECREASED SO THIS IS MY ALGORIRTHYM
	int min2= min1;
	int min3 = min2;
	int okunan;
	int valid = 0; // CHECKING FOR IF FSCANF GET A VALUE OR NOT
	int konum1 =0; /* KONUM1 AND KONUM2 FOR MANIPULATION OF FILE.*/
	int konum2;
	int sayac = 0;
	int fark;
	int flag_1= 0;
	int flag_2 = 0;
	int flag_3 = 0;
	int eleman_sayisi = counting(ptr);


	do
	{
		valid =fscanf(ptr," %d ",&okunan);
		if(okunan <min1)
			min1= okunan;

	}
	while(!feof(ptr));
	rewind(ptr);
	if(valid == 1)
	{
	filling_temp_text(ptr_temp,min1); // BEFORE DELETING IT SHOULD BE PRINTED ON TEMP.TXT
	deleting(ptr,min1);
	//printf("min 1 = %d\n ",min1);
	}
	valid = 0;

	do
	{
		valid =	fscanf(ptr," %d ",&okunan);
		if(min2 >okunan)
			min2= okunan;

	}
	while(!feof(ptr));
	rewind(ptr);
	if(valid == 1)
	{

	filling_temp_text(ptr_temp,min2); 
	deleting(ptr,min2);
//	printf("min 2= %d\n ",min2);
	}
	valid = 0;


	do
	{
		valid = fscanf(ptr," %d ",&okunan);
		if(okunan <min3)
			min3= okunan;

	}
	while(!feof(ptr));
	rewind(ptr);
	if(valid == 1)
	{
	filling_temp_text(ptr_temp,min3); 
//	printf("min 3 = %d\n ",min3);
	deleting(ptr,min3);
	}
	valid = 0;
	rewind(ptr);

}

void filling_temp_text(FILE * ptr_temp ,int min)
{
	fprintf(ptr_temp,"%d ",min);
}
void deleting(FILE * ptr, int num)
{
	int konum1;
	int konum2;
	int fark;
	int temp;
	int okunan;
	int counter =0;
	do
	{
		konum1= ftell(ptr); // IT CHECKS EVERY NUMBERS FOR THE NUMBER WHICH I LOOKING FOR.
		fscanf(ptr," %d ",&okunan);
		if(okunan == num)
		{
			counter= 1;
			konum2 = ftell(ptr); // WHEN I GET THE POSITION OF THE NUMBER WHICH I LOOKING FOR NOW I CAN MANIPULATE IT.
			fark = konum2-konum1-1; // I NEED TO KNOW HOW MANY DIGIT THE NUMBER HAS SO THIS TELL ME.
			fseek(ptr,konum1,SEEK_SET);
			while(fark> 0)
			{
				fprintf(ptr," "); // THE NUMBERS OF DIGIT TIMES IT PUTS SPACE.
				fark--;
			}


		}
	}
	while(!feof(ptr) && counter != 1);
	rewind(ptr);
}

void file_copy(FILE * ptr, FILE * ptr_temp)
{
	int temp;
	rewind(ptr);
	rewind(ptr_temp);
	int eleman_sayisi = counting_temp(ptr_temp); // KNOWING HOW MANY NUMBERS THERE ARE IN TEMP.TXT
	while(eleman_sayisi > 0)
	{
		fscanf(ptr_temp,"%d ",&temp);
		fprintf(ptr,"%d ",temp);
		eleman_sayisi--;
		//printf("burdayim");
	}


}
int counting_temp(FILE * ptr_temp) // COUNT HOW MANY NUMBERS THERE ARE IN TEMP.TXT
{
	int i = 0;
	int temp;
	while(!feof(ptr_temp))
	{
		fscanf(ptr_temp,"%d ",&temp);
		i++;
	}
	rewind(ptr_temp);
	return i;
}