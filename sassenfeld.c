#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define VAR_N 3; // system variables count
	
void modulo(double M[][3]){ // <<<< preciso especificar o tamanho
	int var_n = VAR_N;
	for(int i = 0; i < var_n; i++){
		for(int j = 0; j < var_n; j++){
			if(M[i][j] < 0 ){
				M[i][j] *= -1;
			}
		}
	}
}

int sassenfeld(double M[][3], double V[]){ // <<<< preciso especificar o tamanho
	int var_n = VAR_N;
	double denominador;
	double numerador;
	double resultado;
	int final = 0;

	for(int i = 0; i < var_n; i++){
		numerador = 0;
		denominador = 0;
		resultado = 0;

		for(int j = 0; j < var_n; j++){
			if(i == j){
				denominador = M[i][j];
			} else {
				numerador += (M[i][j]*V[j]);
			}
		}

		resultado = numerador/denominador;
		V[i] = resultado;

		final =  resultado < 1;
		if(final == 0) break;
	}

	return final;
}
	
void main(){
	int var_n = VAR_N;
	int verifica;

	double V[3] = {1,1,1};

	double M[3][3] = {
		{5,1,1}, 
		{3,4,1},
		{3,3,6}
	};

	modulo(M);

	for(int i = 0; i < 3; i++){
		printf("\n%lf\n", V[i]);
	}	

	verifica = sassenfeld(M, V);

	for(int i = 0; i < 3; i++){
		printf("\n%lf\n", V[i]);
	}	

	if(verifica == 1){
		printf("\n\nA matriz dada converge pelo metodo das SASSENFELD\n\n\n");
	} else {
		printf("\n\nA matriz dada NÃO converge pelo metodo das SASSENFELD\n\n\n");
	}


}