#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void inicializa_lista(Lista * ap_lista){
    *ap_lista = NULL;
}

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

void insere_inicio(Lista * ap_lista, int valor){
    Lista novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = *ap_lista;
    *ap_lista = novo_no;
}

int remove_fim(Lista * ap_lista){
    if (*ap_lista == NULL){
        return -1;
    }
    No ** ultimo_no = ap_lista;
    while((*ultimo_no)->proximo != NULL){
        ultimo_no = &(*ultimo_no)->proximo;
    }
    int val_rem;
    val_rem = ((*ultimo_no)->valor);
    free(*ultimo_no);
    *ultimo_no = NULL;
    return val_rem;
}

int remove_inicio(Lista * ap_lista){
    if (*ap_lista == NULL){
        return -1;
    }
    No *no_rem;
    int val_rem;
    no_rem = *ap_lista;
    val_rem = no_rem->valor;
    *ap_lista = no_rem->proximo;
    free (no_rem);
    return val_rem;
}

bool remove_i_esimo(Lista * ap_lista, int i){
    if (*ap_lista == NULL){
        return false;
    }
    if (i == 1){
        remove_inicio(ap_lista);
        return true;
    }

    int contador = 2;
    Lista ap_aux = *ap_lista, ap_aux_prox = ap_aux->proximo;
    while (ap_aux_prox != NULL)
    {
        if (contador == i){
            ap_aux->proximo = ap_aux_prox->proximo;
            free(ap_aux_prox);
            return true;
        }
        ap_aux_prox = ap_aux_prox->proximo;
        ap_aux = ap_aux->proximo;
        contador ++;
    }
    return false;
}

int recupera_i_esimo(Lista lista, int i){
    int count=1;
    while (lista != NULL)
    {   
        if(count == i){
            return lista->valor;
        }
        lista = lista->proximo;
        count ++;
    }
    return -1;
}

int tamanho(Lista lista){
    int tam = 0;
    while (lista != NULL)
    {
        lista = lista->proximo;
        tam++;
    }
    return tam;
     
}

/* Remove todas as ocorrências de valor da lista apontada por ap_lista. 
 * Retorna o numero de ocorrências removidas.
 */
int remove_ocorrencias(Lista *ap_lista, int valor);

int busca(Lista lista, int valor){
    int count = 1;
    while (lista != NULL)
    {
        if(lista->valor == valor){
            return count;
        }
        lista = lista->proximo;
        count++;
    }
    return -1;
    
}

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

void desaloca_lista(Lista *ap_lista){
    Lista no_atual = *ap_lista;
    while (no_atual->proximo != NULL)
    {   
        Lista no_prox = no_atual->proximo;
        free (no_atual);
        no_atual = no_prox;
    }
    free(no_atual);
    *ap_lista = NULL;
    return;
}

int main  (){
    Lista L;
    inicializa_lista(&L);

    insere_fim(&L,2);
    insere_fim(&L,3);
    insere_fim(&L,4);
    insere_fim(&L,5);
    insere_fim(&L,6);
    insere_inicio(&L,1);
    imprime(L);

    //remove_i_esimo(&L, 3);
    
    /*printf("\nrecupera i_esimo: %d", recupera_i_esimo(L,5));
    printf("\nBusca:%d", busca(L,5));
    printf("\nTamanho:%d", tamanho(L));*/
    desaloca_lista(&L);
    printf("\n");
    imprime(L);
    return 0;
}