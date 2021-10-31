#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

void insertionSort (int *vetorI, int vetor);
void selectionsort(int *vetorS, int vetor);
void quicksort(int *vetorQ, int inicio, int final);
void troca(int *arr, int i, int j);
void merge(int *vetorM, int inicio, int meio, int fim);
void mergesort(int *vetorM, int inicio, int fim);
int verificar(int *vetor, int n);

int main(){
    struct timeval begin, end;
    int vetor, i;
    int *vetorM, *vetorI, *vetorQ, *vetorS, *vetorRand;
    srand(time(NULL));
    
   

	printf("Insira o tamanho do vetor: ");
	scanf("%d", &vetor);

    vetorM =  (int *)malloc(vetor * sizeof(int));
    vetorS =  (int *)malloc(vetor * sizeof(int));
    vetorQ =  (int *)malloc(vetor * sizeof(int));
    vetorI =  (int *)malloc(vetor * sizeof(int));
    vetorRand =  (int *)malloc(vetor * sizeof(int));

    printf("\nVetor inicial");
    for (i = 0; i < vetor; i++){
		vetorRand[i] = rand() % 100;
        /*printf(", %d", vetorRand[i]);*/  //tive que comentar porque ficava HORAS printando os vetores. 
	}

    printf(verificar(vetorRand, vetor) ? ". O vetor esta ordenado.\n" : ". O vetor nao esta ordenado.\n");

    for (i = 0; i < vetor; i++){
		vetorM[i] = vetorRand[i];
		vetorS[i] = vetorRand[i];
		vetorQ[i] = vetorRand[i];
		vetorI[i] = vetorRand[i];
	}

    printf("\nInsertion sort:");
    gettimeofday(&begin, 0);
    insertionSort(vetorI, vetor);
    gettimeofday(&end, 0);
    printf("\nTempo de Execucao: %.12f segundos.\n", (end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec) * 1e-6));
    printf(verificar(vetorI, vetor) ? "O vetor esta ordenado.\n" : "O vetor nao esta ordenado.\n");

    printf("\nSelection sort:");
    gettimeofday(&begin, 0);
    selectionsort(vetorS, vetor);
    gettimeofday(&end, 0);
    printf("\nTempo de Execucao: %.12f segundos.\n", (end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec) * 1e-6));
    printf(verificar(vetorI, vetor) ? "O vetor esta ordenado.\n" : "O vetor nao esta ordenado.\n");

    printf("\nQuick sort:");
    gettimeofday(&begin, 0);
    quicksort(vetorQ, 0, vetor - 1);
    gettimeofday(&end, 0);
    printf("\nTempo de Execucao: %.12f segundos.\n", (end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec) * 1e-6));
    printf(verificar(vetorI, vetor) ? "O vetor esta ordenado.\n" : "O vetor nao esta ordenado.\n");

    printf("\nMerge sort:");
    gettimeofday(&begin, 0);
    mergesort(vetorM, 0, vetor - 1);
    gettimeofday(&end, 0);
    printf("\nTempo de Execucao: %.12f segundos.\n", (end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec) * 1e-6));
    printf(verificar(vetorI, vetor) ? "O vetor esta ordenado.\n" : "O vetor nao esta ordenado.\n");

    getchar(); 
    system("PAUSE");
    free(vetorRand);
    free(vetorI);
    free(vetorS);
    free(vetorQ);
    free(vetorM);
}

void insertionSort (int *vetorI, int vetor){
    int i = 0;
    int j = 0;
    int aux = 0;

    for (i = 1; i < vetor; i++){
        aux = vetorI[i];

        for (j = i - 1; (j >= 0) && (aux < vetorI[j]); j --)
        {
            vetorI[j + 1] = vetorI[j];           
        }
        
        vetorI[j + 1] = aux;          
    }            
}

void selectionsort(int *vetorS, int vetor){
    int min, index, aux, i, j;

    for (i = 0; i <= vetor - 1; i++){

        min = vetorS[i];
        index = i;

        for (j = i + 1; j <= vetor - 1; j++){

            if (vetorS[j] < min){
            
                min = vetorS[j];
                index = j;
            }
        }

        if (index != i){

            aux = vetorS[i];
            vetorS[i] = vetorS[index];
            vetorS[index] = aux;
        }
    } 
}

void quicksort(int *vetorQ, int inicio, int final) {

    if (inicio >= final){

        return;
    }
       
    int key = vetorQ[inicio];
    int i = inicio + 1, j = final;

    while (i < j) {
        while (i < j && vetorQ[j] >= key){

            --j;
        }
    
        while (i < j && vetorQ[i] <= key){

            ++i;
        }
           
        if (i < j){

            troca(vetorQ, i, j);
        }
    }

    if (vetorQ[inicio] > vetorQ[i]) {

        troca(vetorQ, inicio, i);
        quicksort(vetorQ, inicio, i - 1);
        quicksort(vetorQ, i + 1, final);
    } else {

        quicksort(vetorQ, inicio + 1, final);
    }

}

void troca(int *arr, int i, int j) {
    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}

void mergesort(int *vetorM, int inicio, int fim){

	int meio;
	if (inicio < fim){

		meio = floor((inicio + fim) / 2);

		mergesort(vetorM, inicio, meio);
		mergesort(vetorM, meio + 1, fim);
		merge(vetorM, inicio, meio, fim);
	}
}

void merge(int *vetorM, int inicio, int meio, int fim){

	int *aux;
    int inicioAux, fimAux, tamanho, i, x, y;
	int fimA = 0;
    int fimB = 0;

	tamanho = fim - inicio + 1;
	inicioAux = inicio;
	fimAux = meio + 1;

	aux = (int *)malloc(tamanho * sizeof(int));

	if(aux != NULL){

		for (i = 0; i < tamanho; i++){

			if (!fimA && !fimB){

				if (vetorM[inicioAux] < vetorM[fimAux]){

                    aux[i] = vetorM[inicioAux++];
                }else{

                    aux[i] = vetorM[fimAux++];
                }
			
				if (inicioAux > meio){
                    fimA = 1;
                }
					
				if (fimAux > fim){
                    fimB = 1;
                }

			}else{

				if (!fimA){

                    aux[i] = vetorM[inicioAux++];
                }
				
				else{

                    aux[i] = vetorM[fimAux++];
                }	
			}
		}

		for (x = 0, y = inicio; x < tamanho; x++, y++){
            vetorM[y] = aux[x];
        }
			
	}

	free(aux);
}

int verificar(int *vetor, int n){
	int i;

	if (n > 1){

        for (i = 1; i < n; i++){

            if (vetor[i - 1] > vetor[i]){

                return 0;
            }
        }
        return 1;	
    }else{
        printf("O vetor é muito pequeno.");
        return 1;
    }
}