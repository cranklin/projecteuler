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
 * Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.
 *
 * NOTE: This is a much more difficult version of Problem 18. It is not possible to try every route to solve this problem, as there are 2^(99) altogether! If you could check one trillion (10^(12)) routes every second it would take over twenty billion years to check them all. There is an efficient algorithm to solve it. ;o)
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

int temparray2[100];

void accumulate(int * array1, int * array2, int rows){
    int i;
    int temp;
    int temparray3[rows+1];
    temparray3[0] = array1[0] + array2[0];
    for(i=0;i<rows;i++){
        if(i==rows-1){
            temparray3[i+1] = array1[i] + array2[i+1];
            /*printf("*\n%d %d",temparray3[i+1],i+1);*/
        }
        else{
            temparray3[i+1] = (array1[i] >= array1[i+1])?array1[i] + array2[i+1]:array1[i+1] + array2[i+1];
        }
    }
    for(i=0;i<=rows;i++){
        temparray2[i]=temparray3[i];
    }
    return;
}

int mapping(int target){

    int i,j,k;
    int answer = 0;
    int rows = target;
    int max = 0;

    node tree[rows][rows];

    FILE *fp;
    if((fp=fopen("euler67.txt","r"))==NULL){
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
                /*printf("%2d ",tree[row][i].num);*/
            }
            row++;
            /*printf("\n");*/
        }
        fclose(fp);
    }

    /*find ranks and diffs*/
    int tempnum,tempkey,tempmax;
    int temparray[rows];

    temparray2[0]=tree[0][0].num;
    for(i=1;i<rows;i++){
        for(j=0;j<=i;j++){
            temparray[j]=tree[i][j].num;
        }
        accumulate(temparray2,temparray,i);
    }

    answer = 0;
    for(i=0;i<rows;i++){
        if(temparray2[i]>answer){
            answer = temparray2[i];
        }
    }

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
