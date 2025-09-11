#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

/* Inicializa a lista como lista vazia. */
void inicializa_lista(Lista * ap_lista){
    *ap_lista = NULL;
}

/* Insere valor no fim da lista apontada por ap_lista. ap_lista aponta para o inicio da lista. */
void insere_fim(Lista * ap_lista, int valor){
    No * novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    No ** ultimo_no = ap_lista;

    while (*ultimo_no != NULL){
        ultimo_no = &((*ultimo_no)->proximo);
    }
    *ultimo_no = novo_no; 
}

/* Insere valor no inicio da lista apontada por ap_lista. */
void insere_inicio(Lista * ap_lista, int valor){
    No *novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = *ap_lista;
    *ap_lista = novo_no;
}

/* Remove valor do fim da lista apontada por ap_lista e retorna este valor. */
int remove_fim(Lista * ap_lista){
    if (*ap_lista == NULL){
        return -1;
    }
    No ** ultimo_no = ap_lista;
    while((*ultimo_no)->proximo != NULL){
        ultimo_no = &(*ultimo_no)->proximo;
    }
    int retorno;
    retorno = ((*ultimo_no)->valor);
    free(*ultimo_no);
    *ultimo_no = NULL;
    return retorno;
}

/* Imprime a lista na saida padrão, no formato:
   (1,3,2,3,4,2,3,1,4)
   em uma linha separada.
 */
void imprime(Lista lista){
    if(lista==NULL){
        return;
    }
    printf("(");
    while (lista != NULL){
        if (lista->proximo == NULL){
            printf("%d", lista->valor);
        }
        else{
            printf("%d,", lista->valor);
        }
        lista = lista->proximo;
    }
    printf(")");
}


int main  (){
    return 0;
}