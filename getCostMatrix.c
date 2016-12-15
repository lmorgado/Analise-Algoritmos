#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include "getCostMatrix.h"

static double** mat_create ( int citiesCount );


double** getCostMatrix ( char* nameFile, int* getCitiesCount ) {
	
	double **costMatrix;
	int Ncities;
		
    int i, j, b;
    double dx, dy, xd, yd, zd;    
    double *CoordX, *CoordY;   
    FILE *p_in;
    	    
	p_in = fopen( nameFile, "r" );    
    
	fscanf( p_in, "%d", &Ncities ); 
		
	costMatrix = mat_create( Ncities );
		
    CoordX = (double*)malloc( Ncities * sizeof(double) );
    CoordY = (double*)malloc( Ncities * sizeof(double) ); 
		
 	while( fscanf( p_in, "%d %lf %lf", &i, &dx, &dy ) != EOF ) { 	
				    
		    CoordX[ i - 1 ] = dx;	  
	        CoordY[ i - 1 ] = dy;	
	}
	
   
	for( i = 0; i < Ncities; i++)
		for( j = 0; j < Ncities; j++ ) {
            
			xd = CoordX[i] - CoordX[j];
            yd = CoordY[i] - CoordY[j];
            zd = sqrt( ( xd * xd ) + ( yd * yd ) ) + 0.5;
           	costMatrix[ i ][ j ] = zd;
	
        } 
    
    fclose( p_in );
    
	free( CoordX );
	free( CoordY );
		
	*getCitiesCount = Ncities;
		
    return costMatrix; 
    
} 


void freeCostMatrix ( int citiesCount, double** A ) {
    
    int i;
    
    for ( i = 0; i < citiesCount; i++ )
        free( A[ i ] );
    
    free( A );
    
}



/* Interna ao modulo getCostMatrix.c */
static double** mat_create ( int citiesCount ) {
    
    int i, j;
    
    double** M = (double**)malloc(citiesCount * sizeof(double*));
    
    for( i = 0; i < citiesCount; i++ )
        M[i] = (double*)malloc(citiesCount * sizeof(double));
    
	for( i = 0; i < citiesCount; i++ )	
		for( j = 0; j < citiesCount; j++ )	
			M[i][j] = 0;
		
    return M;
}
