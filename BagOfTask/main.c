#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define TAMANHO 50000

void setData(int* setNumThread, long int* setEntry) {
	*setNumThread = 8;
	*setEntry = 100000;
	return ;
}

int validateData (int numThread,  long int entryNumber) {
	if(numThread < 1){
		printf("Digite um número valido de threads\n");
		return FALSE;
	}
	if (entryNumber < 2) {
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

void output(int total, double tUsed, long int n, int numThread) {
	printf("Quant. de primos entre 1 e %ld: %d \n",n, total);
    printf("Tempo de execucao: %1.7f \n", tUsed);
	FILE *fpt; 
	fpt = fopen("Bag_Of_Task.csv", "a"); 
    fprintf(fpt,"%ld, %d, %1.7f, %d\n", n,total,tUsed, numThread);
    fclose(fpt);
}

int main() {
	double tFinal;
	int total = 1, numThread = 0, stop = 0;
	long int entryNumber;
	printf("Iniciando o Bag of Task \n");
	
	//Pega o tempo em que as threads iniciaram a execução
    double tStart = omp_get_wtime(); 

	//Funcao para a entrada de dados
	setData(&numThread,&entryNumber);

	//Funcao para validar
	if(validateData(numThread,entryNumber) == FALSE) return 0;
    
	// Número de threads a ser usada
	omp_set_num_threads(numThread); 

	//Paralelismo
	#pragma omp parallel for schedule(dynamic,TAMANHO) reduction(+:total)
		for(int i = 3; i <= entryNumber; i+=2){
			if(primo(i) == 1) total++;
		}
	
	//Tempo final de processamento do programa
    tFinal = omp_get_wtime(); 
	
	//Conta realizada para saber em quanto tempo o programa ficou rodando
	double tUsed = tFinal - tStart; 
	
	//Função de saída 
	output(total,tUsed,entryNumber, numThread);	
	return(0);
}