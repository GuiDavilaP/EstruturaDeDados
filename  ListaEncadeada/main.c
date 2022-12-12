#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lse.h"

// Inicializa(): cria uma lista vazia
TipoPtNo* inicializa(void)
{
    return NULL;
}

// Imprime informações de cada nodo da lista.
void imprime(TipoPtNo* ptLista)
{
    TipoPtNo* ptaux;
    if (ptLista == NULL)
        puts("lista vazia");
    else
        for (ptaux=ptLista; ptaux!=NULL; ptaux=ptaux->prox)
            printf("Titulo = %s Distribuidor = %s Diretor = %s\n",
                   ptaux->info.titulo,
                   ptaux->info.distr,
                   ptaux->info.diretor);
}

// insereInicio(): insere um elemento em uma posição da lista
TipoPtNo* insereInicio (TipoPtNo* ptLista, TipoInfoNo dados)
{
    TipoPtNo *novo;
    novo = (TipoPtNo*) malloc(sizeof(TipoPtNo));
    novo->info = dados;
    novo->prox = ptLista;
    ptLista = novo;
    return novo;
}

// inserFim(): insere um elemento em uma posição da lista
TipoPtNo* insereFim (TipoPtNo* ptLista, TipoInfoNo dados)
{
    TipoPtNo *novo, *ptaux = ptLista;
    novo = (TipoPtNo*) malloc(sizeof(TipoPtNo));
    novo->info = dados;
    novo->prox = NULL;
    if(ptaux)
    {
        for (ptaux=ptLista; ptaux->prox; ptaux=ptaux->prox);
        ptaux->prox = novo;
    }
    else
        ptLista = novo;
    return ptLista;
}

// remove(): remove um elemento na lista
TipoPtNo* remover(TipoPtNo* ptLista, char titulo[])
{
    TipoPtNo *ant = NULL; //ponteiro auxiliar para a posição anterior
    TipoPtNo *ptaux = ptLista; //ponteiro auxiliar para percorrer a lista
    /*procura o elemento na lista*/
    while (ptaux !=NULL && (strcmp(ptaux->info.titulo, titulo)))
    {
        ant = ptaux;
        ptaux = ptaux->prox;
    }
    if (ptaux == NULL) /*verifica se achou*/
        return ptLista; /*retorna a lista original*/
    if (ant == NULL) /*vai remover o primeiro elemento*/
        ptLista = ptaux->prox;
    else /*vai remover do meio ou do final*/
        ant->prox = ptaux->prox;
    free(ptaux); /*libera a memória alocada*/
    return ptLista;
}

//consulta(): consulta um elemento da lista
//lista(): exibe todos os elementos da lista

// destroi(): destrói a lista
TipoPtNo* destroi(TipoPtNo* ptLista)
{
    TipoPtNo *ptaux; //ponteiro auxiliar para percorrer a lista
    while (ptLista != NULL)
    {
        ptaux = ptLista;
        ptLista = ptLista->prox;
        free(ptaux);
    }
    free(ptLista);
    return NULL;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
