#include <stdio.h>
#include <stdlib.h>
#include "matrizADJ.h"



tipo_digrafo *criaDIGRAFO(int num_vertices)
{
    tipo_digrafo *G = malloc(sizeof(tipo_digrafo));
    G->numVertices = num_vertices;
    G->matriz_adj = criaMatriz(num_vertices, num_vertices, 0);
    return G;
}

int **criaMatriz(int total_linha, int total_coluna, int valor){
	int linha, coluna;
	int **matriz = (int **) malloc (total_coluna * sizeof(int *));
	for (linha = 0; linha < total_linha; linha++)
		matriz[linha] = (int *) malloc (total_coluna * sizeof(int));

	for (linha = 0; linha < total_linha; linha++)
		for (coluna = 0; coluna < total_coluna; coluna++)
			matriz[linha][coluna] = valor;

	return matriz;
}

void insere_arco_digrafo(tipo_digrafo *digrafo, int origem, int destino){
    if (digrafo->matriz_adj[origem][destino] == 0)
        digrafo->matriz_adj[origem][destino] = 1;
}

void mostra_digrafo(tipo_digrafo *digrafo){
	int origem, destino;
	printf("\nMOSTRA MATRIZ ADJACENCIA DIGRAFO\n");
	printf("   %d %d %d %d %d \n", 0,1,2,3,4 );
    printf("\n");
	for ( origem = 0; origem < digrafo->numVertices; origem++){
		printf("%d ", origem);
		for (destino = 0; destino < digrafo->numVertices; destino++)
			printf(" %d", digrafo->matriz_adj[origem][destino]);
		printf("  \n");
}

}
void remove_arco_digrafo (tipo_digrafo *digrafo, int origem, int destino){
    if (digrafo->matriz_adj[origem][destino] == 1)
        digrafo->matriz_adj[origem][destino] = 0;
}

void insere_arco_grafo(tipo_digrafo *digrafo, int origem, int destino){
	insere_arco_digrafo(digrafo, origem, destino);
	insere_arco_digrafo(digrafo, destino, origem);
}

void remove_arco_grafo(tipo_digrafo *digrafo, int origem, int destino){
    remove_arco_digrafo(digrafo, origem, destino);
    remove_arco_digrafo(digrafo, destino, origem);
}