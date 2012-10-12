/*
 * The following iterative sequence is defined for the set of positive integers:
 *
 * n \u2192 n/2 (n is even)
 * n \u2192 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following sequence:
 * 13 \u2192 40 \u2192 20 \u2192 10 \u2192 5 \u2192 16 \u2192 8 \u2192 4 \u2192 2 \u2192 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int *cache;
/*int cache[1000000];*/

unsigned long long int getnext(unsigned long long int num){
    unsigned long long int next;
    if(num%2==0){
        next=num/2;
    }
    else{
        next=(num*3)+1;
    }
    return next;
}

int checktree(unsigned long long int num){
    if(!cache[num]){
        /*printf("not found\n");*/
        return -1;
    }
    /*printf("found\n");*/
    return cache[num];
}

int getcount(unsigned long long int num){
    int count=0;
    count=checktree(num);
    if(count==-1){
        count=getcount(getnext(num))+1;
        /*printf("%d:%d\n",num,count);*/
        cache[num]=count;
    }
    /*printf("%d:%d\n",num,count);*/
    return count;
}

int collatz2(int target){
    int i,ans,count;
    int max=0;
    unsigned long long int memsize=1999999999999999999;
    cache = (int *) malloc(memsize*sizeof(int));

    cache[2]=1;
    for(i=2;i<target;i++){
        count = getcount(i);
        /*printf("%d\n",count);*/
        if(count>max){
            max = count;
            ans = i;
        }
    }
    /*for(i=0;i<target;i++){
        printf("%d\n",cache[i]);
    }*/
    return ans;
}

int main (int argc, char *argv[]){
    if(argc == 2){
        int argi = atoi(argv[1]);

        printf("\n%d\n", collatz2(argi));
        return 0;
    }
    else{
        printf("\nUsage: collatz <integer>\n");
        return 1;
    }
}
