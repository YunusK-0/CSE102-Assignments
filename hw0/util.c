#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
    printf("%d//%d", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 + n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 - n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3= n1*n2;
    *d3= d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3= n1*d2;
    *d3= d1*n2;
    fraction_simplify(n3, d3);
} /* end fraction_div */


void fraction_simplify(int * n, int * d) {
    int flag1;
    int flag2;
    int gcd; // simplify for the fraction
    flag1=0; // both flag will be used for understanding whether or not *n and *d are negatif. if they are, the code will multiply with -1 
    flag2=0;
    gcd = 1;
    if (*n < 0)
    { 
    	flag1++;
     *n = *n * -1;
     
    }
    if (*d < 0)
    { 
    	flag2++;
     *d = *d * -1;
     
    }
    
    while(gcd <= *n && gcd <= *d)
    {
    	if(*n %gcd ==0 && *d %gcd == 0)
    	{
    		*n = *n / gcd;
    		*d = *d /gcd;
    	gcd =1; // it has to become 1 for every simlify action for example a number can be divided by 4 but when we start diving with 2 it will increase and it will 3. At the same time the number can be divided by 2 again but gcd is 3 so that's why it should be used.
    	}
    	gcd++;
    }
    
    if(flag1 == 1 && flag2==1)
    	;
    else if (flag1 == 1 || flag2== 1)
     *n = *n * -1;
   
} 
