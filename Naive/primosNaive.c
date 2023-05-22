#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#define TRUE 1
#define FALSE 0

void setData(int* setNumThread, long int* setEntrada) {
	printf("Digite o número de threads: ");
	scanf("%d",setNumThread);
	printf("Digite o n para saber a soma de seus primos: ");
	scanf("%ld",setEntrada);
	return ;
}

int validateData (int setNumThread,  long int setEntrada) {
	if(setNumThread < 1){
		printf("Digite um número valido de threads\n");
		return FALSE;
	}
	if (setEntrada < 2) {
        	printf("Valor inválido! Entre com um valor acima de 2.\n");
       	 	return FALSE;
	}
	return TRUE;
}

int primo (long int n) {
	int i;
	for (i = 3; i < (int)(sqrt(n) + 1); i+=2) {
			if(n % i == 0) return 0;
	}
	return 1;
}

void output(int total, double tInicio, double tFinal, long int n) {
	printf("Quant. de primos entre 1 e %ld: %d \n",n, total);
    printf("Tempo de execucao: %1.7f \n", tFinal - tInicio);
}

int main() {
	double tFinal;
	int total = 1, numThread = 0;
	long int nEntrada;
    double tInicio = omp_get_wtime(); // Pega o tempo em que as threads iniciaram a execução

	//Funcao para a entrada de dados
	setData(&numThread,&nEntrada);

	//Funcao para validar
	if(validateData(numThread,nEntrada) == FALSE) return 0;
    
	// Número de threads a ser usada
	omp_set_num_threads(numThread); 

	// Paralelismo
	#pragma omp parallel for reduction(+:total)
		for (int i = 3; i <= nEntrada; i += 2) {
         	if(primo(i) == 1) total++;
		}	
    		
	tFinal = omp_get_wtime(); // Pega o tempo em que foi finalizado o programa

	//Funcao para a saida do programa
    output(total,tInicio,tFinal,nEntrada);	 
	
	return 0;
}