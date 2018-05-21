#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define VAR_N 3; // system var count
	
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

int linhas(double M[][3]){ // <<<< preciso especificar o tamanho
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
				numerador += M[i][j];
			}
		}

		resultado = numerador/denominador;
		final =  resultado < 1;

		if(final == 0) break;
	}

	return final;
}
	
void main(){
	int var_n = VAR_N;
	int verifica;

	double M[3][3] = {
		{5,1,1}, 
		{3,4,1},
		{3,3,6}
	};

	modulo(M);

	verifica = linhas(M);

	if(verifica == 1){
		printf("\n\nA matriz dada converge pelo metodo das LINHAS\n\n\n");
	} else {
		printf("\n\nA matriz dada NÃO converge pelo metodo das LINHAS\n\n\n");
	}


}