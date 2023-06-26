# OpenMp-LabParalela23.21

## Naive

O algoritmo Naive, também conhecido como "força bruta", é uma abordagem simples para encontrar números primos. A ideia básica é testar cada número individualmente e verificar se ele é divisível por algum outro número além de 1 e ele mesmo.

Aqui está uma explicação passo a passo do algoritmo Naive para encontrar primos:

1. Escolha um número para começar, geralmente a partir do número 2, pois 2 é o menor número primo.

2. Verifique se o número escolhido é divisível por qualquer número entre 2 e ele mesmo - 1 ou como foi implementado neste repositório, indo até a raiz quadrado do número escolhido +1. Se for divisível por algum número, isso significa que não é primo.

3. Se o número passar no teste de divisibilidade para todos os números entre 2 e ele mesmo - 1, então ele é primo.

4. Continue repetindo o processo para números consecutivos até encontrar todos os primos desejados ou atingir um limite definido.

No entanto, o algoritmo Naive pode ser ineficiente para encontrar primos em um intervalo muito grande, pois exige uma verificação individual para cada número. 

## Bag of Task

"Bag of Tasks" (ou "Saco de Tarefas") é uma abordagem de programação paralela em que um conjunto de tarefas independentes é distribuído entre vários processadores ou threads para serem executadas em paralelo.

Nesse modelo, as tarefas são agrupadas em um "saco" (bag) ou lista, e os processadores ou threads retiram tarefas do saco para executar. Cada tarefa é independente das outras, o que significa que não há dependências entre elas. Portanto, os processadores ou threads podem executar as tarefas em qualquer ordem.

1. Divisão dos intervalos: O primeiro passo seria dividir o conjunto de números que você deseja verificar em vários intervalos. Por exemplo, se você deseja encontrar números primos entre 1 e 1000, pode dividir essa faixa em intervalos menores, como [1-250], [251-500], [501-750] e [751-1000].

2. Criar tarefas: Em seguida, você cria tarefas para cada intervalo. Cada tarefa seria responsável por verificar se os números em seu intervalo são primos. 

3. Distribuir tarefas: As tarefas são distribuídas entre os processadores ou threads disponíveis para serem executadas em paralelo. Cada processador ou thread pega uma tarefa do saco de tarefas e executa a verificação de primalidade para os números em seu intervalo.

4. Coletar resultados: Conforme as tarefas são concluídas, os resultados são coletados e combinados para identificar quais números são primos. Isso pode envolver a criação de uma estrutura de dados compartilhada ou a comunicação entre os processadores/threads para compartilhar os resultados.

Essa abordagem permite distribuir o trabalho de verificação de primalidade entre várias tarefas independentes, aproveitando o poder de processamento paralelo para acelerar o processo de encontrar números primos em um conjunto maior de números.

É importante ressaltar que, dependendo do tamanho dos intervalos e do número de tarefas/processadores disponíveis, pode haver uma sobrecarga de comunicação ou coordenação entre as tarefas. Portanto, é necessário ajustar adequadamente o tamanho dos intervalos e a distribuição das tarefas para obter um desempenho ótimo.
## Uso do repositório
Para o uso deste repositório, basta configurar e rodar o makefile. Para configurar basta setar as seguintes variáveis com os valores desejados:

- TARGET: Nome final do objeto
- SOURCES: Diretório do arquivo .c que se encontra o código desejado
- NUM_RUNS: Número de vezes em que será rodado o objeto

Para rodar o makefile, após configurado com o que deseja, basta rodar o comando **`make run`** em seu terminal, além de printar os resultados na tela, o código gerará um .csv com o nome de um dos algoritmos utilizados para encontrar a soma dos primos contendo:

- A soma final
- O tempo que foi necessário para terminar de rodar
- O número solicitado
- O número de threads utilizadas    

Após rodar, e caso queira compilar com outra configuração no makefile, rode **`make clean`** para apagar os objetos criados da compilação feita anteriormente. Para alterar os valores de **n** e/ou **número de threads** basta alterar a função abaixo no respectivo algortimo:
```
void setData(int* setNumThread, long int* setEntry) {
	*setNumThread = 8;
	*setEntry = 100000;
	return ;
}
```