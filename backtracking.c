#include <stdio.h>
#include <stdlib.h>
#include "getCostMatrix.h"


#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) ) /* troca elemento x com y */


int minCost = 9999999;
int *minPath;


/* Problema do caixeiro viajante (TSP) - Algoritmo Forca Bruta
*
* costMatrix: Matriz com os custos (pesos) das arestas.
* ListOfCities: Lista de cidades. ListOfCities[0...n].
* i: Posicao inicial da permutacao.
* n: Posição final da permutacao.
*/
void TSP_BruteForce(double **costMatrix, int *ListOfCities, int i, int n) 
{ 
	
	int j, temp, sum = 0;
	
	if (i == n) {  /* Fim de uma dada permutacao. Atualiza-se o custo e caminho minimos */
		
		for (j = 0; j < n - 1; j++) 		
											
			sum += (int)costMatrix[ ListOfCities[j] ][ ListOfCities[j + 1] ]; /* calcula-se o custo total do percurso */	
				
		sum += (int)costMatrix[ ListOfCities[j] ][ 0 ];      /* retorno: distancia entre a cidade de partida e a de chegada - ListOfCities[n] */
		
		
//		for ( j = 0; j <  n; j++ )              /* testa todas as permutacoes com a cidade ListOfCities[0] fixa */
//			printf("%d", ListOfCities[j]);
		
//		printf("      "); 
		
		
		if (sum <= minCost) { /* Atualiza-se o custo e caminho minimos, se necessário */
			
			minCost = sum;
			//minPath = ListOfCities;
			
		} 		
					
	} 
	
	else { /* Geram-se todas as permutacoes de ListOfCities[i] para ListOfCities[n] */
		
		for (j = i;  j < n; j++) {
			
			SWAP(ListOfCities[i], ListOfCities[j], temp);
			TSP_BruteForce(costMatrix, ListOfCities, i + 1, n);
			SWAP(ListOfCities[i], ListOfCities[j], temp);
		}				
	}	


}



int main (void) {
	
	double **M;
	int *ListOfCities;
	int i, Ncities;
	
	M = getCostMatrix ( "test_tsp/ulysses16.tsp", &Ncities );	/* Matriz de Custos */
	
	ListOfCities = (int*)malloc(Ncities * sizeof(int));		/* Lista de cidades ListOfCities[0..Ncities-1] */
	
	for ( i = 0; i <  Ncities; i++ )
		ListOfCities[i] = i;
		
	TSP_BruteForce(M, ListOfCities, 1, Ncities);
	 
	printf("Custo Minimo: %d\n", minCost);
		
	return 0;
}



