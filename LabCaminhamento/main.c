#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

int Repete(TipoFila *visitados, int vertice)
{
    if(visitados != NULL)
    {
        if(visitados->dado == vertice || Repete(visitados->elo, vertice))
            return 1;
    }
    return 0;
}

void auxDFS(int arvore[][8], TipoDFila *fila, TipoDFila *visitados, int vertInicial)
{
    int j = 0;

    for(j = 0; j < 8; j++)
    {
        if(arvore[vertInicial][j] == 1 && !Repete(visitados->prim, j))
        {
            InserirFila(&fila, j);
            InserirFila(&visitados, j);
            printf("%d", j);
            auxDFS(arvore, fila, visitados, j);
        }
    }
}

void DFS(int arvore[][8], TipoDFila *fila, TipoDFila *visitados, int vertInicial)
{
    InserirFila(&fila, vertInicial);
    InserirFila(&visitados, vertInicial);
    printf("%d", vertInicial);
    auxDFS(arvore, fila, visitados, vertInicial);
}

/*
TipoDFila InBFS(int arvore[][8], TipoDFila *fila)
{
    int i, j;
    TipoDFila *visitados;

    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            if(arvore[i][j] != 0 && j);
                InserirFila(arvore[i][j]);
        }
    }
    //OutBfs()
}
*/

int main()
{
    int arvore[8][8] = {};
    TipoDFila *fila, *visitados;

    //int i, j;
    // Reseta
    /*for(i = 0; i < 8; i++)
        for(j = 0; j < 8; j++)
            arvore[i][j] = 0;*/
    // Arvore exemplo.
    arvore[0][1] = 1;
    arvore[0][2] = 1;
    arvore[1][3] = 1;
    arvore[2][3] = 1;
    arvore[2][4] = 1;
    arvore[3][5] = 1;
    arvore[3][7] = 1;
    arvore[3][4] = 1;
    arvore[5][4] = 1;
    arvore[6][1] = 1;
    arvore[7][6] = 1;

    fila = InicializaFila(fila);
    visitados = InicializaFila(visitados);
    DFS(arvore, fila, visitados, 1);
    printf("\n");
    ImprimirFila(fila);

    return 0;
}
