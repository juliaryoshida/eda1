#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char texto[101];
    struct No *prox;
} No;

void push(No **topo, char *str){
    No *novo = (No*)malloc(sizeof(No)); //No* faz o type cast do que o malloc retorna(void*) para No*
    strcpy(novo->texto, str);
    novo->prox= *topo;
    *topo = novo;
}

char* pop(No **topo){
    if(*topo==NULL){
        return NULL;
    }
    No *temp=*topo;
    *topo=temp->prox;
    char *textoDesfeito = malloc(strlen(temp->texto)+1);
    strcpy(textoDesfeito, temp->texto);
    free(temp);
    return textoDesfeito;
} 

int main(){
    No *topo = NULL;
    char comando[200];
    char *resultados[1000];
    int cont=0;
    while(fgets(comando, sizeof(comando),stdin)!=NULL){
        comando[strcspn(comando, "\n")] = '\0';
        if(strncmp(comando, "inserir ", 8) == 0){
            push(&topo, comando + 8);
        } else if(strcmp(comando, "desfazer") == 0) {
            char *textoDesfeito = pop(&topo);
            if(textoDesfeito == NULL){
                resultados[cont] = strdup("NULL");
            } else{
                resultados[cont]=textoDesfeito;
            }
            cont++;
        }
    }

    for(int i=0; i<cont; i++){
        printf("%s\n", resultados[i]);
    }

    while (topo != NULL) {
        No *temp = topo;
        topo = topo->prox;
        free(temp);
    } 

    return 0;
}