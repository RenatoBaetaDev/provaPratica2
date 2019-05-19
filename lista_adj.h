#include <stdio.h>
#include <stdlib.h>

typedef struct no 
{
    int vertice;
    struct no *prox;
}no_t;

typedef struct grafo
{
    int num_vertices;
    no_t *VETOR_list_adj;
}grafo_t;


grafo_t *criaGRAFO(int n);
no_t *criaNO(int v);
void addAresta(grafo_t *grafo, int origem, int dest);
void mostraGrafo(grafo_t *grafo);
void destroiGRAFO(grafo_t* grafo);
grafo_t *matrizParaLista(tipo_digrafo *digrafo);
