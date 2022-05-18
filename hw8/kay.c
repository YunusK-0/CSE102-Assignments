#include<stdio.h>
#include<stdlib.h>

void generate_sequence(int xs,int currentlen,int seqlen, int *seq);
void check_loop_iterative(void (*f)(int,int,int,int*),int xs,int seqlen,int *loop,int looplen);
int has_loop(int *arr, int n, int looplen, int *ls,int *le);
int main()
{
    int seqlen;
    int currentlen = 0;
    int xs;
    int looplen = -1;
    int printing_loop = 0;
    int *seq = (int*)calloc(100,sizeof(int));
    void (*ptr)(int,int,int,int*) = generate_sequence;
    printf("Enter the sequence length\n");
    scanf("%d",&seqlen);
    printf("Enter the first element\n");
    scanf("%d",&xs);
    check_loop_iterative(ptr,xs,seqlen,seq,looplen);
    if(seq[98] !=0)
    {
        printing_loop= seq[98];
        printf("Loop: {");
        for(int i = 0;i<seq[99]-seq[98]+1;i++,printing_loop++)
            printf("%d,",seq[printing_loop]);
        printf("}\n");
    }
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
}
void check_loop_iterative(void (*f)(int,int,int,int*),int xs,int seqlen,int *loop,int looplen)
{
    int *ls = (int *)malloc(1*sizeof(int));
    int *le = (int *)malloc(1*sizeof(int));
    int result;
    (*f)(xs,0,seqlen,loop);
    if(looplen == -1)
    {
        for(int i = 0; i<seqlen; i++)
          printf("%d-",loop[i]);
    printf("\n");
    check_loop_iterative(f,xs,seqlen,loop,0);
    }
    else if (looplen == 0)
    {
        check_loop_iterative(f,xs,seqlen,loop,(int)(seqlen/2));
    }
    else if (looplen <=1)
    {
        printf("No loop founded\n");
    }
    else
    {
        printf("Checking if there is a loop of length %d\n",looplen);
        result = has_loop(loop,seqlen,looplen--,ls,le);
        //printf("\ntest =%d\n",result);
        if(result == 1)
        {
            printf("\n\nLoop detected with a length of %d\n",looplen+1);
            printf("The indexes of the loop's first occurance %d (first digit), %d(last digit)\n",*ls,*le);
            loop[98] = *ls;
            loop[99] = *le;
        }
        else
            check_loop_iterative(f,xs,seqlen,loop,looplen);
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
    do
    {
        if(arr[ilerleyen] == arr[ilerleyen+looplen])
        {
            ilerleyen++;
            flag++;
            //printf("buradayim [%d %d]--flag %d--\n",arr[ilerleyen],arr[ilerleyen+looplen],flag);
        }
        else
        {
           // printf("ife giremedim %d -- %d yüzünden\n",arr[ilerleyen],arr[ilerleyen+looplen]);
            sabit++;
            ilerleyen = sabit;
            flag =0;
        }
        if(sabit + looplen == n-1)
        {
            return 0;
        }
        if(flag == looplen)
        {
            *ls = ilerleyen-flag;
            *le = ilerleyen+looplen-flag-1;
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

//void hist_of_firstdigits(void (*f), int xs, int seqlen, int *h, int digit)