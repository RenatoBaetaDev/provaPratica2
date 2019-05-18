#include <stdio.h>
#include <stdlib.h>
#include "lista_adj.h"


grafo_t *criaGRAFO(int n)
{
    int i;
    grafo_t *grafo = (grafo_t*) malloc (sizeof(grafo_t));
    if (!grafo){
        printf("[ERRO FATAL]: Incapaz de Alocar Memoria para o Grafo \n Saindo.. \n");
        exit(EXIT_FAILURE);
    }

    grafo->num_vertices = n;
    grafo->VETOR_list_adj = (no_t*) malloc (n * sizeof(no_t));
    if (!grafo->VETOR_list_adj){
        printf("[ERRO FATAL]: Incapaz de Alocar Memoria para o Vetor de Lista Adjacente \n Saindo.. \n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < n; i++)
        grafo->VETOR_list_adj[i].prox = NULL;
    
    return grafo;
}


no_t *criaNO(int v)
{
    no_t *novoNO = (no_t*) malloc (sizeof(no_t));
    if (!novoNO){
        printf("[ERRO FATAL]: Incapaz de Alocar Memoria para um Novo No \n Saindo.. \n");
        exit(EXIT_FAILURE);        
    }

    novoNO->vertice = v;
    novoNO->prox = NULL;
    return novoNO;
}


void addAresta(grafo_t *grafo, int origem, int dest)
{
    no_t *novoNO = criaNO(dest);
    novoNO->prox = grafo->VETOR_list_adj[origem].prox;
    grafo->VETOR_list_adj[origem].prox = novoNO;
}


void mostraGrafo(grafo_t *grafo)
{
    int i;
    for (i = 0; i < grafo->num_vertices; i++)
    {
        no_t *Atual = grafo->VETOR_list_adj[i].prox;
        printf("[%d] -> ", grafo->VETOR_list_adj[i].vertice);        
        while (Atual)
        {            
            no_t *tmp = Atual;
            Atual = Atual->prox;
            printf("[%d] -> ", tmp->vertice);        
        }        
        printf(" NULL \n");
    }
}

// void mostraGrafo(grafo_t *grafo)
// {
//     int i;
//     for (i = 0; i < grafo->num_vertices; i++)
//     {
//         no_t *Atual = grafo->VETOR_list_adj[i].prox;        
//         printf("[%d] -> ", Atual->vertice);
//         while (Atual)
//         {
//             no_t *tmp = Atual;
//             Atual = Atual->prox;
//             printf("[%d] ->  ", tmp->vertice);
//         }        
//         printf(" NULL \n");
//     }
// }

void destroiGRAFO(grafo_t* grafo)
{
    if(grafo)
    {
        if(grafo->VETOR_list_adj)
        {
            int v;
            for(v = 0; v < grafo->num_vertices; v++)
            {
                no_t *Atual = grafo->VETOR_list_adj[v].prox;
                while (Atual)
                {
                    no_t *tmp = Atual;
                    Atual = Atual->prox;
                    free(tmp);
                }
            }
            free(grafo->VETOR_list_adj);            
        }
        free(grafo);
    }
}