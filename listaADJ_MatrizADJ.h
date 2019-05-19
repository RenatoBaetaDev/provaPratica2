#include <stdio.h>
#include <stdlib.h>

// LISTA

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

// MATRIZ

typedef struct digrafo {
	int numVertices;
	int **matriz_adj;
}tipo_digrafo;

// FUNCOES DE LISTA

grafo_t *criaGRAFO(int n);
no_t *criaNO(int v);
void addAresta(grafo_t *grafo, int origem, int dest);
void mostraGrafo(grafo_t *grafo);
void destroiGRAFO(grafo_t* grafo);
grafo_t *matrizParaLista(tipo_digrafo *digrafo);

//FUNCOES DE MATRIZ

tipo_digrafo *criaDIGRAFO(int numVertices);
int **criaMatriz(int total_linha, int total_coluna, int valor);
void insere_arco_digrafo(tipo_digrafo *digrafo, int origem, int destino);
void mostra_digrafo(tipo_digrafo *digrafo);
void remove_arco_digrafo (tipo_digrafo *digrafo, int origem, int destino);
void insere_arco_grafo(tipo_digrafo *digrafo, int origem, int destino);
void remove_arco_grafo(tipo_digrafo *digrafo, int origem, int destino);
tipo_digrafo *listaParaMatriz(grafo_t* grafo);