#include <stdio.h>
#include <stdlib.h>

int main(){    
    int *a, *dia=NULL;
    int r, totaldias=0;
    while(scanf("%d",&r)==1){
        a = malloc(2*r*sizeof(int));
        for(int cont=0; cont<(2*r); cont++){
            scanf("%d", &a[cont]);
        }
        int b=-1, n=0;
        for(int c=1; c<(2*r); c=c+2){
            if(b<a[c]){
                b=a[c];            
                n=a[c-1];
            }
            if(b==a[c]){
                if(n>a[c-1]){          
                    n=a[c-1]; 
                }
            }
        }
        dia = realloc(dia, (totaldias + 1)*sizeof(int));
        dia[totaldias]=n;
        totaldias++;
        free(a);
    }
    for(int i=0; i<totaldias; i++){
        printf("Dia %d\n%d\n\n", (i+1), dia[i]);
    }
}