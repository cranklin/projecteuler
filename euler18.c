/*
 * By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
 *
 * 3
 * 7 5
 * 2 4 6
 * 8 5 9 3
 *
 * That is, 3 + 7 + 4 + 9 = 23.
 *
 * Find the maximum total from top to bottom of the triangle below:
 *
 * 75
 * 95 64
 * 17 47 82
 * 18 35 87 10
 * 20 04 82 47 65
 * 19 01 23 75 03 34
 * 88 02 77 73 07 63 67
 * 99 65 04 28 06 16 70 92
 * 41 41 26 56 83 40 80 70 33
 * 41 48 72 33 47 32 37 16 94 29
 * 53 71 44 65 25 43 91 52 97 51 14
 * 70 11 33 28 77 73 17 78 39 68 17 57
 * 91 71 52 38 17 14 91 43 58 50 27 29 48
 * 63 66 04 68 89 53 67 30 73 16 69 87 40 31
 * 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
 *
 * NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

struct element{
    int num;
    int rank;
    int diff;
};

typedef struct element node;

int mapping(int target){

    int i,j,k;
    int answer = 0;
    int rows = target;
    int max = 0;

    node tree[rows][rows];

    FILE *fp;
    if((fp=fopen("euler18.txt","r"))==NULL){
    /*if((fp=fopen("euler18sample.txt","r"))==NULL){*/
        printf("\nError opening file\n");
        return 1;
    }
    else{
        int row=0;
        while(feof(fp)==0 && row<rows){
            for(i=0;i<=row;i++){
                fscanf(fp,"%2d",&tree[row][i].num);
                tree[row][i].rank=0;
                printf("%2d ",tree[row][i].num);
            }
            row++;
            printf("\n");
        }
        fclose(fp);
    }

    /*find ranks and diffs*/
    int tempnum,tempkey,tempmax;

    for(i=0;i<rows;i++){
        for(j=0;j<=i;j++){
            tempnum = 0;
            for(k=0;k<=i;k++){
                if(tree[i][k].num > tempnum && tree[i][k].rank==0){
                    tempnum = tree[i][k].num;
                    tempkey = k;
                }
            }
            tree[i][tempkey].rank = j+1;
            if(j==0){
                tree[i][tempkey].diff=0;
                tempmax = tree[i][tempkey].num;
                /*printf("\n%d",tempmax);*/
                max+=tempmax;
            }
            else{
                tree[i][tempkey].diff = tempmax-tree[i][tempkey].num;
            }
        }
    }

    /*dump max*/
    printf("\n");
    for(i=0;i<rows;i++){
        for(j=0;j<=i;j++){
            if(tree[i][j].diff==0){
                printf("%c[1m",27);  /*- turn on bold */
                printf("%2d ",tree[i][j].num);
                printf("%c[0m",27); /* turn off bold */
            }
            else{
                printf("%2d ",tree[i][j].num);
            }
        }
        printf("\n");
    }

    /*dump ranks*/
    /*printf("\n");
    for(i=0;i<rows;i++){
        for(j=0;j<=i;j++){
            printf("%2d ",tree[i][j].rank);
        }
        printf("\n");
    }*/

    /*dump diffs*/
    printf("\n");
    for(i=0;i<rows;i++){
        for(j=0;j<=i;j++){
            if(tree[i][j].diff==0){
                printf("%c[1m",27);  /* turn on bold */
                printf("%2d ",tree[i][j].diff);
                printf("%c[0m",27); /* turn off bold */
            }
            else{
                printf("%2d ",tree[i][j].diff);
            }
        }
        printf("\n");
    }

    /* method 1 */
    /*int currentrow=0;
    int currentcol=0;
    int optimalcol;
    int maxsegment = 3;
    int trianglesegment[];
    int counter = 0;
    while(currentrow<rows-1){
        if((rows-1)-currentrow > maxsegment){
            segment=maxsegment;
        }
        else{
            segment=(rows-1)-currentrow;
        }
        for(i=0;i<segment;i++){
            for(j=0;j<=i;j++;){
                trianglesegment[counter]=tree[currentrow+i][currentcol+j].num;
                counter++;
            }
        }
        counter=0;
        currentrow+=(segment-1);
    }*/

    /* method 2 */
    int temparray[rows];
    /*answer = test(tree,temparray,rows);*/

    /*answer=max-31-15-71-62-6-33-16-5;*/ /*1074*/
    /*answer=max;*/
    return answer;
}

int main (int argc, char *argv[]){
    if(argc == 2){
        int argi = atoi(argv[1]);
        printf("\n%d\n", mapping(argi));
        return 0;
    }
    else{
        printf("\nUsage: mapping <integer>\n");
        return 1;
    }
}
