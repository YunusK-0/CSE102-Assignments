#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
    in the all code there are control and kontrol variables. it helps me to know if it is valid or not input.
    LOAN.TXT IT HAS FIRSTLY ID NUMBER AND THEN LOANS. FOR EXAMPLE: 1 2000 1200 (IT MEANS ID NUMBER ==1 AND IT HAS 2 LOANS WHICH ARE 2000 AND 1200)
*/
union Person
{
    char name[50];
    char address[50];
    int phone;
};
union Loan
{
    float arr[3];
};
struct BankAccount
{
    union Person Customer;
    union Loan Loans[3];
};
void print_customer(int *kacinci,int id,int kredi[],FILE * p_ptr,float (*loan_detail)[3][3]);// it gets data from txt for who get loans .
void addCustomer(char filename[20],int *kacinc, struct BankAccount musteri[]); // it adds customers
void listCustomer(struct BankAccount musteri[],int *kacinci); // listing all the customers with id and name.
void newLoan(struct BankAccount musteri[],int *kacinci,int kredi[],float (*loan_detail)[3][3]); // it provides new loans for customers.
float calculateLoan(float amount,int period,float interestRate); // it calculates loan
void getReport(int *kacinci,int kredi[],float (*loan_detail)[3][3]);
void print_without_loan(int kacinci,int id,int kredi[]); // it gets data from txt for who didn't get any loans from us.
int before_starting(void);// this is for before execating the program
int main()
{
    int kredi[51]={0};
    struct BankAccount musteri[50];
    int secim;
    int kontrol;
    char c;
    char filename[20]="customer.txt";
    int kacinci = before_starting();
    float loan_detail[51][3][3] = {};
    do
    {
        printf("Welcome to the Bank managment System\n");
        printf("========================================\n");
        printf("1. List all Customers\n");
        printf("2.Add New Customer\n");
        printf("3. New Loan Application\n");
        printf("4. Report Menu\n");
        printf("5.Exit system\n");
        kontrol = scanf("%d",&secim);
        if(kontrol != 1)
            while(getchar() != '\n');
        else
        {
            if(secim ==2 )
                addCustomer(filename,&kacinci,musteri);
            else if(secim == 1)
                listCustomer(musteri,&kacinci);
            else if (secim == 3)
                newLoan(musteri,&kacinci,kredi,loan_detail);
            else if(secim == 4)
                getReport(&kacinci,kredi,loan_detail);
            
        }
    } while (secim != 5);
    
}
int before_starting(void)// this function helps to program to know how many members are there in loan.txt. So how it know previous users. 
{
    FILE *y_ptr;
    int counter = 0;;
    y_ptr = fopen("customer.txt","a+");
    char input[100];
    int flag = 2;
    int c;
    while((c = getc(y_ptr))  != -1)
    {
        if(c == 10)
            counter +=1;
    }
    fclose(y_ptr);
    return counter/5;
    
}

void listCustomer(struct BankAccount musteri[],int *kacinci)
{
    int i;
    for(i=0;i<*kacinci;i++)
    {
        printf("Customer id = %d\nCustomer name = %s\n",i+1,musteri[i].Customer.name);
        printf("--------------------------------\n");
    }

}
void getReport(int *kacinci,int kredi[],float (*loan_detail)[3][3])
{
    int i;
    int temp;
    int secim;
    int cus;
    int credi_num;
    FILE *ptr;
    int control;
    int flag =2;
    ptr = fopen("customer.txt","r");
    FILE * pointer;
    pointer = fopen("loan.txt","r");
    do
    {
        printf("1. Customer detail\n"
                            "2. Loan detail\n");
        control = scanf("%d",&secim);
        if(control != 1)
        {
            while(getchar() != '\n');
            printf("invalid !!! \n");
        }
    }while(control == 0);
    if(secim == 1)
    {
        for(i = 0;i<=*kacinci;i++)
        {
            while(fscanf(pointer,"%d",&temp) != EOF)
            {
                fseek(pointer,ftell(pointer)+1,SEEK_SET);
                if(temp == i)
                {
                   // printf("-----ftell loan.txt =%ld+++",ftell(pointer));
                    print_customer(kacinci,i,kredi,pointer,loan_detail);
                    flag = 0;
                    break;
                }
                else
                    flag=1;

            }
            if(flag== 1)
                print_without_loan(*kacinci,i,kredi);

            fseek(pointer,0,SEEK_SET);
        }
    }
    else if(secim == 2)
    {
        do
        {
            printf("Which costumer do want to look at the loans? Please enter id number...\n");
            control = scanf("%d",&cus);
            if(control != 1)
                while(getchar() != '\n');
            if(cus > *kacinci)
                printf("error invalid !!!\n");
        }while(cus > *kacinci || control == 0); // id numarası elimizde olmayan herhangi birinie bakarsa program burada hata veriyor.
        do
        {
            printf("which credit do want to look at %d. id ?\n",cus);
            control = scanf("%d",&credi_num);
            if(control != 1)
                while(getchar() != '\n');
            if(credi_num > loan_detail[cus][1][0])
                printf("error invalid !!!\n");
        }while(control == 0 || cus >(int)loan_detail[cus][1][0]);
        printf("TOTAL CREDIT IS %lf\n",loan_detail[cus][2][credi_num-1]);
        for(int j = 0; j< loan_detail[cus][0][credi_num-1];j++)
        {
            printf("%d. Month Installement is =%lf\n",j+1, loan_detail[cus][2][credi_num-1]/ loan_detail[cus][0][credi_num-1]);
        } // ÇEKTİĞİ KREDİNİN ÖDEMEK İSTEDİĞİ AYA BÖLÜMÜ BURADA YAPILIYOR.
        
    }
    fclose(ptr);
    fclose(pointer);
}
void print_without_loan(int kacinci,int id,int kredi[]) // it works fro who didn't have any loans. It prints them in third option of menu.
{
    FILE *x_ptr;
    x_ptr = fopen("customer.txt","r");
    char input[50]="Customer id = ";
    char text[20];
    char get[50];
    double temp;
    double result = 0;
    sprintf(text,"%d",id);
    strcat(input,text);
    while(fscanf(x_ptr,"%s",get) != EOF)
    {
        if(strcmp(text,get) == 0)
        {
            printf("Computer id =  %s",text);
            for(int i= 0;i<4;i++)
            {
                fgets(get,50,x_ptr);
                printf("%s",get);
            }
            printf("loan = [");
            printf("0] = %lf\n",result);
            break;
        }
        
    }
    fclose(x_ptr);

}
void addCustomer(char filename[20],int *kacinci,struct BankAccount musteri[])
{
    if(*kacinci <= 50)
    {
        int kontrol;
        union Person kisi;
        FILE *ptr;
        ptr = fopen(filename,"a+");
        printf("Enter customer name\n");
        scanf(" %[^\n]%*c",kisi.name);
        strcpy(musteri[*kacinci].Customer.name,kisi.name);
        fprintf(ptr,"Customer id = %d\n",*kacinci+1);
        fprintf(ptr,"Customer name = %s\n",kisi.name);
        do
        {
            printf("Enter phone number\n");
            kontrol = scanf("%d",&kisi.phone);
            if(kontrol != 1)
            {
                while(getchar() != '\n');               // it cheks whether or not valid phone number.
                printf("INVALID PHONE NUMBER !!\n");    // it cheks whether or not valid phone number.    
            }
        }while(kontrol == 0);
        fprintf(ptr,"Customer phone = %d\n",kisi.phone);
        printf("Enter address = ");
        scanf(" %[^\n]%*c",kisi.address);
        fprintf(ptr,"Customer address = %s\n\n",kisi.address);
        *kacinci+=1;
        fclose(ptr);
    }
    else
        printf("THERE ARE 50 PEOPLE !!!! ");
}
void newLoan(struct BankAccount musteri[],int *kacinci,int kredi[],float (*loan_detail)[3][3])
{
    FILE * pointer;
    int kontrol;
    pointer = fopen("loan.txt","a+");
    int who;
    int times;
    int i;
    float result;
    union Loan dizi;
    do
    {
        printf("Which customer do you want to have loan. Please enter id number.");
        kontrol = scanf("%d",&who);
        if(kontrol != 1)
        {
            while(getchar() != '\n');
            printf("invalid");
        }
        if(who>*kacinci)
            printf("Error !! Invalid...\n");
    }while(who>*kacinci && who >0);
    do
    {
        printf("Enter how many loans is going to be taken(from 1 to 3)\n");
        kontrol = scanf("%d",&times);
        if(kontrol != 1)
        {
            while(getchar() != '\n');
            printf("invalid");
        }
    } while (times >3 || kontrol == 0);
    for(i=0;i<times;i++)
    {
        do
        {
            printf("Please enter Amount\n");
            kontrol = scanf("%f",&dizi.arr[0]);
            if(kontrol != 1)
            {
                while(getchar() != '\n');
                printf("INVALID Amount !!\n");
            }
        }while(kontrol == 0);
        do
        {
            printf("Please enter period(months)\n");
            kontrol = scanf("%f",&dizi.arr[1]);
            if(kontrol != 1)
            {
                while(getchar() != '\n');
                printf("INVALID period !!\n");
            }
        }while(kontrol == 0);
        do
        {
            printf("Please enter interestrate\n");
            kontrol = scanf("%f",&dizi.arr[2]);
            if(kontrol != 1)
            {
                while(getchar() != '\n');
                printf("INVALID interestate !!\n");
            }
        }while(kontrol == 0);
        result = calculateLoan(dizi.arr[0],dizi.arr[1],dizi.arr[2]);
        fprintf(pointer,"%d %.2lf",who,result);
        loan_detail[who][1][0] = times; // 3. BOYUTLU BİR ARRAYDE WHO 1 0 KISMI KAÇ KREDİ ÇEKTİĞİNİ TUTYOR
        loan_detail[who][0][i] = dizi.arr[1]; // BU KISIM ÇEKTİĞİ HER KREDİNİN KAÇ AYLIK OLDUĞUNU TUTUYOR
        loan_detail[who][2][i] = result; // ÇEKTİĞİ HER KREDİNİN GERİ ÖDEME MİKTARINI TUTUYOR
        loan_detail[who][1][1] += result; // ÇEKTİĞİ TOPLAM TUTARLARI BURADA TUTUYORUM.
    }
    fprintf(pointer,"\n");
    kredi[who]=times;
    fclose(pointer);
}
float calculateLoan(float amount,int period,float interestRate)
{
    if(period == 0)
        return amount ;
    else
        return amount = (1+interestRate) * calculateLoan(amount,period-1,interestRate);
}
void print_customer(int *kacinci,int id,int kredi[],FILE *p_ptr,float (*loan_detail)[3][3])
{ // KODUN BU KISMINDA CUSTOMER.TXT İLE LOAN.TXT ARASINDAKİ BAĞLANTI KURULUYOR. SPRİNT İLE İD STRİNGE DÖNÜŞTÜRÜLÜYOR SONRADA BU KISIM LOAN.TXT DE ARANIYOR
    FILE * ptr;
    ptr = fopen("customer.txt","r");
    FILE * point;
    point = fopen("loan.txt","r");
    char input[50]="Customer id = ";
    char text[20];
    char get[50];
    //char gelen[50];
    double temp;
    double result = 0;
    sprintf(text,"%d",id);
    strcat(input,text);
    while(fscanf(ptr,"%s",get) != EOF)
    {
        if(strcmp(text,get) == 0)
        {
            printf("Computer id =  %s",text);
            for(int i= 0;i<4;i++)
            {
                fgets(get,50,ptr);
                printf("%s",get);
            }
            printf("loan = [");
            //fseek(p_ptr,ftell(p_ptr)-1,SEEK_SET);
            for(int i= 0;i<kredi[id];i++)
            {
                fseek(p_ptr,ftell(p_ptr)-1,SEEK_SET);
                fscanf(p_ptr,"%*c %lf",&temp);
                //printf("((loanda imlec şuan = %ld))",ftell(p_ptr));
                fseek(p_ptr,ftell(p_ptr),SEEK_SET);
                result += temp;
                printf("%lf+",temp);
            }
            printf("\b] = %lf\n",result);
        }
        //else
        //    printf("%s\n",get);
    }
    
}