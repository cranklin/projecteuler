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
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

/* 1st attempt
unsigned long long int collatz(int target){
    int cont;
    unsigned long long int current, answer;
    cont=1;
    current = 8;
    while(cont && current>1){
        if((current-1)%3 == 0){
            if(((current-1)/3)%2==0){
                current = current * 2;
            }
            else{
                current = (current-1)/3;
                if(current<target){
                    answer = current;
                }
                else{
                    cont = 0;
                }
            }
        }
        else{
            current = current * 2;
        }
        printf("%llu\n",current);
    }
    return answer;
}
*/

struct custom_el{
    unsigned long long int num;
    unsigned long long int count;
    struct custom_el *left;
    struct custom_el *right;
};

typedef struct custom_el tnode;

tnode *root;

tnode *talloc(void){
    return (tnode *) malloc(sizeof(tnode));
}

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

void insert(tnode **tree,tnode *newnode){
    if(!(*tree)) {
        *tree = newnode;
        return;
    }
    if(newnode->num<(*tree)->num){
        insert(&(*tree)->left, newnode);
    }
    else if(newnode->num>(*tree)->num){
        insert(&(*tree)->right, newnode);
    }
    return;
}

unsigned long long int checktree(unsigned long long int num){
    tnode *currentnode;
    currentnode = root;
    while(currentnode->num!=num){
        if(num < currentnode->num){
            if(currentnode->left==NULL){
                /*printf("not found\n");*/
                return -1;
            }
            currentnode=currentnode->left;
        }
        else{
            if(currentnode->right==NULL){
                /*printf("not found\n");*/
                return -1;
            }
            currentnode=currentnode->right;
        }
    }
    /*printf("found\n");*/
    return currentnode->count;
}

unsigned long long int getcount(unsigned long long int num){
    unsigned long long int count=0;
    count=checktree(num);
    if(count==-1){
        count=getcount(getnext(num))+1;
        /*printf("%d\n",count);*/
        tnode *newnode;
        newnode = talloc();
        newnode->num = num;
        newnode->count = count;
        newnode->left = NULL;
        newnode->right = NULL;
        insert(&root,newnode);
    }
    /*printf("%d\n",count);*/
    return count;
}

void printout(tnode **tree){
    if((*tree)->left) printout(&(*tree)->left);
    printf("%d\n%d\n\n",(*tree)->num,(*tree)->count);
    if((*tree)->right) printout(&(*tree)->right);
}

int collatz2(int target){
    int i,ans;
    unsigned long long int count=0;
    unsigned long long int max=0;

    tnode *curr;
    root = talloc();
    curr = talloc();
    curr->num=2;
    curr->count=1;
    curr->left=NULL;
    curr->right=NULL;
    insert(&root,curr);
    for(i=2;i<target;i++){
        count = getcount(i);
        /*printf("%d\n",count);*/
        if(count>max){
            max = count;
            ans = i;
        }
    }
    return ans;
}

int main (int argc, char *argv[]){
    if(argc == 2){
        int argi = atoi(argv[1]);
        /*printout(&root);*/
        printf("\n%d\n", collatz2(argi));
        return 0;
    }
    else{
        printf("\nUsage: collatz <integer>\n");
        return 1;
    }
}
