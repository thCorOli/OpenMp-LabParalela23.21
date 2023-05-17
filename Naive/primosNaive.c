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
	double t_final;
	int total = 1;
	long int n;
    double t_inicio = omp_get_wtime(); // Pega o tempo em que as threads iniciaram a execução
    omp_set_num_threads(4); // Número de threads a ser usada

	//Funcao para a entrada de dados


	//Funcao para validar
	if (argc < 2) {
        	printf("Valor inválido! Entre com um valor do maior inteiro\n");
       	 	return 0;
    	} else {
        	n = strtol(argv[1], (char **) NULL, 10);
       	}

	// Paralelismo
	#pragma omp parallel for reduction(+:total)
    {

    }
    		
	
	//Funcao para a saida do programa
	t_final = omp_get_wtime();
    printf("Quant. de primos entre 1 e n: %d \n", total);
    printf("Tempo de execucao: %1.7f \n", t_final - t_inicio);	 
	
	return(0);
}