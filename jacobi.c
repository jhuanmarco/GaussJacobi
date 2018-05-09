#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define EPSILON 0.05;
#define VAR_N 3; // system var count

int stop2(double A[], double P[]){
		double var_n = VAR_N;
		double e = EPSILON;

		double aux;
		double maior = P[0] - A[0];
		maior = fabs(maior);

		for(int i = 1; i < var_n; i++){
			aux = fabs(P[i] - A[i]);
			if(aux > maior){
				maior = aux;
			}
		}

		if(maior < e) return 0;

		return 1;
}

int stop3(double A[], double P[]){
		double var_n = VAR_N;
		double e = EPSILON;

		double aux;
		double maior = (P[0] - A[0])/P[0];
		maior = fabs(maior);

		for(int i = 1; i < var_n; i++){
			aux = fabs(P[i] - A[i])/P[i];
			aux = fabs(aux);
			if(aux > maior){
				maior = aux;
			}
		}

		if(maior < e) return 0;

		return 1;
}

void main(){
	int var_n = VAR_N;
	double aux = 0;
	double result;

	double V[var_n];
	double A[var_n]; // atual
	double P[var_n]; // prox

	double M[3][4] = {
		{10,2,1,7},
		{1,5,1,-8},
		{2,3,10,6}
	};

	
	for(int i = 0; i < var_n; i++){
		V[i] = M[i][i];
		A[i] = M[i][var_n]/V[i];
	}
	

	int k;
	// k = 0;
	k = 1; // pois utiliza uma iteracao para encontrar os x iniciais/ ou se pedir para começar em 0,0,0
	
	int stop = 0;

	do{	

		k++; // logo sempre executa 2 iteracoes


		for(int i = 0; i < var_n; i++){

			result = 1/V[i];			
			aux = 0;

			for (int j = 0; j < var_n; j++){
				if(i == j) {
					aux += M[i][var_n];
					continue;
				}
				aux -= (M[i][j]*A[j]);
			}

			result *= aux;
			P[i] = result;
		}

		/*
		printf("\nANTE\n");
		for(int i = 0; i < var_n; i++){
			printf("%.10lf\n", A[i]);
		}

		printf("\nPROXIMO\n");
		for(int i = 0; i < var_n; i++){
			printf("%.10lf\n", P[i]);
		}

		sleep(1);
		*/

		//stop = stop2(A, P);	// Max |P - A| < 3
		stop = stop3(A, P); // Max |P - A|/P < 3
		//stop = k < 2; // 2 = numero de iteracoes pedido

		for(int i = 0; i < var_n; i++){
			A[i] = P[i];
		}

		

	} while (stop);

	printf("GAUSS JACOBI\nX APROXIMADOS EM %d ITERACOES\n", k);
	for(int i = 0; i < var_n; i++){
		printf("x%d = %.10lf\n", i, P[i]);
	}



}