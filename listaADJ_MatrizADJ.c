#include <stdio.h>
#include <stdlib.h>
#include "listaADJ_MatrizADJ.h"

// LISTA DE ADJ

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
        printf("[%d] -> ", i);        
        while (Atual)
        {            
            printf("[%d] -> ", Atual->vertice);        
            Atual = Atual->prox;
        }        
        printf(" NULL \n");
    }
}


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

grafo_t *matrizParaLista(tipo_digrafo *digrafo)
{

    int n =  digrafo->numVertices;
    
    grafo_t *grafo = criaGRAFO(n);

	for (int origem = 0; origem < n; origem++)
		for (int destino = 0; destino < n; destino++)
            if (digrafo->matriz_adj[origem][destino] == 1)
                addAresta(grafo,origem,destino);

    return grafo;
}


// MATRIZ DE ADJ

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

tipo_digrafo *listaParaMatriz(grafo_t* grafo){

    int n = grafo->num_vertices;
    tipo_digrafo *digrafo = criaDIGRAFO(n);

    for (int i = 0; i < n; i++)
    {
        no_t *Atual = grafo->VETOR_list_adj[i].prox;
        while (Atual)
        {            
            insere_arco_digrafo(digrafo,i, Atual->vertice);
            Atual = Atual->prox;
        }        

    }

    return digrafo;
}