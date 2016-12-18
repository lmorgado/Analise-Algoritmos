#include "mst_prime.h"
#include "getCostMatrix.h"

static int isElementInHamiltonCycle (int* H, int n, int element);


void APPROX_TSP_TOUR (double **graph, int* H, int n) {
	
	int* L; //Lista de vértices visitados em pre-ordem	
	int i;	
				
	MST_PRIM (graph, L, n); // Obtendo L
	
    for(i = 0; i < n; i++) // Inicializando o ciclo hamiltoniano 	  
    	H[i] = -1;	          
 	
	for(i = 0; i < n - 1; i++) {
				
		if (!isElementInHamiltonCycle (H, n, L[i])) // Verifico primeiro se o pai já está no ciclo
			H[i] = L[i];
		
		if (!isElementInHamiltonCycle (H, n, i)) // Por fim, verifico o filho
			H[i] = i;				
	}
	
	H[n] = H[0]; // O ciclo retorna para o início
			
}


static int isElementInHamiltonCycle (int* H, int n, int element) {
	
	int i;
	
	for(i = 0; i < n; i++) {
		
		if (H[i] == -1) // fora do ciclo
			break;
		
		if (H[i] == element)
			return 1;	
	}
	
	return 0;	
}



int main (void) {
	
	int Ncities;
	int* H;
	int i;	
	
	double** test = getCostMatrix ( "test_tsp/ulysses16.tsp", &Ncities );
	
	//APPROX_TSP_TOUR (test, H, Ncities);
	
		
	return 0;
}