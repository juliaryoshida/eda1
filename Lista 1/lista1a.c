#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;   
}
