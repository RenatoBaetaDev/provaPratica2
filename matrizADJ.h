#include <stdio.h>
#include <stdlib.h>

typedef struct digrafo {
	int numVertices;
	int **matriz_adj;
}tipo_digrafo;

tipo_digrafo *criaDIGRAFO(int numVertices);
int **criaMatriz(int total_linha, int total_coluna, int valor);
void insere_arco_digrafo(tipo_digrafo *digrafo, int origem, int destino);
void mostra_digrafo(tipo_digrafo *digrafo);
void remove_arco_digrafo (tipo_digrafo *digrafo, int origem, int destino);
void insere_arco_grafo(tipo_digrafo *digrafo, int origem, int destino);
void remove_arco_grafo(tipo_digrafo *digrafo, int origem, int destino);