#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void trim(char name[], int size){
    int len = strlen(name);
    if(len > 0 && name[len - 1] == '\n'){
        name[len - 1] = '\0';
    }
    
}

int main(){

int num = 2;


printf("You have 2 box to store number?\n");
int *m = malloc(num*sizeof(int));

if( m == NULL){
    printf("Couldn't Allocate Space here ");
    return 1;
}

printf("\nGive 2 numbers here: \n");

for(int i = 0; i < num ; i++){
    printf("Element #%d: ",i+1);
    scanf("%d",(m + i));
    
}

printf("<<=============================================>>>\n\n\n");
printf("realloc part\n\n");

char opt[10];

getchar(); // to get rid from left-over spaces
//which comes when you use scanf then fgets
//Thats why if you use scanf only it doesn't happen or if you use fgets only problem wont exist


    printf("Do you want to put more values? say \"yes\" or no\n\n");
    fgets(opt,sizeof(opt),stdin);
    trim(opt,sizeof(opt));
    
    
    if(strcmp(opt,"yes") == 0){
        printf("ok reallocating memory\n\n");
    }else{
        printf("ok terminating program\n");
        return 1;
    }
    
    m = (int *)realloc(m,(2+num)*sizeof(int));
    if( m == NULL){
        printf("Couldn't reallocate mmeory");
        return 1;
    }
    
    printf("ok give 2 number more\n\n");
    for(int i = 2; i < 2 + num ; i++){
    printf("Element #%d: ",i+3);
    scanf("%d",(m + i));
}
printf("Numbers stored are: ");
    for(int i = 0; i < 2 + num ; i++){
    printf("%d ",*(m + i));
    
}



free(m);    
    
    
    return 0;
}
