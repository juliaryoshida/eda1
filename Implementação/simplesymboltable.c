#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct{
    int key;
    char value[20];
} Item;

Item table[MAX];
int n = 0;

void put(int key, char *value){    
    if(n>=MAX){
        return;
    }

    for(int i=0; i<n; i++){
        if(strcmp(table[i].value, value)==0){
            table[i].key = key;
            strcpy(table[i].value, value);
            return;
        } 
    }

    strcpy(table[n].value, value);
    table[n].key = key;
    n++;
}

int get(int key){
    for(int i=0; i<n; i++){
        if(table[i].key==key){
            printf("%s\n", table[i].value);
            return i;
        }
    }
    return -1;
}

int main(){
    char word[20];
    int index = 0, searchkey = 0;
    while(scanf("%s", word) == 1){
        put(index, word);
        index++;
    }
    get(searchkey);
    return 0;
}