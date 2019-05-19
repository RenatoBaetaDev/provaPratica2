#include <stdio.h>
#include <stdlib.h>
// #include <time.h> //include das funcoes de tempo
// #include "matrizADJ.h" //entrada da Matriz de Adjacências
// #include "lista_adj.h" 
// #include "matrizADJ.h" 
#include "listaADJ_MatrizADJ.h"

int main()
{

    //lista de Adjacencia
    grafo_t *dir_grafo = criaGRAFO(5);

    addAresta(dir_grafo, 0 , 1);
    addAresta(dir_grafo, 0 , 4);
    addAresta(dir_grafo, 1 , 2);
    addAresta(dir_grafo, 1 , 3);
    addAresta(dir_grafo, 1 , 4);
    addAresta(dir_grafo, 2 , 3);
    addAresta(dir_grafo, 3 , 4);    

    //printf("\n GRAFO DIRECIONADO - DIGRAFO \n");
    //mostraGrafo(dir_grafo);
    //destroiGRAFO(dir_grafo);

    //matriz de Adjacencia
    tipo_digrafo *digrafo = criaDIGRAFO(5);
    insere_arco_digrafo(digrafo, 0, 1);
    insere_arco_digrafo(digrafo, 0, 4);
    insere_arco_digrafo(digrafo, 1, 2);
    insere_arco_digrafo(digrafo, 1, 3);
    insere_arco_digrafo(digrafo, 1, 4);
    insere_arco_digrafo(digrafo, 2, 3);
    insere_arco_digrafo(digrafo, 3, 4);

    //mostra_digrafo(digrafo);

    // remove_arco_digrafo(digrafo, 0, 4);
    // remove_arco_digrafo(digrafo, 2, 3);

    //mostra_digrafo(digrafo);


    int exerc;

    do{

        printf("\n\n Qual exercício voce quer testar? \n");    
        printf("1 - Matriz -> Lista de Adjacencia \n");
        printf("2 - Lista -> Matriz de Adjacencia \n");
        printf("3 - Ciclico ou Aciclico \n");
        printf("4 - Grafo(lista) Conexo ou não \n");
        printf("5 - Grafo(matriz) Orientado ou não \n");
        printf("6 - BFS e DFS \n");
        printf("7 - DFS e Arestas Classificadas \n");
        printf("8 - Graus de Grafo(Lista) \n");
        printf("9 - Instagram \n");
        printf("0 - SAIR \n");
        fflush(stdin);    
        scanf("%d", &exerc);

        switch (exerc)
        {
            case 1:
            {
                mostra_digrafo(digrafo);
                grafo_t *listaDigrafo = matrizParaLista(digrafo);
                printf("\n\n      |");
                printf("\n      v \n\n");
                mostraGrafo(listaDigrafo);
                break;
            }

            case 2:
            {
                mostraGrafo(dir_grafo);
                tipo_digrafo *matrizDigrafo = listaParaMatriz(dir_grafo);
                printf("\n\n      |");
                printf("\n      v \n\n");               
                mostra_digrafo(matrizDigrafo);                
                break;
            }

            case 3:
            {
                
                break;
            }

            case 0:
            {
                printf("Programa parou de executar com sucesso! \n");
                break;
            }


            default:
            {        
                printf("Esse exercicio nao existe");
            }

        }



    }while( exerc != 0);
    

    return 0;
}

