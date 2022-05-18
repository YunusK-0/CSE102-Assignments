#include<stdio.h>
#include<stdlib.h>
#include "util.h"

void generate_sequence(int xs, int currentlen,int seqlen,int *seq) // creating sequence is done here.
{
    if(currentlen < seqlen)
    {
        seq[0] = xs;
        if(xs % 2 == 0)
            xs /= 2;
        else
            xs = (3*xs) +1;
        currentlen += 1;
        generate_sequence(xs,currentlen,seqlen,seq+1);
    }
    else // this is base condition to stop recursive function
        return;
}
void check_loop_iterative(void (*f)(int,int,int,int*),int xs,int seqlen,int *loop,int*looplen)
{
    int *ls = (int *)malloc(1*sizeof(int));
    int *le = (int *)malloc(1*sizeof(int));
    int *seq = (int *)calloc(seqlen ,sizeof(int));// the sequence is here.
    int temp;
    int result; // it used for to check what has_loop will return
    (*f)(xs,0,seqlen,seq); // calling the generate_sequence function to have numbers.
    if(*looplen == -2) // if looplen -2 it means print it just 1 times. 
    {
        printf("Sequence = {");
        for(int i = 0; i<seqlen; i++)
            printf("%d,",seq[i]);
        printf("\b}\n");
    	*looplen = -1;
        free(ls);
        free(seq);
        free(le);
    check_loop_iterative(f,xs,seqlen,loop,looplen);
    }
    else if (*looplen == -1) // this is for resize to looplen. I used value of looplen to have -2 because i need to print it one one more time then it is -1 then i assigned it again
    {			    	
        *looplen = (int)(seqlen/2);
        free(ls);
        free(seq);
        free(le);
        check_loop_iterative(f,xs,seqlen,loop,looplen);
    }
    else if (*looplen <=1) // IT COUNTS DOWN FROM SEQLEN/2 TO 1. IF IT IS 1 DURING THE COUNTING DOWN IT MEANS THERE IS NO LOOP
    {
        printf("No loop founded\n");
    }
    else
    {
        printf("Checking if there is a loop of length %d\n",*looplen);
        temp = *looplen;
        result = has_loop(seq,seqlen,temp,ls,le);
        if(result == 1) // IT MEANS LOOP IS EXIST
        {
            printf("\n\nLoop detected with a length of %d\n",*looplen);
            printf("The indexes of the loop's first occurance %d (first digit), %d(last digit)\n",*ls,*le);
            for(int i = *ls;i<=*le;i++,loop++)
            {
                loop[0] = seq[i];
            }
        }
        else // if there is not loop.
        {
            *looplen-=1;
            check_loop_iterative(f,xs,seqlen,loop,looplen);
        }
        free(ls);
        free(seq);
        free(le);
    }
}

int has_loop(int *arr, int n, int looplen, int *ls,int *le)
{
    int i;
    int res;
    int flag =0;
    int sabit = 0; // this is almost constans
    int ilerleyen = 0;
    if(looplen <2)
        return 0;
    do
    {
        if(arr[sabit+ilerleyen] == arr[sabit+ilerleyen+looplen])
        {
            ilerleyen++;
            flag++;
        }
        else
        {
        
            sabit++;
            ilerleyen = 0;
            flag =0;
        }
        if(sabit + looplen == n-1)
        {
            return 0;
        }
        if(flag == looplen && flag == ilerleyen && (n == looplen + sabit+ ilerleyen || sabit + looplen+ilerleyen +flag ==n))  // Bitirme şartlarından ilki flag ve looplenin aynı olması.
        {                                                                                                                    // flag ancak aynı olduğu sürece artıyor yoksa sıfırlanıyor.
            *ls = sabit;                                                                                                    // son parantezli şart ise eğer bir döngü varsa ve bu döngü baştan itibaren başlıyor ve sonda bitiyorsa bunu farketmesi için
            *le = sabit+looplen-1;

            return 1;
        }
    } while (ilerleyen+looplen-1 != n || ilerleyen <=looplen);
    if(ilerleyen+looplen-1 == n)
    {
        return 1;
    }
    else
        return 0;
}

void hist_of_firstdigits(void (*f)(int,int,int,int*), int xs, int seqlen, int *h, int digit) // digit start from 1 to 9. It checsk first digits of the number. Start from 1 so it check which is start with 1xx f.e 102,19..
{
    if(digit < 10)
    {
        int *seq = (int *)malloc(seqlen*sizeof(int));
        (*f)(xs,0,seqlen,seq);
        int temp;
        int on_katlari= 10;
        int gecici_on_katlari;
        for(int i = 0;i<seqlen;i++)
        {
                do
                {
                    temp = seq[i];
                    if(temp % on_katlari == temp && temp >= 10)
                    {
                        gecici_on_katlari = on_katlari/10;  // THIS PART IS JUST MATHMATICAL CALCULATIONS. YOU SHOULD HAVE A PENCIL AND PAPER TO UNDERSTAND IT.
                        temp -= (temp % gecici_on_katlari); // THIS PART IS JUST MATHMATICAL CALCULATIONS. YOU SHOULD HAVE A PENCIL AND PAPER TO UNDERSTAND IT.
                        temp /= gecici_on_katlari;          // THIS PART IS JUST MATHMATICAL CALCULATIONS. YOU SHOULD HAVE A PENCIL AND PAPER TO UNDERSTAND IT.
                        if(temp == digit)
                            h[digit-1]++;
                        temp = 0;
                        on_katlari = 10;
                    }
                    else if(temp <10)
                    {
                        if(temp % on_katlari == digit)
                            h[digit-1]++;
                        temp = 0;
                    }
                    else
                    {
                        on_katlari *= 10;
                    }
                } while (temp != 0);
        }
        free(seq);
        hist_of_firstdigits(f,xs,seqlen,h,digit+1);
    }
}

