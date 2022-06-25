#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define STACK_BLOCK_SIZE 10

typedef struct{
    int *array;
    int currentsize;
    int maxsize;
}stack;

void push (stack *s, int d); // insert at the top of stack.
int pop(stack *s); // delete from top of the stack.
stack * init_return(void); // initialize stack is done here.
int init(stack *s); // it check if it initialization is successful or not.
int *  grow_array(stack *s,int times); // it grows int array whihch one part of the stack (struct)
//int * shrink_array(stack *s,int times); // the same as grow_array function but it acts oppositely
int main()
{
    int length;
    int i; // this is for counting
    int temp; // this is take a disc from the rod and it contains which disc has.
    int temp2; // this variable has a critical role without this code will stuck in a loop. it helps to remind which disc was moved.
    int flag = 0;
    int flag2= 0;
    int flag3 = 0;
    int control;
    char c;
    stack * rod_1;
    stack *rod_2;
    stack *rod_3;
    rod_1 = init_return(); // initaialization is done here.
    rod_2 = init_return(); // initaialization is done here.
    rod_3 = init_return(); // initaialization is done here.
    do
    {
        printf("Enter tower size = ");
        control = scanf("%d",&length);
        if(control== 0 || length <1)
        {
            printf("invalid input please enter valid number. \n");
            while((c=getchar()) != '\n');
        }
    }while(control == 0 || length <1);
    for(i = 0;i<length;i++)
        push(rod_1,length-i);
    for(i = 0;i <pow(2,(double)length)-1; i++) // this problem is a mathematical problem. If user enter 3 it means that there is a solution with 7 move. if it is 1 it means there is 1 move.
    {
        if(i ==0 )
            temp2=-999;
        flag = 0;
        flag2= 0;
        flag3 = 0;
        temp = 0;
        //for(int j = 0;j<rod_1->currentsize;j++)
        //    printf("j== %d || i == %d||rod1 de bulunanlar = %d || size == %d\n",j,i,rod_1->array[j],rod_1->currentsize);
        if(rod_1->currentsize != 0) // this is from first rod to rod2 to or rod3
        {   
            // in order to understand why there is there is and what is their role let me expain. As i mentioned above this is amathematical problem. After some 
            //calculation parts, i realized that if inout is even and i got the disc 2 and it has to move 2 right. i.e from 1 to 3, i.e from 2 to 1. this is mathematical.
            // if input is even but and i have odd number disc such as 1. 1 has to move 1 right. ie. input 4 and it times for disc 2 to move and it is on first rod. it has to gove one right which is rod2.
            // all i mentioned above are coded just below with if else.
            // temp2 for reminding which disc was moved lastly. Without it there will be loops. 
            temp = pop(rod_1);
            if(temp2 != temp &&length %2 == 1 && ((rod_3->currentsize >0 && temp < rod_3->array[rod_3->currentsize-1]) || (rod_3->currentsize == 0 ))&& temp %2 == 1)
            {
                push(rod_3,temp);
                printf("Move the disk %d from '1' to '3'\n",temp);
                flag=1;
                temp2 = temp;
            }
            else if(temp2 != temp &&length %2 == 1 && ((rod_2->currentsize >0 && temp < rod_2->array[rod_2->currentsize-1]) || (rod_2->currentsize == 0 ))&& temp %2 == 0)
            {
                push(rod_2,temp);
                printf("Move the disk %d from '1' to '2'\n",temp);
                flag=1;
                temp2 = temp;
            }
            else if(temp2 != temp &&length %2 == 0 && ((rod_3->currentsize >0 && temp < rod_3->array[rod_3->currentsize-1]) || (rod_3->currentsize == 0))&& temp %2 == 0)
            {
                push(rod_3,temp);
                printf("Move the disk %d from '1' to '3'\n",temp);
                flag = 1;
                temp2 = temp;
            }
            else if(temp2 != temp &&length %2 == 0 && ((rod_2->currentsize >0 && temp < rod_2->array[rod_2->currentsize-1]) || (rod_2->currentsize == 0 ))&& temp %2 == 1)
            {
                push(rod_2,temp);
                printf("Move the disk %d from '1' to '2'\n",temp);
                flag = 1;
                temp2 = temp;
            }
            else
            { // else part for if it gets from rod 1 but there is no move. then it is pushed back.
                push(rod_1,temp);
                flag =0;
                temp = 0;
                //printf("temp = %d||\n",temp);
            }
        }
        if (rod_2->currentsize != 0)
        {
            temp = pop(rod_2);
            if(temp2 != temp &&length %2 == 1 && ((rod_1->currentsize >0 && temp < rod_1->array[rod_1->currentsize-1]) || (rod_1->currentsize  ==0  ))&& temp %2 == 1)
            {
                push(rod_1,temp);
                printf("Move the disk %d from '2' to '1'\n",temp);
                flag2= 1;
                temp2 = temp;
            }
            else if(temp2 != temp &&length %2 == 1 && ((rod_3->currentsize >0 && temp < rod_3->array[rod_3->currentsize-1]) || (rod_3->currentsize == 0))&& temp %2 == 0)
            {
                push(rod_3,temp);
                printf("Move the disk %d from '2' to '3'\n",temp);
                flag2= 1;
                temp2 = temp;
            }
            else if(temp2 != temp &&length %2 == 0 && ((rod_1->currentsize >0 && temp < rod_1->array[rod_1->currentsize-1]) || (rod_1->currentsize  ==0 ))&& temp %2 == 0)
            {
                push(rod_1,temp);
                printf("Move the disk %d from '2' to '1'\n",temp);
                flag2= 1;
                temp2 = temp;
            }
            else if(temp2 != temp &&length %2 == 0 && ((rod_3->currentsize >0 && temp < rod_3->array[rod_3->currentsize-1]) || (rod_3->currentsize == 0)) && temp %2 == 1)
            {
                push(rod_3,temp);
                printf("Move the disk %d from '2' to '3'\n",temp);
                flag2= 1;
                temp2 = temp;
            }
            else
            {
               // printf("yerleştirilemeyenlerden bir tanesi = %d || rod_3 içi = %d || rod3_eleman =%d || rod1 eleman_Sayisi =%d || rod_1 =%d\n",temp,rod_3->array[rod_3->currentsize-1],rod_3->currentsize,rod_1->currentsize,rod_1->array[rod_1->currentsize-1]);
                push(rod_2,temp);
                flag2= 0;
                temp = 0;
                //printf("i == %d || temp == %d || rod3 == %d || rod1 == %d|| rod2= %d ||rod2-size %d\n"
                //,i,temp,rod_3->array[rod_3->currentsize],rod_1->array[rod_1->currentsize],rod_2->array[rod_2->currentsize-1],rod_2->currentsize);
            }
        }
        if (rod_3->currentsize != 0)
        {   
            temp = pop(rod_3);
            if(temp2 != temp &&length %2 == 1 && ((rod_2->currentsize >0 &&temp < rod_2->array[rod_2->currentsize-1]) || (rod_2->currentsize == 0))&& temp %2 == 1)
            {
                push(rod_2,temp);
                printf("Move the disk %d from '3' to '2'\n",temp);
                flag3 = 1;
                temp2 = temp;
            }
            else if(temp2 != temp &&length %2 == 1 && ((rod_1->currentsize >0 &&temp < rod_1->array[rod_1->currentsize-1]) || (rod_1->currentsize == 0))&& temp %2 == 0)
            {
                push(rod_1,temp);
                printf("Move the disk %d from '3' to '1'\n",temp);
                flag3 = 1;
                temp2 = temp;
            }
            else if(temp2 != temp &&length %2 == 0 && ((rod_2->currentsize >0 && temp < rod_2->array[rod_2->currentsize-1]) || (rod_2->currentsize == 0))&& temp %2 == 0)
            {
                push(rod_2,temp);
                printf("Move the disk %d from '3' to '2'\n",temp);
                flag3 = 1;
                temp2 = temp;
            }
            else if(temp2 != temp &&length %2 == 0 && ((rod_1->currentsize >0 &&temp < rod_1->array[rod_1->currentsize-1]) || (rod_1->currentsize == 0))&& temp %2 == 1)
            {
                push(rod_1,temp);
                printf("Move the disk %d from '3' to '1'\n",temp);
                flag3 = 1;
                temp2 = temp;
            }
            else
            {
                push(rod_3,temp);
                flag3=0;
                //printf("i == %d\n",i);
            }
        }
       // printf("(i == %d || temp = %d || %d %d %d)\n",i,temp,flag,flag2,flag3);

    }
    
}

stack * init_return(void)
{
    int result;
    stack *towers;
    do
    {
        towers = (stack*)malloc(1*sizeof(stack));
        result = init(towers);
    }while(result == 0);
    towers->currentsize =0;
    towers->array = (int *)calloc(STACK_BLOCK_SIZE,sizeof(int));
    towers->maxsize = STACK_BLOCK_SIZE;
    return towers;
}
int init(stack *s)
{
    if(s == NULL)
        return 0;
    return 1;
}

void push(stack *s,int d)
{
    if(s->maxsize == s->currentsize) // this is for if it reachs max. then resize it.
    {
        s->array= grow_array(s,s->currentsize);
        s->maxsize += 10; // resizeing. increased 10
    }
    s->array[s->currentsize] = d;
    //printf("(%d ||| %d|| %d)\n",s->array[s->currentsize],s->currentsize,s->maxsize);
    s->currentsize+= 1;
}
int *  grow_array(stack *s,int times)
{
    int *cp; // this is pointing old s->array position and then it will copy whole digits.
    cp = s->array;
    int i;
    s->array = (int *)calloc(times+STACK_BLOCK_SIZE,sizeof(int));
    free(s->array);
    for(i = 0; i <times+STACK_BLOCK_SIZE;i++)
        s->array[i] = cp[i];
   // s->currentsize = i;
    return s->array;
}
int pop(stack *s)
{
    if(s->currentsize != 0)
    {
        s->currentsize -= 1;
        return s->array[s->currentsize]; // it returns what it deletes.
    }
}