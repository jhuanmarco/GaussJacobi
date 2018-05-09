#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define EPSILON 0.00001;
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

int stop1(double A[], double P[]){
		double var_n = VAR_N;
		double e = EPSILON;

		double aux;
		double maior = P[0];
		maior = fabs(maior);

		for(int i = 1; i < var_n; i++){
			aux = fabs(P[i]);
			if(aux < maior){
				maior = aux;
			}
		}

		if(maior > e) return 0;

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

	int k = 0;

	do{	
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


			//printf(")\n");
			result *= aux;
			P[i] = result;
		}

		stop = stop1(A, P); // MaxP < 3
		//stop = stop2(A, P);	// Max |P - A| < 3
		//stop = stop3(A, P); // Max |P - A|/P < 3
		//stop = stop < 4;

		for(int i = 0; i < var_n; i++){
			A[i] = P[i];
		}

		k++;
		
	} while (stop);


		printf("\nATUAL\n");
		for(int i = 0; i < var_n; i++){
			printf("%lf\n", A[i]);
		}

		printf("\nPROXIMO\n");
		for(int i = 0; i < var_n; i++){
			printf("%lf\n", P[i]);
		}



}