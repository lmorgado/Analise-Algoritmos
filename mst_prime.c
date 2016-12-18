#include <stdio.h>
#include "queue.h"
#include "getCostMatrix.h"

#define INF 9999


void MST_PRIM (double** graph, int *PI, int n)
{	
	
	int key[n];
    Queue* queue;    // Fila
    int u;          // vertice explorado
    int v;         // vizinhos de u
    int i;

    
    for(i = 0; i < n; i++) {
     
	   key[i] = INF; //Inicializando as chaves + predecessores 
       PI[i] = -1;	 //Inicializando os predecessores
 
    }
    
	key[0] = 0; //raiz    
    
	
    queue = queue_create ();   // Criando a fila 
	for (i = 0; i < n; i++)
        queue_insert (queue, i, key[i]); /* i (numero do vertice) é o dado; 
									      * key[i] is a chave do vértice (menor peso dentre todas as arestas conectadas a ele) */	
 
 
    while(!queue_empty(queue)) {
				
		u = queue_retrieve_minimum (queue);  // Extraindo o vértice u mínimo da Fila     
    
		for(v = 0; v < n; v++)     // Vizinhos de do vertice u     
			if(queue_hasVertex(queue, v) && graph[u][v] < key[v]) {
				PI[v] = u;
         		key[v] = graph[u][v];								
       		}   	
	}
 	       
}        






/*
int main(void) {
	
	int Ncities;
	int* PI;
	int i;	
	
	double** test = getCostMatrix ( "test_tsp/ulysses16.tsp", &Ncities );
	
	MST_PRIM (test, PI, Ncities);
	
	
	for(i = 1; i < Ncities; i++)
		printf("\nPai: %d da cidade: %d", PI[i], i);
	
	
	return 0;
} */