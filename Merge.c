#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void combina(int vetor[],int inicio,int meio,int fim){
    int n1,n2;
    int i,j,k;
    n1=meio-inicio+1;
    n2=fim-meio;
    int b[n1],c[n2];

    

    for(i=0;i<n1;i++)
        b[i]=vetor[inicio+i];
    for(j=0;j<n2;j++)
        c[j]=vetor[meio+j+1];
    i=0;
    j=0;
    k=inicio;

    
    while (i<n1 && j<n2){
        if(b[i]<=c[j]){
            vetor[k]=b[i];
            i++;
        }else{
            vetor[k]=c[j];
            j++;
        }
        k++;
    };

    while (i<n1){
        vetor[k]=b[i];
        i++;
        k++;
    };

    while (j<n2){
        vetor[k]=c[j];
        j++;
        k++;
    };
}

void mergeSort(int vetor[], int inicio,int fim){
    if(inicio<fim){
        int meio= (inicio+fim)/2;
        mergeSort(vetor,inicio,meio);
        mergeSort(vetor,meio+1,fim);
        combina(vetor,inicio,meio,fim);
    }
}

int main()
{
    int tam= 200000;
    int vetor[tam];
    // for(int k=0; k<tam; k++){
    //     vetor[k]=rand();
    // }
    // for(int k=0; k<tam; k++){
    //     vetor[k]=k;
    // }
    int x= tam;
    for(int k=0; k<tam; k++){
        x=x-1;
        vetor[k]=x;
    }
    printf("\n");
    clock_t begin = clock();
    mergeSort(vetor,0,tam-1);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo gasto: %f \n\n", time_spent);
    
    return 0;
}
