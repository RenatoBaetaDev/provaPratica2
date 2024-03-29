#include <stdio.h>
#include <stdlib.h>


typedef struct noI{
	int vertice;
	int idade;
	char *nome;
	struct noI *prox;
}noI;

typedef struct grafoI
{
    int num_vertices;
    noI *VETOR_list_adj;
}grafoI;

// FILA

//estruta que define os valores do Nos da fila
typedef struct noFila
{
	int info;
	struct noFila* prox;
}No;

//estrutura fila que armazena o primeiro e o ultimo valor inseridos na fila
typedef struct fila{
	No* ini;
	No* fim;
}Fila;

Fila* criaFila(void);
Fila* insere(Fila* f, int v);
int retira(Fila* f);
int vaziaFila(Fila* f);
void liberaFila(Fila *f);
void imprimeFila(Fila *f);

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
void mostraQtdeDeCiclos(grafo_t *grafo);
void qtdeGrausPorNo(grafo_t *grafo);

//FUNCOES DE MATRIZ

tipo_digrafo *criaDIGRAFO(int numVertices);
int **criaMatriz(int total_linha, int total_coluna, int valor);
void insere_arco_digrafo(tipo_digrafo *digrafo, int origem, int destino);
void mostra_digrafo(tipo_digrafo *digrafo);
void remove_arco_digrafo (tipo_digrafo *digrafo, int origem, int destino);
void insere_arco_grafo(tipo_digrafo *digrafo, int origem, int destino);
void remove_arco_grafo(tipo_digrafo *digrafo, int origem, int destino);
tipo_digrafo *listaParaMatriz(grafo_t* grafo);
int ehOrientado(tipo_digrafo *digrafo);


int **BFS(grafo_t *grafo, int n);
void imprimeBFS(int **matriz, int qtdeDeNos);

void dfs_visit(int no, grafo_t *grafo, int **matriz);
int **DFS(grafo_t *grafo);

grafoI * criaGRAFOInsta(int n);
noI *criaNOInsta(int v);
void addArestaInsta(grafoI *grafo, int origem, int dest);
void addUsuario(grafoI *grafo, int no, int idade, char* nome);
void pessoaMaisPopular(grafoI *grafo);
void qtdeSeguidores(grafoI *grafo, char *nome);
void pessoasQueSeguemMaisVelhos(grafoI *grafo);