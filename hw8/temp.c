#include<stdio.h>
#include<stdlib.h>

void generate_sequence(int xs,int currentlen,int seqlen, int *seq);
void check_loop_iterative(void (*f)(int,int,int,int*),int xs,int seqlen,int *loop,int looplen);
int has_loop(int *arr, int n, int looplen, int *ls,int *le);
void hist_of_firstdigits(void (*f)(int,int,int,int*), int xs, int seqlen, int *h, int digit);
int main()
{
    int seqlen;
    int currentlen = 0;
    int xs;
    int looplen = -2;
    int printing_loop = 0;
    printf("Enter the sequence length\n");
    scanf("%d",&seqlen);
    printf("Enter the first element\n");
    scanf("%d",&xs);
    int *h = (int *)calloc(9,sizeof(int));
    int *seq = (int*)calloc(seqlen,sizeof(int));
    int *loop = (int *)calloc((int)(seqlen/2)+1,sizeof(int));
    void (*ptr)(int,int,int,int*) = generate_sequence;
    check_loop_iterative(ptr,xs,seqlen,loop,looplen);
    if(loop[0] !=0)
    {
        printf("Loop: {");
        for(int i = 0;loop[i] != -999;i++)
            printf("%d,",loop[i]);
        printf("\b}\n");
    }
    hist_of_firstdigits(ptr,xs,seqlen,h,1);
    printf("histogram = {");
    for(int i = 0;i<9;i++)
        printf("%d,",h[i]);
    printf("\b}\n\n");
    free(h);
    free(seq);
    free(loop);
}

void generate_sequence(int xs, int currentlen,int seqlen,int *seq)
{
    if(currentlen < seqlen)
    {
       // printf("%d Döndür %d\n",currentlen,xs);
        seq[0] = xs;
        if(xs % 2 == 0)
            xs /= 2;
        else
            xs = (3*xs) +1;
        currentlen += 1;
        generate_sequence(xs,currentlen,seqlen,seq+1);
    }
    else 
        return;
}
void check_loop_iterative(void (*f)(int,int,int,int*),int xs,int seqlen,int *loop,int looplen)
{
    int *ls = (int *)malloc(1*sizeof(int));
    int *le = (int *)malloc(1*sizeof(int));
    int *seq = (int *)calloc(seqlen ,sizeof(int));
    int result;
    (*f)(xs,0,seqlen,seq);
    if(looplen == -2)
    {
        printf("Sequence = {");
        for(int i = 0; i<seqlen; i++)
          printf("%d,",seq[i]);
    printf("\b}\n");
        free(ls);
        free(seq);
        free(le);
    check_loop_iterative(f,xs,seqlen,loop,-1);
    }
    else if (looplen == -1)
    {
        //printf("patladim1");
        free(ls);
        free(seq);
        free(le);
        check_loop_iterative(f,xs,seqlen,loop,(int)(seqlen/2));
    }
    else if (looplen <=1)
    {
        printf("No loop founded\n");
    }
    else
    {
        printf("Checking if there is a loop of length %d\n",looplen);
        result = has_loop(seq,seqlen,looplen--,ls,le);
        //printf("\ntest =%d\n",result);
        if(result == 1)
        {
            printf("\n\nLoop detected with a length of %d\n",looplen+1);
            printf("The indexes of the loop's first occurance %d (first digit), %d(last digit)\n",*ls,*le);
            for(int i = *ls;i<=*le;i++,loop++)
            {
                loop[0] = seq[i];
                //printf("loop[0] = %d ||\n",loop[0]);
            }
            loop[0] = -999;
        }
        else
            check_loop_iterative(f,xs,seqlen,loop,looplen);
        free(ls);
        free(seq);
        free(le);
    }
   // check_loop_iterative(f,xs,seqlen,loop,looplen);
}

int has_loop(int *arr, int n, int looplen, int *ls,int *le)
{
    int i;
    int res;
    int flag =0;
    int sabit = 0;
    int ilerleyen = 0;
    //
    //printf("looplen == %d\n",looplen);
    if(looplen <3)
        return 0;
    do
    {
        if(arr[sabit+ilerleyen] == arr[sabit+ilerleyen+looplen])
        {
            //printf("buradayim [%d %d]--flag %d-- sabit == %d|| ilerleyen = %d || looplen = %d\n",arr[sabit+ilerleyen],arr[sabit+ilerleyen+looplen],flag,sabit,ilerleyen,looplen);
            ilerleyen++;
            flag++;
        }
        else
        {
            //printf("ife giremedim %d -- %d yüzünden||sabit == %d||ilerleyen = %d || flag = %d || looplen = %d\n",arr[sabit+ilerleyen],arr[sabit+ilerleyen+looplen],sabit,ilerleyen,flag,looplen);
            sabit++;
            ilerleyen = 0;
            flag =0;
        }
        if(sabit + looplen == n-1)
        {
            return 0;
        }
        if(flag == looplen && flag == ilerleyen && (n == looplen + sabit+ ilerleyen || sabit + looplen+ilerleyen +flag ==n))
        {
            *ls = sabit;
            *le = sabit+looplen-1;
            //printf("(sabit = %d || deger = %d || ls = %d || le = %d || ilerleyen = %d)\n",sabit,arr[sabit],*ls,*le,ilerleyen);

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

void hist_of_firstdigits(void (*f)(int,int,int,int*), int xs, int seqlen, int *h, int digit)
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
                        //printf("/************************************************************************/\n");
                        //printf("Temp = %d||| seq[i] = %d|| digit = %d || gecici = %d || on katlari = %d\n", temp,seq[i],digit,gecici_on_katlari,on_katlari);
                        gecici_on_katlari = on_katlari/10;
                        temp -= (temp % gecici_on_katlari);
                        //printf("Temp = %d||| seq[i] = %d|| digit = %d || gecici = %d || on katlari = %d\n", temp,seq[i],digit,gecici_on_katlari,on_katlari);
                        //printf("--------------------------------------------------------\n");
                        temp /= gecici_on_katlari;
                        //printf("Temp = %d||| seq[i] = %d|| digit = %d || gecici = %d || on katlari = %d\n", temp,seq[i],digit,gecici_on_katlari,on_katlari);
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
