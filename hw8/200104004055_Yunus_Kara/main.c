#include<stdio.h>
#include<stdlib.h>
#include "util.h"

int main()
{
    int seqlen;
    int currentlen = 0;
    int xs;
    int start_point;
    int *looplen = &start_point;
    *looplen = -2;
    int printing_loop = 0;
    printf("Enter the sequence length\n");
    scanf("%d",&seqlen);
    printf("Enter the first element\n");
    scanf("%d",&xs);
    int *h = (int *)calloc(9,sizeof(int)); // there 9 nine digit
    int *seq = (int*)calloc(seqlen,sizeof(int)); // it needs to have seqlen times int bytes.
    int *loop = (int *)calloc((int)(seqlen/2)+1,sizeof(int));	// it's max value is (seqlen/2)+1 so it is allocate.
    void (*ptr)(int,int,int,int*) = generate_sequence;
    check_loop_iterative(ptr,xs,seqlen,loop,looplen);
    if(*looplen >1) // looplen counting down so after all the complation if it is grater than 1 there is a loop then it will be printed.
    {
        printf("Loop: {");
        for(int i = 0;i<*looplen;i++)
            printf("%d,",loop[i]);
        printf("\b}\n");
    }
    //printf("looplen = %d",*looplen); 
    hist_of_firstdigits(ptr,xs,seqlen,h,1);
    printf("histogram = {");
    for(int i = 0;i<9;i++)
        printf("%d,",h[i]);
    printf("\b}\n\n");
    //free(looplen);
    free(h); // the allocated area is free right now.
    free(seq);// the allocated area is free right now.
    free(loop);// the allocated area is free right now.
}


