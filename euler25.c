/*
 * The Fibonacci sequence is defined by the recurrence relation:
 *
 *     F_(n) = F_(n\u22121) + F_(n\u22122), where F_(1) = 1 and F_(2) = 1.
 *
 *     Hence the first 12 terms will be:
 *
 *         F_(1) = 1
 *             F_(2) = 1
 *                 F_(3) = 2
 *                     F_(4) = 3
 *                         F_(5) = 5
 *                             F_(6) = 8
 *                                 F_(7) = 13
 *                                     F_(8) = 21
 *                                         F_(9) = 34
 *                                             F_(10) = 55
 *                                                 F_(11) = 89
 *                                                     F_(12) = 144
 *
 *                                                     The 12th term, F_(12), is the first term to contain three digits.
 *
 *                                                     What is the first term in the Fibonacci sequence to contain 1000 digits?
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int fib(int n){
    int x[2000],y[2000];
    int digits,carry,expanded,temp,i,term;
    expanded = 0;
    carry = 0;
    digits = 1;
    x[0] = 0;
    y[0] = 1;
    term = 1;
    while(digits<n){
        term++;
        for(i=0;i<digits;i++){
            temp = x[i] + y[i];
            if(i>0){
                temp += carry;
            }
            carry = 0;
            if(temp>9){
                carry = temp / 10;
                temp = temp % 10;
                if(i==digits-1){
                    expanded = 1;
                }
            }
            x[i] = y[i];
            y[i] = temp;
        }
        if(expanded){
            /*printf("cha");*/
            digits++;
            y[digits-1] = carry;
            expanded = 0;
        }
    }
    for(i=digits-1;i>=0;i--){
        printf("%d",y[i]);
    }
    return term;
}

int main (int argc, char *argv[]){
    if(argc == 2){
        int argi = atoi(argv[1]);
        printf("\n%d\n", fib(argi));
        return 0;
    }
    else{
        printf("\nUsage: fib <integer>\n");
        return 1;
    }
}
