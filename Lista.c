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
    No *novo_no = (No*)malloc(sizeof(No));
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

/* Retorna o valor do i-ésimo elemento da lista, caso ele exista. 
Retorna -1 caso contrário. As posições são contadas a partir de 1, sendo 1 a primeira posição. */
int recupera_i_esimo(Lista lista, int i);

/* Retorna o tamanho da lista. */
int tamanho(Lista lista);

/* Remove todas as ocorrências de valor da lista apontada por ap_lista. 
 * Retorna o numero de ocorrências removidas.
 */
int remove_ocorrencias(Lista *ap_lista, int valor);

/* Busca elemento valor na lista. 
   Retorna a posição na lista, começando de 1=primeira posição.
   Retorna -1 caso não encontrado.
*/
int busca(Lista lista, int valor);

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

/* Desaloca toda a memória alocada da lista.
 */
void desaloca_lista(Lista *ap_lista);

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

    remove_i_esimo(&L, 3);

    printf("\n");
    imprime(L);
    return 0;
}