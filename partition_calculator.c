#include <errno.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>
// p1 = 1
// p2 = 1+p1
// p3 = 1+p2
// p4 = 1+p3+p2-p1
// p5 = 1+p4+p3-p2
// p6 = 1+p5+p4-p3+p3-p2
#define MAX_PARTITIONS 31
struct st_q
{
    int *data;
    int front;
    int rear;

};

void init_queue(struct st_q *q, int size)
{
    q->data = (int *)malloc(size * sizeof(int));
    q->front = 0;
    q->rear = 0;
}

void enqueue(struct st_q *q, int value)
{
    q->data[q->rear++] = value;
}

void print_queue(struct st_q *q)
{
    for (int i = q->front; i < q->rear; i++)
    {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int abs(int x){
    if(x >=0 ){
        return x;
    }
    return -x;
}


void level_traveler(int n, int level){

    if (n>0)
    {

        printf("Entering Level: %d\n", level+1);

        for(int i = 0; i < n; i++)
        {
            printf("Level %d branch %d deployed\n", level+1, i);
            level_traveler(i, level+1);
        }
    }
    printf("Level %d branch %d completed\n", level, n);
    
}

int level_traveler_adder(int n, int level){

    int sum = 0;
    if (n>0)
    {

        printf("Entering Level: %d\n", level+1);

        for(int i = 0; i < n; i++)
        {
            printf("Level %d branch %d deployed\n", level+1, i);
            sum = sum + level_traveler_adder(i, level+1);
        }
    }
    else
    {
        printf("Level %d branch %d completed\n", level, n);
        return 1;
    }
    printf("Level %d branch %d completed\n", level, n);
    return sum;
    
}

void level_traveler_printer(int n, int level, struct st_q* s, int t){

    if(t-n>=1){
        int sign  = (level%2==0)?-1:1;
        enqueue(s, sign*t);
        
        if (n>0)
        {

            printf("Entering Level: %d\n", level+1);

            for(int i = 0; i < n; i++)
            {
                
                printf("Level %d branch %d deployed\n", level+1, i);
                level_traveler_printer(i, level+1, s, t-i-1);
            }
        }
    }
    printf("Level %d branch %d completed\n", level, n);
    
}

int partition_calculator(int num ){

    int *P = (int*)malloc(sizeof(int) * (num));
    P[1-1] = 1;
    struct st_q s;
    int temp = 0;
    int sign = 0;
    for(int i = 1; i < num; i++){
        
        init_queue(&s, 1<<i);
        level_traveler_printer((i+2)/2, 0, &s, i+1);
        for(int j = 1; j < s.rear; j++){
            temp = s.data[j];
            printf("temp = %d\n", temp);
            sign = (temp>0)?1:-1;
            P[i] = P[i] + sign * P[abs(temp)-1];
        }
        P[i] = P[i] + 1;
        free(s.data);
        printf("ran the loop for %d and P %d = %d\n", i,i+1, P[i]);
        




    }
    int temp2 = P[num-1];
    free(P);
    
    return temp2;

}


int main(void)
{

    int k = 0;
    while(k<1){
        printf("Enter number: ");
        scanf("%d", &k);
    }
    // struct st_q s;
    // init_queue(&s, 2^(k-1));
    // level_traveler_printer((k+1)/2, 0, &s, k);
    // print_queue(&s);


    printf("The number of partitions of %d is: %d\n", k, partition_calculator(k));
    // printf("Enter the value of n: ");
    // int n;
    // scanf("%d", &n);
    // int** k  = (int** )malloc(sizeof(int*) * n);
    // int* l = (int* )malloc(sizeof(int) * n);
    // for(int i = 0; i < (n+1)/2; i++)
    // {
    //     k[i] = &l[i];
    //     k[n-i-1] = &l[i];
    // }
    // for(int i = 0; i < n; i++)
    // {
    //     l[i] = i+1;
    // }
    // for(int i = 0; i < (n+1)/2; i++)
    // {
    //     *k[i] = i;
    // }
    // for(int i = 0; i < n; i++)
    // {
    //     printf("%d ", *k[i]);
    // }
    // printf("\n");
    // int n;
    // printf("Enter the value of n: ");
    // scanf("%d", &n);
    // int** k = (int** )malloc(sizeof(int*) * n);
    // for(int i = 0; i < n; i++)
    // {
    //     k[i] = (int*)malloc(sizeof(int) * ((i+3)/2));
    // }
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < ((i+3)/2); j++)
    //     {
    //         k[i][j] = j+1;
    //     }
    // }

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < ((i+3)/2); j++)
    //     {
    //         printf("%d ", k[i][j]);
    //     }
    //     printf("\n");
    // }
    // // Free the allocated memory
    // for(int i = 0; i < n; i++)
    // {
    //     free(k[i]);
    // }
    // free(k);

    // int *k = (int*)malloc(sizeof(int) * 10);
    // int *p1 =&k[0];
    // int *p2 =&k[9];
    // p1 = p2;
    // k[0] = 1;
    // printf("%d\n", k[9]);
    // free(k);








    return 0;
}