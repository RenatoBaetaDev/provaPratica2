#include <stdio.h>
#include <stdlib.h>
#include "listaADJ_MatrizADJ.h"

int tempo;

Fila* criaFila(void){
	Fila *f = (Fila*) malloc (sizeof(Fila));
	f->ini = f->fim = NULL;
	return f;
}

Fila* insere(Fila* f, int v){
	No* novo = (No*) malloc (sizeof(No));
	novo->info = v;
	novo->prox = NULL;
	if(f->fim != NULL)
		f->fim->prox = novo;
	f->fim = novo;
	if (f->ini==NULL)
		f->ini = f->fim;
	return f;
}

int retira(Fila* f){
	int v;
	if (vaziaFila(f))
	{
		printf("Fila Vazia.\n");
		exit(1);
	}
	v = f->ini->info;
	No* p = f->ini->prox;
	free(f->ini);
	f->ini = p;
	if (f->ini == NULL)
		f->fim = NULL;
	return v;
}

int vaziaFila(Fila* f){
	return (f->ini==NULL);
}

void liberaFila(Fila *f){
	No* q = f->ini;
	while(q!=NULL)
	{
		No *t = q->prox;
		free(q);
		q = t;
	}

	free(f);
}

void imprimeFila(Fila *f){
	printf("Imprimindo Fila!\n");
	No *q;
	for (q = f->ini; q!= NULL; q= q->prox)
		printf("%d\n", q->info);
}

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

void mostraQtdeDeCiclos(grafo_t *grafo)
{
    int i;
    int ciclos = 0;
    for (i = 0; i < grafo->num_vertices; i++)
    {
        no_t *Atual = grafo->VETOR_list_adj[i].prox;
        while (Atual)
        {            
            if (Atual->vertice == i)   
                ciclos += 1;         
            Atual = Atual->prox;
        }        
    }    
    if (ciclos == 0)
        printf("\n GRAFO ACICLICO ");
    else    
        printf("\n GRAFO CICLICO \n Quantidade de Ciclos = %d", ciclos);
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

tipo_digrafo *listaParaMatriz(grafo_t* grafo)
{
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

int ehOrientado(tipo_digrafo *digrafo)
{
	int origem, destino;
    int orientado = 0;
	for ( origem = 0; origem < digrafo->numVertices; origem++){
		for (destino = origem+1; destino < digrafo->numVertices; destino++)
            if (digrafo->matriz_adj[origem][destino] != digrafo->matriz_adj[destino][origem])
                orientado = 1;
    }    
    return orientado;
}

//RECEBE UMA LISTA DE ADJACENCIAS
int **BFS(grafo_t *grafo, int s)
{    
    int qtdeDeNos = grafo->num_vertices;
    int linhas = 4;
    int no = 0;
    int corNo = 1;
    int distNo = 2;
    int paiNo = 3;
    int **matriz  = criaMatriz(linhas, qtdeDeNos, 0);
    int i = 0;

    int preto = 0;
    int branco = 1;
    int cinza = 2;
    int infinito = -1;
    int valor;
    int nulo = 99999;
    

    for (int z = 0; z < qtdeDeNos; z++)
    {          
        matriz[no][z] = z;                
    }

    for (i = 1; i < linhas; i++){
        if (i == corNo)
            valor = branco;
        else if (i == distNo)
            valor = infinito;
        else 
            valor = nulo;

        for (int z = 0; z < qtdeDeNos; z++)
        {    
            if (z==s)  
                continue;    
            matriz[i][z] = valor;
        }           
    }

    matriz[corNo][s] = cinza;
    matriz[distNo][s] = 0;
    matriz[paiNo][s] = nulo;

    Fila *Q = criaFila();
    Q = insere(Q,s);


    while( !vaziaFila(Q) )
    {
        int noAtual = retira(Q);

        no_t *Atual = grafo->VETOR_list_adj[noAtual].prox;    

        while (Atual)
        {            
            int v = Atual->vertice;
            if (matriz[corNo][v] == branco)
            {
                matriz[corNo][v] = cinza;            
                matriz[distNo][v] = matriz[distNo][noAtual] + 1;
                matriz[paiNo][v] = noAtual;
                insere(Q, v);
            }
            Atual = Atual->prox;
        } 

        matriz[corNo][noAtual] = preto;
    }


    return matriz;
}


void imprimeBFS(int **matriz, int qtdeDeNos)
{
    int linhas = 4;
    int no = 0;
    int corNo = 1;
    int distNo = 2;
    int paiNo = 3;

    int preto = 0;
    int branco = 1;
    int cinza = 2;
    int infinito = -1;
    int valor;
    int nulo = 99999;

    printf(" -------- BFS -------- \n");


	for (int linha = 0; linha < linhas; linha++){
        if (linha == corNo)
            printf("Cor   ");
        else if (linha == distNo)
            printf("Dist  ");
        else if (linha == paiNo) 
            printf("Pai   ");
        else 
            printf("No    ");

		for (int no = 1; no < qtdeDeNos; no++)
        {
            if (matriz[linha][no] == 99999)
                printf("| %s |", "NIL");
            else if(matriz[linha][no] == -1)
                printf("| %d  |", matriz[linha][no]);            
            else 
                printf("|  %d  |", matriz[linha][no]);            
        }		    
		printf("  \n");    
    }
}


// void dfs_visit(int no, int **matriz)
void dfs_visit(int no, grafo_t *grafo, int **matriz)
{

    int corNo = 1;
    int paiNo = 2;
    int tempInic = 3;
    int tempoFim = 4;  
    int preto = 0;
    int branco = 1;
    int cinza = 2;      


    matriz[corNo][no] = cinza;
    tempo += 1;
    matriz[tempInic][no] = tempo;

    no_t *Atual = grafo->VETOR_list_adj[no].prox;
    while (Atual)
    {            
        if (matriz[corNo][Atual->vertice] == branco)
        {
            matriz[paiNo][Atual->vertice] = no;        
            dfs_visit(Atual->vertice, grafo, matriz);
        }
        Atual = Atual->prox;
    }     

    matriz[corNo][no] = preto;
    tempo += 1;
    matriz[tempoFim][no] = tempo;
}

int **DFS(grafo_t *grafo)
{
    int qtdeDeNos = grafo->num_vertices;
    int linhas = 5;
    int no = 0;
    int corNo = 1;
    int paiNo = 2;
    int tempInic = 3;
    int tempoFim = 4;
    int **matriz  = criaMatriz(linhas, qtdeDeNos, 0);
    int i = 0;

    int preto = 0;
    int branco = 1;
    int cinza = 2;
    int infinito = -1;
    int valor;
    int nulo = 99999;
    
    for (no = 1; no < grafo->num_vertices; no++)
    {
        matriz[0][no] = no;
        matriz[corNo][no] = branco;
        matriz[paiNo][no] = nulo;
    }

    tempo = 0;

    for (no = 1; no < grafo->num_vertices; no++)
        if (matriz[corNo][no] == branco)
            dfs_visit(no, grafo, matriz);         

    printf("\n \n -------- DFS -------- \n");


	for (int linha = 0; linha < linhas; linha++){
        if (linha == corNo)
            printf("Cor   ");
        else if (linha == tempInic)
            printf("T. I. ");
        else if (linha == tempoFim)
            printf("T. F. ");            
        else if (linha == paiNo) 
            printf("Pai   ");
        else 
            printf("No    ");

		for (int no = 1; no < qtdeDeNos; no++)
        {
            if (matriz[linha][no] == 99999)
                printf("| %s |", "NIL");
            else if(matriz[linha][no] > 9)
                printf("| %d  |", matriz[linha][no]);            
            else 
                printf("|  %d  |", matriz[linha][no]);            
        }		    
		printf("  \n");    
    }

    return matriz;    
}