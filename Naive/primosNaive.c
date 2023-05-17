#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

int primo (long int n) {
	int i;
	for (i = 3; i < (int)(sqrt(n) + 1); i+=2) {
			if(n % i == 0) return 0;
	}
	return 1;
}

int main(int argc, char *argv[]) {
	double tFinal;
	int total = 1, numThread = 4;
	long int nEntrada;
    double tInicio = omp_get_wtime(); // Pega o tempo em que as threads iniciaram a execução
    omp_set_num_threads(numThread); // Número de threads a ser usada

	//Funcao para a entrada de dados


	//Funcao para validar
	if (argc < 2) {
        	printf("Valor inválido! Entre com um valor do maior inteiro\n");
       	 	return 0;
    	} else {
        	nEntrada = strtol(argv[1], (char **) NULL, 10);
       	}

	// Paralelismo
	#pragma omp parallel for reduction(+:total)
    {

    }
    		
	
	//Funcao para a saida do programa
	tFinal = omp_get_wtime(); // Pego o tempo em que foi finalizado o programa
    printf("Quant. de primos entre 1 e n: %d \n", total);
    printf("Tempo de execucao: %1.7f \n", tFinal - tInicio);	 
	
	return(0);
}