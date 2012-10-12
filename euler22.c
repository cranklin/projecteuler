/*
 * Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
 *
 * For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 ×53 = 49714.
 *
 * What is the total of all the name scores in the file?
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>

#define LINES 5163

struct element{
    char name[20];
    int value;
    int score;
};

typedef struct element node;

node namearray[LINES];

int names(int target){

    int i,j,k;
    unsigned int answer = 0;
    int tempint;
    char temp[20];

    FILE *fp;
    if((fp=fopen("euler22.txt","r"))==NULL){
        printf("\nError opening file\n");
        return 1;
    }
    else{
        int row = 0;
        while(feof(fp)==0){
            fscanf(fp,"%s",&namearray[row].name);
            namearray[row].value=0;
            for(i=0;namearray[row].name[i]!='\0';i++){
                namearray[row].value += namearray[row].name[i]-64;
            }
            row++;
        }
        fclose(fp);
    }

    /*for(i=0;i<LINES;i++){
        for(j=0;namearray[i].name[j]!='\0';j++){
            
        }
    }*/
    for(i=0;i<LINES;i++){
        for(j=0;j<LINES-1;j++){
            k=0;
            while(namearray[j].name[k]==namearray[j+1].name[k]){
                k++;
            }
            if((namearray[j].name[k] > namearray[j+1].name[k]) || (namearray[j+1].name[k] == '\0')){
                strcpy(temp,namearray[j].name);
                strcpy(namearray[j].name,namearray[j+1].name);
                strcpy(namearray[j+1].name,temp);
                tempint = namearray[j].value;
                namearray[j].value = namearray[j+1].value;
                namearray[j+1].value = tempint;
            }
        }
    }

    for(i=0;i<LINES;i++){
        /*printf("%s : %d\n",namearray[i].name,namearray[i].value);*/
        answer += namearray[i].value * (i+1);
    }

    /*printf("\n%s\n",namearray[target].name);*/

    return answer;
}

int main (int argc, char *argv[]){
    if(argc == 2){
        int argi = atoi(argv[1]);
        printf("\n%d\n", names(argi));
        return 0;
    }
    else{
        printf("\nUsage: names <integer>\n");
        return 1;
    }
}
