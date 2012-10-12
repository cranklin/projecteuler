/*
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
 * If d(a) = b and d(b) = a, where a \u2260 b, then a and b are an amicable pair and each of a and b are called amicable numbers.
 *
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
 *
 * Evaluate the sum of all the amicable numbers under 10000.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int sumofdividends(int num){
    int limit,sum,j;
    limit = num/2;
    sum = 1;
    printf("\n%d : ",num);
    for(j=2;j<=limit;j++){
        if(num%j==0){
            printf("%d,%d,",j,num/j);
            sum+=j;
            if(j!=num/j){
                sum+=num/j;
            }
            limit=(num/j)-1;
        }
    }
    printf(" = %d\n\n",sum);
    return sum;
}

int amicable(int target){
    int myarray[target+1];
    int temp,temp2;
    int i;
    int answer = 0;
    for(i=0;i<target+1;i++){
        myarray[i]=0;
    }

    for(i=4;i<=target;i++){
        if(myarray[i]!=1){
            temp = sumofdividends(i);
            if(temp!=i && temp > 2){
                temp2 = sumofdividends(temp);
                if(temp2 == i){
                    myarray[i]=1;
                    myarray[temp]=1;
                }
            }
        }
    }

    for(i=1;i<=target;i++){
        if(myarray[i]==1){
            printf("\n%d",i);
            answer+=i;
        }
    }
    return answer;
}

int main (int argc, char *argv[]){
    if(argc == 2){
        int argi = atoi(argv[1]);
        printf("\n%d\n", amicable(argi));
        return 0;
    }
    else{
        printf("\nUsage: amicable <integer>\n");
        return 1;
    }
}
