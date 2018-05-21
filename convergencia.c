#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

#define VAR_N 3; // system variables count

// CHANGE
	
void modulo(double M[][3]){ // <<<< preciso especificar o tamanho CHANGE
	int var_n = VAR_N;
	for(int i = 0; i < var_n; i++){
		for(int j = 0; j < var_n; j++){
			if(M[i][j] < 0 ){
				M[i][j] *= -1;
			}
		}
	}
}
 
int linhas(double M[][3]){ // <<<< MUDAR AQUI preciso especificar o tamanho CHANGE
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

int colunas(double M[][3]){ // <<<< MUDAR AQUI preciso especificar o tamanho CHANGE
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
				denominador = M[j][i];
			} else {
				numerador += M[j][i];
			}
		}

		resultado = numerador/denominador;
		final =  resultado < 1;

		if(final == 0) break;
	}

	return final;
}

int sassenfeld(double M[][3], double V[]){ // <<<< MUDAR AQUI preciso especificar o tamanho CHANGE
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
	int opcao;
	char metodo[15];

	double V[3] = {1,1,1}; // <<<< MUDAR AQUI preciso especificar o tamanho CHANGE

	double M[3][3] = { // <<<< MUDAR AQUI preciso especificar o tamanho CHANGE
		{1,0,-1},
		{-0.5,1,-0.25},
		{1,-0.5,1}
	};

	modulo(M);

	printf("CONVERGENCIA DE METODOS\n1- LINHAS\n2- COLUNAS\n3- SASSENFELD\n");
	scanf(" %d", &opcao);

	switch(opcao){
		case 1:
			verifica = linhas(M);
			strcpy(metodo, "LINHAS");
		break;
		case 2:
			verifica = colunas(M);
			strcpy(metodo, "COLUNAS");
		break; 
		case 3:
			verifica = sassenfeld(M,V);
			strcpy(metodo, "SASSENFELD");
		break;
		default:
			printf("Nenhum metodo escolhido");
			return;
		break;
	}

	if(verifica == 1){
		printf("\n------------\nA matriz dada\nCONVERGE pelo metodo de \n%s\n------------\n\n", metodo);
	} else {
		printf("\n------------\nA matriz dada\nNAO CONVERGE pelo metodo de \n%s\n------------\n\n", metodo);
	}


}