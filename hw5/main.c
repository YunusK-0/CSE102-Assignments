#include<stdio.h>
#include<math.h>
    /* MY ALGORITYHM IS TO GET ONE BY ONE VALUE. WHEN IT GETS A VALUE IT CHECKS IS IT VALID OR NOT. IF IT IS, IT IS WAITING FOR SECOND VALUE. IF IT IS NOT IT SAYS THIS IS NOT AND WAITING FOR UNTIL VALID ONE.*/

    /* MY ALGORITYHM IS TO GET ONE BY ONE VALUE. WHEN IT GETS A VALUE IT CHECKS IS IT VALID OR NOT. IF IT IS, IT IS WAITING FOR SECOND VALUE. IF IT IS NOT IT SAYS THIS IS NOT AND WAITING FOR UNTIL VALID ONE.*/

    /* MY ALGORITYHM IS TO GET ONE BY ONE VALUE. WHEN IT GETS A VALUE IT CHECKS IS IT VALID OR NOT. IF IT IS, IT IS WAITING FOR SECOND VALUE. IF IT IS NOT IT SAYS THIS IS NOT AND WAITING FOR UNTIL VALID ONE.*/

#define PI 3.14

typedef enum
{
    Triangle=1,Quadrilateral,Circle,Pyramid,Cyclinder,Exit=0
}shapes;
typedef enum
{
    Area=1,Perimeter,Volume,exit=0
}calculators;

int select_shape(void); //selecting shape
int select_calc(void); // selecting calculation options.
int calc_triangle(int secim); // this is for triangle
int calc_quadrilateral(int secim); // this is for quadrilateral
int calculate(int (*ptr_shape)(void),int (*ptr_calc)(void)); // it takes functions as paramethers 
int calc_circle(int secim); // calculation of circle
int calc_pyramid(int secim); // based on square pyramid
int calc_cyclinder(int secim); // cyclinder


/* In MY CODE THERE ARE ''VALID'' VARIABLES BEFORE THAN SCANF IT CHECKS SCANF GET VALUE OR NOT IF IT IS GET RETURN 1 ELSE 0*/
int main()
{
    int (*ptr_shape)(void) = select_shape;
    int (*ptr_calc)(void) = select_calc;
    calculate(ptr_shape,ptr_calc);
}
int calculate(int (*ptr_shape)(void),int (*ptr_calc)(void))
{
    int donen_1;
    int donen_2;
    int result;
    shapes secilen_1;
    calculators secilen_2; 
    do
    {
        donen_1 = (*ptr_shape)(); // callling select shape function
        secilen_1 = donen_1;
        if(donen_1== -999)// checking return value
            printf("ERROR !!! INVALID\n"); 
        else if(secilen_1 != Exit)
        {
            donen_2 = (*ptr_calc)(); // calling calculation function.
            if(donen_2 == -999)
                printf("ERROR !!! INVALID\n");
            else
            {
                secilen_2 = donen_2; // assign the variable to my enum type
                if(secilen_2 != exit)
                {
                    switch (secilen_1)
                    {
                    case Triangle:
                        result = calc_triangle(secilen_2);
                        if(result == -999) // checking return value
                             printf("Error ! Triangle does not have volume !!!\n\n");
                        break;
                    case Quadrilateral:
                        result = calc_quadrilateral(secilen_2);
                        if(result == -999)
                            printf("ERROR !!! Quadrilateral does not have volume\n\n");
                        break;

                    case Circle:
                        result = calc_circle(secilen_2);
                        if(result == -999)
                        printf("ERROR !!! circle doesnt have volume \n\n");
                        break;
                    case Pyramid:
                        calc_pyramid(secilen_2);
                        break;
                    case Cyclinder:
                        calc_cyclinder(secilen_2);
                        break;
                    default:
                        break;
                    }
                }
                else
                    break;
            }
            

        }
        else 
            break;
        
        if(secilen_2== -999)
            printf("ERROR !!! INVALID\n");
    } while (secilen_1 !=  Exit || secilen_2 !=exit ); //the loop will continue until one of them is exit
   // printf("result = %d",donen_1);
  //  printf("xd : %d", (*ptr_calc)());

}

int select_shape(void)
{
    int secim;
    int valid = 0;
    int c ;
    char ch = 9;
    int flag;
    shapes gelen = -999;
    printf("Welcome to the geometric calculator!\n\n");
    printf("Select a shape to calculate:\n");
    printf("----------------------------\n");
    do
    {
        flag = 0;
        printf("1. Triangle\n2. Quadrilateral\n3. Circle\n4. Pyramid\n5. Cyclinder\n0. Exit\n");
        valid = (scanf("%d",&secim));

            while ((c = getchar()) != '\n' && c != EOF)                 // this line is used whole code. It was used to get a value for example '2' any other cases such as '2a' or 'a' or 'x' are reason to error
            {               // this line is used whole code. It was used to get a value for example '2' any other cases such as '2a' or 'a' or 'x' are reason to error
                if(c != 0)              // this line is used whole code. It was used to get a value for example '2' any other cases such as '2a' or 'a' or 'x' are reason to error
                    flag = 1;               // this line is used whole code. It was used to get a value for example '2' any other cases such as '2a' or 'a' or 'x' are reason to error
            }               // this line is used whole code. It was used to get a value for example '2' any other cases such as '2a' or 'a' or 'x' are reason to error

        gelen = secim;
        if(gelen < Exit || gelen > Cyclinder || valid ==0)
            printf("Error !\n");
    } while (gelen < Exit || gelen > Cyclinder || valid == 0 || secim <0 || secim >5);
    if(flag != 0)
        return -999; //returning error code
    else
        return gelen;
}

int select_calc(void)
{
    int secim;
    int valid= 0;
    int c;
    int flag = 0;
    calculators gelen;
    printf("Select calculator\n");
    printf("-------------------------\n");
    do
    {
        flag = 0;
        printf("1. Area\n2. Perimeter\n3. Volume\n0. Exit\n");
        valid = scanf("%d",&secim);
        while ((c = getchar()) != '\n' && c != EOF)
        {
                if(c != 0)
                    flag = 1;
        }

        gelen = secim;
        if(gelen < exit || gelen > Volume || valid == 0)
            printf("Error !\n");
    } while (secim < 0 || secim >3 || gelen <exit || gelen >Volume || valid == 0);
    if(flag != 0)
        return -999;
    else
        return gelen;
    
}
int calc_triangle(int secim)
{
    if(secim == Volume)
        return -999;

    double num1;
    double num2;
    double num3;
    double cevre;
    double result;
    int c;
    int flag_1;
    int flag_2;
    int flag_3;
    int valid_1= 0;
    int valid_2 = 0;
    int valid_3 = 0;
    printf("Please enter three sides of Triangle:\n");
    /* MY ALGORITYHM IS TO GET ONE BY ONE VALUE. WHEN IT GETS A VALUE IT CHECKS IS IT VALID OR NOT. IF IT IS, IT IS WAITING FOR SECOND VALUE. IF IT IS NOT IT SAYS THIS IS NOT AND WAITING FOR UNTIL VALID ONE.*/
    do 
    {
        do
        {
            flag_1 = 0;
            printf("enter first edge\n");
            valid_1 = scanf("%lf",&num1);
            while ((c = getchar()) != '\n' && c != EOF)
            {
                if(c != 0)
                    flag_1= 1;
            }
            if(flag_1 == 1)
                printf("Invalid number PLEASE try again\n");
        } while (num1 <=0 || valid_1==0 || flag_1== 1);
        do
        {
            flag_2 =0;
            printf("enter second edge \n");
            valid_2 = scanf("%lf",&num2);
            while ((c = getchar()) != '\n' && c != EOF)
            {
                if(c != 0)
                    flag_2= 1;
            }
            if(flag_2 == 1)
                printf("Invalid number PLEASE try again\n");
        } while (num2 <=0 || valid_2==0 || flag_2 ==1);
        do
        {
            flag_3 = 0;
            printf("enter third edge:\n");
            valid_3 = scanf("%lf",&num3);
            while ((c = getchar()) != '\n' && c != EOF)
            {
                if(c != 0)
                    flag_3= 1;
            }
            if(flag_3 == 1)
                printf("Invalid number PLEASE try again\n");
        } while (num3 <=0 || valid_3==0 || flag_3 == 1);
        if(num1 + num2 <=num3 || num2 + num3 <= num1 || num1 + num3 <=num2) // THIS IS CONDITION OF BEING TRIANGLE
        printf("ERROR !\n");
    }while(num1 + num2 <=num3 || num2 + num3 <=num1 || num1 + num3 <=num2);
    switch (secim)
    {
        case Area:
            cevre = (num1 + num2+ num3) /2 ; // HALF OF PERIMETER
            result = sqrt((cevre)* (cevre -num1) * (cevre - num2) *(cevre -num3));
            printf("Area is = %.2lf\n",result);
            break;
        case Perimeter:
            cevre = (num1 + num2+ num3) ; //CALCULATION OF PERIMETER
            printf("Perimeter is = %.2lf\n",cevre);
            break;
    }
    if(num1 >0 && num2 >0 && num3 > 0 && !(num1 + num2 <=num3 || num2 + num3 <= num1 || num1 + num3 <=num2))
        return 1;
    else
        return 0;
}
int calc_quadrilateral(int secim)
{
    if(secim == Volume) // QUADRILATERAL DOESN NOT HAVE VOLUME ERROR CODE!!!1!
        return -999;
    double num1;        // EVERY EDGE OF QUADRILATERAL
    double num2;        // EVERY EDGE OF QUADRILATERAL
    double num3;        // EVERY EDGE OF QUADRILATERAL
    double num4;        // EVERY EDGE OF QUADRILATERAL
    char c;
    double cevre;
    double result;
    int flag_1;
    int flag_2;
    int flag_3;
    int flag_4;
    int valid_1= 0;
    int valid_2 = 0;
    int valid_3 = 0;
    int valid_4 = 0;
    printf("Please enter four sides of Triangle:\n");
    do
    {
        do
        {
            flag_1 = 0;
            printf("enter first edge\n");
            valid_1 = scanf("%lf",&num1);
            while ((c = getchar()) != '\n' && c != EOF)
            {
                if(c != 0)
                    flag_1= 1;
            }
            if(flag_1 == 1)
                printf("Invalid number PLEASE try again\n");
        } while (num1 <=0 || valid_1==0 || flag_1 == 1 );
        do
        {
            flag_2 = 0;
            printf("enter second edge \n");
            valid_2 = scanf("%lf",&num2);
            while ((c = getchar()) != '\n' && c != EOF)
            {
                if(c != 0)
                    flag_2= 1;
            }
            if(flag_2 == 1)
                printf("Invalid number PLEASE try again\n");
        } while (num2 <=0 || valid_2==0 || flag_2 == 1);
        do
        {
            flag_3 = 0;
            printf("enter third edge:\n");
            valid_3 = scanf("%lf",&num3);
            while ((c = getchar()) != '\n' && c != EOF)
            {
                if(c != 0)
                    flag_3= 1;
            }
            if(flag_3 == 1)
                printf("Invalid number PLEASE try again\n");
        } while (num3 <=0 || valid_3==0 || flag_3 == 1);
        do
        {
            flag_4 =0;
            printf("enter 4. edge\n");
            valid_4 = scanf("%lf",&num4);
            while ((c = getchar()) != '\n' && c != EOF)
            {
                if(c != 0)
                    flag_4= 1;
            }
            if(flag_4 == 1)
                printf("Invalid number PLEASE try again\n");
        } while (num4 <=0 || valid_4==0 || flag_4 == 1 );
        cevre = (num1 + num2+ num3+ num4) /2;
        if(cevre <num1 || cevre <num2 || cevre < num3 || cevre <num4) // THIS IS CONDITION OF BEING QUADRILATERAL
            printf("ERROR! NON VALID QUADRILATERAL\n");

    }while(cevre <num1 || cevre <num2 || cevre < num3 || cevre <num4);
    switch (secim)
    {
        case Area:
            cevre = (num1 + num2+ num3+ num4) /2 ;
            result = sqrt((cevre-num4)* (cevre -num1) * (cevre - num2) *(cevre -num3));
            printf("Area is = %.2lf\n",result);
            break;
        case Perimeter:
            cevre = (num1 + num2+ num3 + num4) ;
            printf("Perimeter is = %.2lf\n",cevre);
            break;
    }
    return 1;
}
int calc_circle(int secim)
{
    if(secim == Volume)
        return -999;
    double num1; // RADIUS
    char c;
    int valid_1;
    double cevre;
    int flag;
    double result;
    do
    {
        flag = 0;
        printf("enter radius\n");
        valid_1 = scanf("%lf",&num1);
        while ((c = getchar()) != '\n' && c != EOF)
            {
                if(c != 0)
                    flag= 1;
            }
            if(flag == 1)
                printf("Invalid number PLEASE try again\n");
    } while (num1 <=0 || valid_1==0 || flag ==1);

    switch (secim)
    {
        case Perimeter:
            cevre = 2 * PI * num1;
            printf("𝑪𝒊𝒓𝒄𝒖𝒎𝒇𝒆𝒓𝒆𝒏𝒄𝒆 is %.2lf\n\n",cevre);
            break;
        case Area:
            result = PI * num1* num1;
            printf("Area is %.2lf\n\n",result);
            break;

    }
}

int calc_pyramid(int secim)
{
    double num1;
    char c;
    int valid_1;
    double num2;
    int valid_2;
    double result;
    double B;
    double L;
    int flag_1;
    int flag_2;
    double cevre;
    double surface_area;
    do
    {
        flag_1 = 0;
        printf("enter edge of square \n");
        valid_1 = scanf("%lf",&num1);
        while ((c = getchar()) != '\n' && c != EOF)
            {
                if(c != 0)
                    flag_1= 1;
            }
            if(flag_1 == 1)
                printf("Invalid number PLEASE try again\n");
    } while (num1 <=0 || valid_1==0 || flag_1 == 1);
    if(secim != Perimeter)
    {
        do
        {
            flag_2 =0;
            if(secim == Area)
                printf("enter slant height of the pyramid\n");
            if(secim == Volume)
                printf("enter the height of pyramid\n\n");
            valid_2 = scanf("%lf",&num2);
            while ((c = getchar()) != '\n' && c != EOF)
            {
                if(c != 0)
                    flag_2= 1;
            }
            if(flag_2 == 1)
                printf("Invalid number PLEASE try again\n");
        } while (num2 <=0 || valid_2==0 || flag_2 == 1);
    }
    switch (secim)
    {
        case Perimeter:
            cevre = 4* num1;
            printf("Perimeter is %.2lf\n",cevre);
            break;
        case Area:
            B = num1* num1;
            printf("Base surface area is %.2lf\n",B);
            L = 2* num1*num2;
            printf("Lateral surface area is %.2lf\n\n",L);
            surface_area = B + L;
            printf("Surface area is %.2lf\n\n",surface_area);
            break;
        case Volume:
            result = num1*num1*num2/3;
            printf("Volume of pyramid is %.2lf\n\n",result);
            break;
    }
}

int calc_cyclinder(int secim)
{
    double num1; // RADIUS
    char c;
    int valid_1;
    double num2; //HEIGHT
    int valid_2;
    int flag_1;
    int flag_2;
    double surface_area;
    double lateral;
    double base;
    double cevre;
    double volume;
    do
    {
        flag_1=0;
        printf("enter radius\n");
        valid_1 = scanf("%lf",&num1);
        while ((c = getchar()) != '\n' && c != EOF)         // THIS IS LIKE OTHER CLEARING BUFFER.
            {           // THIS IS LIKE OTHER CLEARING BUFFER.
                if(c != 0)          // THIS IS LIKE OTHER CLEARING BUFFER.
                    flag_1=1;           // THIS IS LIKE OTHER CLEARING BUFFER.
            }           // THIS IS LIKE OTHER CLEARING BUFFER.
            if(flag_1 == 1)         // THIS IS LIKE OTHER CLEARING BUFFER.
                printf("Invalid number PLEASE try again\n");            // THIS IS LIKE OTHER CLEARING BUFFER.
    } while (num1 <=0 || valid_1==0 || flag_1 == 1 );
    do
    {
        flag_2 = 0;
        valid_2 = scanf("%lf",&num2);
        while ((c = getchar()) != '\n' && c != EOF)
            {
                if(c != 0)
                    flag_2= 1;
            }
            if(flag_2 == 1)
                printf("Invalid number PLEASE try again\n");
    } while (num2 <=0 || valid_2==0 || flag_2 ==1 );

    switch(secim)
    {
        case Area:
            base = PI * num1*num1;
            printf("Base surface area is %.2lf\n",base);
            lateral = 2 * PI * num1* num2;
            printf("Lateral surface area is %.2lf\n\n",lateral);
            surface_area= 2 *PI * num1 *(num1+num2);
            printf("Surface area is %.2lf\n\n",surface_area);
            break;

        case Perimeter:
            cevre = 2 * PI * num1;
            printf("Base surface perimeter of a cyclinder %.2lf\n",cevre);
            break;
        case Volume:
            volume= PI * num1 *num1* num2;
            printf("Volume of a cyclinder is %.2lf\n\n",volume);
            break;

    }
}